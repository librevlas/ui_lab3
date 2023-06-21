#include "QuestionWidget.h"

QuestionWidget::QuestionWidget(Question question, QWidget *parent)
    : QWidget(parent) {
  mQuestion = question;
  QHBoxLayout *layout = new QHBoxLayout(this);

  QLabel *questionLabel = new QLabel(this);
  questionLabel->setText(mQuestion.getQuestionText());
  qDebug() << mQuestion.getQuestionText();

  layout->addWidget(questionLabel);

  QLabel *authorLabel = new QLabel(this);
  authorLabel->setText(mQuestion.getAuthorLogin());
  layout->addWidget(authorLabel);

  QPushButton *openButton = new QPushButton("Open", this);
  layout->addWidget(openButton);

  connect(openButton, &QPushButton::clicked, this,
          [this]() { emit openClicked(mQuestion); });
}
