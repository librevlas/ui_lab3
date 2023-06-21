#ifndef UI_LAB3_QUESTIONWIDGET_H
#define UI_LAB3_QUESTIONWIDGET_H

#include "ClientApi.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QWidget>

class QuestionWidget : public QWidget {
  Q_OBJECT
public:
  explicit QuestionWidget(Question question, QWidget *parent = nullptr);

signals:
  void openClicked(Question question);

private:
  Question mQuestion;
};

#endif // UI_LAB3_QUESTIONWIDGET_H
