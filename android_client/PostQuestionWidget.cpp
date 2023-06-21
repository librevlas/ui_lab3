#include "PostQuestionWidget.h"

PostQuestionWidget::PostQuestionWidget(QWidget *parent)
    : QWidget(parent) {
  auto mainLayout = new QVBoxLayout(this);
  auto layout = new QVBoxLayout();
  mainLayout->addLayout(layout);

  questionEdit = new QLineEdit(this);
  layout->addWidget(questionEdit);
  layout->addStretch();

  auto buttonLayout = new QHBoxLayout();
  mainLayout->addLayout(buttonLayout);

  QPushButton *backButton = new QPushButton("Back", this);
  buttonLayout->addWidget(backButton);

  QPushButton *postButton = new QPushButton("Post Question", this);
  buttonLayout->addWidget(postButton);

  connect(postButton, &QPushButton::clicked, this, [this](){
    qDebug() << questionEdit->text();
    emit postClicked(questionEdit->text());
  });
  connect(backButton, &QPushButton::clicked, this, [this] () {
    emit backClicked();
  });
}
