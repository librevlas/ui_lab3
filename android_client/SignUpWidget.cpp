#include "SignUpWidget.h"

SignUpWidget::SignUpWidget(QWidget *parent)
    : QWidget(parent), mLoginLabel(new QLabel("Login", this)),
      mPasswordLabel(new QLabel("Password", this)),
      mBirthDateLabel(new QLabel("Date of birth", this)),
      mLoginEdit(new QLineEdit(this)), mPasswordEdit(new QLineEdit(this)),
      mBirthDateEdit(new QLineEdit(this)),
      mProceedButton(new QPushButton("Proceed", this)),
mBackButton(new QPushButton("Back to Sign In", this)){
  mPasswordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);

  QFormLayout *layout = new QFormLayout(this);
  layout->addRow(mLoginLabel, mLoginEdit);
  layout->addRow(mPasswordLabel, mPasswordEdit);
  layout->addRow(mBirthDateLabel, mBirthDateEdit);
  layout->addWidget(mProceedButton);
  layout->addWidget(mBackButton);

  connect(mProceedButton, &QPushButton::clicked, this, [this]() {
    User newUser;
    newUser.setLogin(mLoginEdit->text());
    newUser.setPassword(mPasswordEdit->text());
    newUser.setBirthdate(mBirthDateEdit->text());
    emit proceed(newUser);
  });

  connect(mBackButton, &QPushButton::clicked, this, &SignUpWidget::backToSignIn);
}
