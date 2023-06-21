#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H


#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFormLayout>

class SignInWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SignInWidget(QWidget *parent = nullptr);

    void setWrongPassword(bool wrongPassword);

signals:
    void signInClicked(QString login, QString password);
    void signUpClicked();
    void changeServer();

private slots:
    void onSignInClicked();

private:
    QLabel *mLoginLabel;
    QLabel *mPasswordLabel;
    QLineEdit *mLoginEdit;
    QLineEdit *mPasswordEdit;
    QPushButton *mSignInButton;
    QPushButton *mSignUpButton;
    QPushButton *mChangeServerButton;

    QLabel *mStatusLabel;
};


#endif // LOGINWIDGET_H
