#ifndef UI_LAB3_SIGNUPWIDGET_H
#define UI_LAB3_SIGNUPWIDGET_H

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

#include "ClientApi.h"

class SignUpWidget : public QWidget {
  Q_OBJECT

public:
  explicit SignUpWidget(QWidget *parent = nullptr);

signals:
  void proceed(User);
  void backToSignIn();

private:
  QLabel *mLoginLabel;
  QLabel *mPasswordLabel;
  QLabel *mBirthDateLabel;
  QLineEdit *mLoginEdit;
  QLineEdit *mPasswordEdit;
  QLineEdit *mBirthDateEdit;
  QPushButton *mProceedButton;
  QPushButton *mBackButton;
};

#endif // UI_LAB3_SIGNUPWIDGET_H
