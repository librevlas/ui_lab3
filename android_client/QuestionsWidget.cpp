#include "QuestionsWidget.h"
#include "Client.h"

QuestionsWidget::QuestionsWidget(Client *client, QWidget *parent)
    : QWidget(parent), mClient(client) {
    stackedWidget = new QStackedWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);

    questionListWidget = new QuestionListWidget;
    answerPageWidget = nullptr; // We will create this when a mQuestion is opened
    postAnswerWidget = nullptr; // We will create this when the Answer button is clicked
    postQuestionWidget = nullptr;

    stackedWidget->addWidget(questionListWidget);

    connect(questionListWidget, &QuestionListWidget::openClicked, this, &QuestionsWidget::openQuestion);
    connect(questionListWidget, &QuestionListWidget::refreshClicked, this, &QuestionsWidget::updateQuestionsListWidget);
    connect(questionListWidget, &QuestionListWidget::newQuestionClicked, this, &QuestionsWidget::newQuestion);
}

void QuestionsWidget::updateQuestionsListWidget() {
  auto currentQuestions = mClient->getQuestions();
  questionListWidget->updateQuestions(currentQuestions);
}

void QuestionsWidget::openQuestion(Question question) {
  delete answerPageWidget;

  answerPageWidget = new AnswerPageWidget(question);
  stackedWidget->addWidget(answerPageWidget);
  stackedWidget->setCurrentWidget(answerPageWidget);

  connect(answerPageWidget, &AnswerPageWidget::answerClicked, this, &QuestionsWidget::answerQuestion);
  connect(answerPageWidget, &AnswerPageWidget::backClicked, this, &QuestionsWidget::showQuestionList);
}

void QuestionsWidget::answerQuestion(Question question) {
  delete postAnswerWidget;

  postAnswerWidget = new PostAnswerWidget(question);
  stackedWidget->addWidget(postAnswerWidget);
  stackedWidget->setCurrentWidget(postAnswerWidget);

  connect(postAnswerWidget, &PostAnswerWidget::answerClicked, this, &QuestionsWidget::postAnswer);
  connect(postAnswerWidget, &PostAnswerWidget::backClicked, this, &QuestionsWidget::showAnswerPage);
}

void QuestionsWidget::postAnswer(Question question, QString answerText) {
  mClient->addAnswer(question.getId(), mClient->getLastUser().getLogin(), answerText);

  showAnswerPage(question);
}

void QuestionsWidget::showAnswerPage(Question question) {
  if (updateQuestion(question)) {
    openQuestion(question);
  } else {
    showQuestionList();
  }
}

bool QuestionsWidget::updateQuestion(Question &question) {
  auto questionsFromServer = mClient->getQuestions();
  for (auto &item : questionsFromServer) {
    if (item.getId() == question.getId()) {
      question = item;
      return true;
    }
  }
  return false;
}

void QuestionsWidget::showQuestionList() {
  updateQuestionsListWidget();
  stackedWidget->setCurrentWidget(questionListWidget);
}

void QuestionsWidget::newQuestion() {
  delete postQuestionWidget;

  postQuestionWidget = new PostQuestionWidget();
  stackedWidget->addWidget(postQuestionWidget);
  stackedWidget->setCurrentWidget(postQuestionWidget);

  connect(postQuestionWidget, &PostQuestionWidget::postClicked, this, &QuestionsWidget::postQuestion);
  connect(postQuestionWidget, &PostQuestionWidget::backClicked, this, &QuestionsWidget::showQuestionList);
}

void QuestionsWidget::postQuestion(QString questionText) {
  Question question;
  question.setQuestionText(questionText);
  question.setCurrentCreatedDate();
  question.setAuthorLogin(mClient->getLastUser().getLogin());
  mClient->addQuestion(question);
  showQuestionList();
}
