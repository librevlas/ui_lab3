#include "AnswerWidget.h"

AnswerWidget::AnswerWidget(Answer answer, QWidget *parent)
    : QWidget(parent), answer(answer) {
  QHBoxLayout *layout = new QHBoxLayout(this);

  QLabel *answerLabel = new QLabel(this);
  answerLabel->setText(answer.getAnswerText());
  layout->addWidget(answerLabel);

  QLabel *authorLabel = new QLabel(this);
  authorLabel->setText(answer.getAnswerers().join(", "));
  layout->addWidget(authorLabel);
}
