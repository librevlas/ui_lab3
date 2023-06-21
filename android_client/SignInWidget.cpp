#include "SignInWidget.h"

SignInWidget::SignInWidget(QWidget *parent)
    : QWidget(parent), mLoginLabel(new QLabel("Login", this)),
      mPasswordLabel(new QLabel("Password", this)),
      mLoginEdit(new QLineEdit(this)), mPasswordEdit(new QLineEdit(this)),
      mSignInButton(new QPushButton("Sign In", this)),
      mSignUpButton(new QPushButton("Sign Up", this)),
      mChangeServerButton(new QPushButton("Change Server", this)), mStatusLabel(new QLabel("",this)) {
  mPasswordEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
  mStatusLabel->setStyleSheet(R"(
/* QLabel */
QLabel {
    color: #ff8000;
    font: 18px; /* Sets the font size to 18 pixels */
    background-color: #eeeeee;
}
)");

  auto mainLayout = new QVBoxLayout(this);
  QFormLayout *layout = new QFormLayout();
  mainLayout->addLayout(layout);


  auto buttonLayout = new QHBoxLayout();
  mainLayout->addLayout(buttonLayout);

  layout->addRow(mLoginLabel, mLoginEdit);
  layout->addRow(mPasswordLabel, mPasswordEdit);
  layout->addWidget(mStatusLabel);
  layout->addWidget(mSignInButton);
  buttonLayout->addWidget(mSignUpButton);
  buttonLayout->addWidget(mChangeServerButton);

  connect(mSignInButton, &QPushButton::clicked, this,
          &SignInWidget::onSignInClicked);
  connect(mSignUpButton, &QPushButton::clicked, this,
          &SignInWidget::signUpClicked);
  connect(mChangeServerButton, &QPushButton::clicked, this,
          &SignInWidget::changeServer);
}

void SignInWidget::onSignInClicked() { emit signInClicked(mLoginEdit->text(), mPasswordEdit->text()); }

void SignInWidget::setWrongPassword(bool wrongPassword) {
  mStatusLabel->setText((wrongPassword?"Wrong Password":""));
}
