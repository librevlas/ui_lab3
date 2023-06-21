#ifndef UI_LAB3_QUESTIONSWIDGET_H
#define UI_LAB3_QUESTIONSWIDGET_H

#include "AnswerPageWidget.h"
#include "Client.h"
#include "PostAnswerWidget.h"
#include "PostQuestionWidget.h"
#include "QuestionListWidget.h"
#include <QStackedWidget>
#include <QWidget>

class QuestionsWidget : public QWidget {
Q_OBJECT
public:
  explicit QuestionsWidget(Client *client, QWidget *parent);

  void showQuestionList();

private:
  void openQuestion(Question question);
  void answerQuestion(Question question);
  void postAnswer(Question question, QString answerText);
  void showAnswerPage(Question question);
  void updateQuestionsListWidget();
  bool updateQuestion(Question &question);
  void newQuestion();
  void postQuestion(QString questionText);

  QStackedWidget *stackedWidget;
  QuestionListWidget *questionListWidget;
  AnswerPageWidget *answerPageWidget;
  PostAnswerWidget *postAnswerWidget;
  PostQuestionWidget *postQuestionWidget;
  Client *mClient = nullptr;
};


#endif // UI_LAB3_QUESTIONSWIDGET_H
