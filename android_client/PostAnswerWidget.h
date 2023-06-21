#ifndef UI_LAB3_POSTANSWERWIDGET_H
#define UI_LAB3_POSTANSWERWIDGET_H

#include "ClientApi.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class PostAnswerWidget : public QWidget {
Q_OBJECT
public:
  explicit PostAnswerWidget(Question question, QWidget *parent = nullptr);

signals:
  void answerClicked(Question question, QString answerText);
  void backClicked(Question question);

private:
  Question mQuestion;
  QLineEdit *answerEdit;
};


#endif // UI_LAB3_POSTANSWERWIDGET_H
