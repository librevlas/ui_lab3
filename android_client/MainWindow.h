#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "Client.h"
#include "ConnectWidget.h"
#include "QuestionsWidget.h"
#include "SignInWidget.h"
#include "SignUpWidget.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  SignInWidget *mSignInWidget;
  ConnectWidget *mConnectWidget;
  SignUpWidget *mSignUpWidget;
  QuestionsWidget *mQuestionsWidget;

  Client *mClient;
  QStackedWidget *mStack;

};
#endif // MAINWINDOW_H
