//
// Created by lesha on 21.06.2023.
//

#include "QuestionListWidget.h"

QuestionListWidget::QuestionListWidget(QWidget *parent) : QWidget(parent) {
  auto mainLayout = new QVBoxLayout(this);
  layout = new QVBoxLayout();
  mainLayout->addLayout(layout);
  mNewQuestionButton = new QPushButton("New Question");
  mRefreshButton = new QPushButton("Refresh");

  auto buttonLayout = new QHBoxLayout();
  mainLayout->addLayout(buttonLayout);
  buttonLayout->addWidget(mRefreshButton);
  buttonLayout->addWidget(mNewQuestionButton);

  connect(mRefreshButton, &QPushButton::clicked, this, &QuestionListWidget::refreshClicked);
  connect(mNewQuestionButton, &QPushButton::clicked, this, &QuestionListWidget::newQuestionClicked);
}

void QuestionListWidget::updateQuestions(QList<Question> questions) {
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != 0) {
        delete child->widget();
        delete child;
    }

    for (Question question : questions) {
        QuestionWidget *questionWidget = new QuestionWidget(question, this);
        layout->addWidget(questionWidget);
        connect(questionWidget, &QuestionWidget::openClicked, this, &QuestionListWidget::openClicked);
    }
    layout->addStretch();
}
