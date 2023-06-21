#include "AnswerPageWidget.h"

AnswerPageWidget::AnswerPageWidget(Question question, QWidget *parent)
    : QWidget(parent), mQuestion(question) {
  auto mainLayout = new QVBoxLayout(this);
  auto layout = new QVBoxLayout();
  mainLayout->addLayout(layout);

  QLabel *questionLabel = new QLabel(this);
  questionLabel->setText(mQuestion.getQuestionText());
  layout->addWidget(questionLabel);

  for (Answer answer : mQuestion.getAnswers()) {
    AnswerWidget *answerWidget = new AnswerWidget(answer, this);
    layout->addWidget(answerWidget);
  }
  layout->addStretch();

  auto buttonLayout = new QHBoxLayout();

  QPushButton *backButton = new QPushButton("Back", this);
  buttonLayout->addWidget(backButton);

  QPushButton *answerButton = new QPushButton("Answer", this);
  buttonLayout->addWidget(answerButton);

  mainLayout->addLayout(buttonLayout);

  connect(answerButton, &QPushButton::clicked, this, [this] () {
    emit answerClicked(mQuestion);
  });
  connect(backButton, &QPushButton::clicked, this, &AnswerPageWidget::backClicked);
}
