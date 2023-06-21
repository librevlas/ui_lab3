#ifndef UI_LAB3_ANSWERWIDGET_H
#define UI_LAB3_ANSWERWIDGET_H

#include "ClientApi.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QWidget>

class AnswerWidget : public QWidget {
public:
  explicit AnswerWidget(Answer answer, QWidget *parent = nullptr);

private:
  Answer answer;
};


#endif // UI_LAB3_ANSWERWIDGET_H
