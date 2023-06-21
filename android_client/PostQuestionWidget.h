#ifndef UI_LAB3_POSTQUESTIONWIDGET_H
#define UI_LAB3_POSTQUESTIONWIDGET_H

#include "ClientApi.h"
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>

class PostQuestionWidget : public QWidget {
Q_OBJECT
public:
  explicit PostQuestionWidget(QWidget *parent = nullptr);

signals:
  void postClicked(QString questionText);
  void backClicked();

private:
  QLineEdit *questionEdit;
};


#endif // UI_LAB3_POSTQUESTIONWIDGET_H
