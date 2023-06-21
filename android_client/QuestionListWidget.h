//
// Created by lesha on 21.06.2023.
//

#ifndef UI_LAB3_QUESTIONLISTWIDGET_H
#define UI_LAB3_QUESTIONLISTWIDGET_H

#include "ClientApi.h"
#include "QuestionWidget.h"
#include <QSignalMapper>
#include <QVBoxLayout>
#include <QWidget>

class QuestionListWidget : public QWidget {
Q_OBJECT
public:
  explicit QuestionListWidget(QWidget *parent = nullptr);

  void updateQuestions(QList<Question> questions);

signals:
  void openClicked(Question question);
  void newQuestionClicked();
  void refreshClicked();

private:
  QVBoxLayout *layout{};
  QPushButton *mNewQuestionButton{};
  QPushButton *mRefreshButton{};
};


#endif // UI_LAB3_QUESTIONLISTWIDGET_H
