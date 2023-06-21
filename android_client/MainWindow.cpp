#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  mClient = new Client(this);
  mStack = new QStackedWidget;

  mConnectWidget = new ConnectWidget(mStack);
  mSignInWidget = new SignInWidget(mStack);
  mSignUpWidget = new SignUpWidget(mStack);
  mQuestionsWidget = new QuestionsWidget(mClient, mStack);

  mStack->addWidget(mConnectWidget);
  mStack->addWidget(mSignInWidget);
  mStack->addWidget(mSignUpWidget);
  mStack->addWidget(mQuestionsWidget);

  setCentralWidget(mStack);

  mStack->setCurrentWidget(mConnectWidget);

  connect(mConnectWidget, &ConnectWidget::connectToServer, this, [this](QString url) {
    mClient->setUrl(url);
    mStack->setCurrentWidget(mSignInWidget);
  });

  connect(mSignInWidget, &SignInWidget::changeServer, this, [this]() {
    mStack->setCurrentWidget(mConnectWidget);
  });

  connect(mSignInWidget, &SignInWidget::signUpClicked, this, [this](){
    mStack->setCurrentWidget(mSignUpWidget);
  });

  connect(mSignInWidget, &SignInWidget::signInClicked, this, [this](QString login, QString password){
    bool status = mClient->signIn(login, password);
    mSignInWidget->setWrongPassword(!status);
    if (status) {
      mQuestionsWidget->showQuestionList();
      mStack->setCurrentWidget(mQuestionsWidget);
    }
  });

  connect(mSignUpWidget, &SignUpWidget::proceed, this, [this] (User newUser) {
    mClient->signUp(newUser);
    mQuestionsWidget->showQuestionList();
    mStack->setCurrentWidget(mQuestionsWidget);
  });

  connect(mSignUpWidget, &SignUpWidget::backToSignIn, this, [this] () {
    mStack->setCurrentWidget(mSignInWidget);
  });


}

MainWindow::~MainWindow() {}
