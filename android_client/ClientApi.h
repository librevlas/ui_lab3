#ifndef UI_LAB3_CLIENTAPI_H
#define UI_LAB3_CLIENTAPI_H

#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>

#include <QEventLoop>
#include <QJsonArray>
#include <QJsonObject>

class User {
public:
  User() : login(""), password(""), birthdate("") {}
  User(const QJsonObject &json);

  QJsonObject toJson() const {
    QJsonObject json;
    json["login"] = login;
    json["password"] = password;
    json["birthdate"] = birthdate;
    return json;
  }

  // Getters
  QString getLogin() const { return login; }
  QString getPassword() const { return password; }
  QString getBirthdate() const { return birthdate; }

  // Setters
  void setLogin(const QString &newLogin) { login = newLogin; }
  void setPassword(const QString &newPassword) { password = newPassword; }
  void setBirthdate(const QString &newBirthdate) { birthdate = newBirthdate; }

private:
  QString login;
  QString password;
  QString birthdate;
};

class Answer {
public:
  Answer() : id(QUuid::createUuid().toString()) {}
  Answer(const QJsonObject &json);

  QJsonObject toJson() const {
    QJsonObject json;
    json["answerText"] = answerText;
    json["id"] = id;
    QJsonArray jsonAnswerers;
    for (const QString &answerer : answerers) {
      jsonAnswerers.push_back(answerer);
    }
    json["answerers"] = jsonAnswerers;
    return json;
  }

  void setAnswerText(QString text) { answerText = text; }

  QString getAnswerText() const { return answerText; }
  QString getId() const { return id; }
  QStringList getAnswerers() const { return answerers; }

private:
  QString answerText;
  QString id;
  QStringList answerers;
};

class Question {
public:
  Question()
      : authorLogin(""), id(QUuid::createUuid().toString()), createdDate(""),
        questionText("") {}
  Question(const QJsonObject &json);

  QJsonObject toJson() const {
    QJsonObject json;
    json["authorLogin"] = authorLogin;
    json["id"] = id;
    json["createdDate"] = createdDate;
    json["questionText"] = questionText;
    QJsonArray jsonAnswers;
    for (const Answer &answer : answers) {
      jsonAnswers.append(answer.toJson());
    }
    json["answers"] = jsonAnswers;
    return json;
  }

  // Getters
  QString getAuthorLogin() const { return authorLogin; }
  QString getId() const { return id; }
  QString getCreatedDate() const { return createdDate; }
  QString getQuestionText() const { return questionText; }
  QList<Answer> getAnswers() const { return answers; }

  // Setters
  void setAuthorLogin(const QString &newAuthorLogin) {
    authorLogin = newAuthorLogin;
  }
  void setId(const QString &newId) { id = newId; }
  void setCreatedDate(const QString &newCreatedDate) {
    createdDate = newCreatedDate;
  }
  void setCurrentCreatedDate() {
    auto date = QDateTime::currentDateTime();
    createdDate = date.toString("dd.MM.yyyy");
  }
  void setQuestionText(const QString &newQuestionText) {
    questionText = newQuestionText;
  }

private:
  QString authorLogin;
  QString id;
  QString createdDate;
  QString questionText;
  QList<Answer> answers;
};

#endif // UI_LAB3_CLIENTAPI_H
