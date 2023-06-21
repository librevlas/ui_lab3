#ifndef UI_LAB3_CLIENT_H
#define UI_LAB3_CLIENT_H

#include "ClientApi.h"

class Client : public QObject {
Q_OBJECT
public:
  Client(QObject *parent)
  : QObject(parent), networkManager(new QNetworkAccessManager(this)) {}

  void setUrl(const QString &url) { baseUrl = url; }

  // User API
  bool signIn(const QString& login, const QString& password);
  void signUp(const User &user);

  // Question API
  QList<Question> getQuestions();
  void addQuestion(const Question &question);

  void addAnswer(const QString& questionId, const QString& login, const QString&  answer);
  void upvoteAnswer(const QString& questionId, const QString& login, const QString& answerId);

  User getLastUser() const { return mLastUser; }

private:
  QString baseUrl = "http://localhost:3000";
  QNetworkAccessManager *networkManager;

  void waitForReply(QNetworkReply *reply) {
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
  }

  User mLastUser;
};

#endif // UI_LAB3_CLIENT_H
