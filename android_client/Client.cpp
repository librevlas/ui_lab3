//
// Created by lesha on 20.06.2023.
//

#include "Client.h"

bool Client::signIn(const QString &login, const QString &password) {
  QUrl url(baseUrl + "/users/signin");
  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  auto creds = QJsonObject();
  creds["login"] = login;
  creds["password"] = password;
  QNetworkReply *reply =
      networkManager->post(request, QJsonDocument(creds).toJson());
  waitForReply(reply);
  qDebug() << reply->error();
  QJsonObject jsonObject = QJsonDocument::fromJson(reply->readAll()).object();
  mLastUser = User(jsonObject);
  return true;
}

void Client::signUp(const User &user) {
  auto creds = QJsonObject();
  creds["login"] = user.getLogin();
  creds["password"] = user.getPassword();
  creds["birthdate"] = user.getBirthdate();
  QUrl url(baseUrl + "/users");
  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QNetworkReply *reply =
      networkManager->post(request, QJsonDocument(creds).toJson());
  waitForReply(reply);
  qDebug() << reply->error();
  QJsonObject jsonObject = QJsonDocument::fromJson(reply->readAll()).object();
  mLastUser = User(jsonObject);
}

QList<Question> Client::getQuestions() {
  QUrl url(baseUrl + "/questions");
  QNetworkRequest request(url);
  QNetworkReply *reply = networkManager->get(request);
  waitForReply(reply);
  qDebug() << reply->error();

  QJsonArray jsonArray = QJsonDocument::fromJson(reply->readAll()).array();
  QList<Question> list;
  for (const auto &item : jsonArray) {
    auto obj = item.toObject();
    obj["questionText"] = obj["_questionText"].toString();
    list.emplace_back(obj);
  }
  return list;
}

void Client::addQuestion(const Question &question) {
  auto creds = question.toJson();
  QUrl url(baseUrl + "/questions");
  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QNetworkReply *reply =
      networkManager->post(request, QJsonDocument(creds).toJson());
  waitForReply(reply);
  qDebug() << reply->error();
}

void Client::addAnswer(const QString &questionId, const QString &login,
                       const QString &answer) {
  auto creds = QJsonObject();
  creds["login"] = login;
  creds["answerText"] = answer;
  QUrl url(baseUrl + "/questions/" + questionId + "/answers");
  QNetworkRequest request(url);
  request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
  QNetworkReply *reply =
      networkManager->post(request, QJsonDocument(creds).toJson());
  waitForReply(reply);
  qDebug() << reply->error();
}

void Client::upvoteAnswer(const QString &questionId, const QString &login,
                          const QString &answerId) {}
