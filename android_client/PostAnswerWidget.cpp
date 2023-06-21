#include "PostAnswerWidget.h"

PostAnswerWidget::PostAnswerWidget(Question question, QWidget *parent)
    : QWidget(parent), mQuestion(question) {
  auto mainLayout = new QVBoxLayout(this);
  auto layout = new QVBoxLayout();
  mainLayout->addLayout(layout);

  answerEdit = new QLineEdit(this);
  layout->addWidget(answerEdit);
  answerEdit->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

  auto buttonLayout = new QHBoxLayout();
  mainLayout->addLayout(buttonLayout);
  mainLayout->addStretch();
  QPushButton *backButton = new QPushButton("Back", this);
  buttonLayout->addWidget(backButton);

  QPushButton *answerButton = new QPushButton("Answer", this);
  buttonLayout->addWidget(answerButton);

  connect(answerButton, &QPushButton::clicked, this, [this](){
    emit answerClicked(mQuestion, answerEdit->text());
  });
  connect(backButton, &QPushButton::clicked, this, [this] () {
    emit backClicked(mQuestion);
  });
}
