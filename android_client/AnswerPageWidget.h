#ifndef UI_LAB3_ANSWERPAGEWIDGET_H
#define UI_LAB3_ANSWERPAGEWIDGET_H

#include "AnswerWidget.h"
#include "ClientApi.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class AnswerPageWidget : public QWidget {
Q_OBJECT
public:
  explicit AnswerPageWidget(Question question, QWidget *parent = nullptr);

signals:
  void answerClicked(Question question);
  void backClicked();

private:
  Question mQuestion;
};


#endif // UI_LAB3_ANSWERPAGEWIDGET_H
