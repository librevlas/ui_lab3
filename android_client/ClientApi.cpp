#include "ClientApi.h"

#include <QList>

User::User(const QJsonObject &json)
    : login(json["login"].toString()), password(json["password"].toString()),
      birthdate(json["birthdate"].toString()) {}

Answer::Answer(const QJsonObject &json)
    : answerText(json["answerText"].toString()), id(json["id"].toString()) {
  QJsonArray answerersJson = json["answerers"].toArray();
  for (const auto &item : answerersJson) {
    answerers.emplace_back(item.toString());
  }
}

Question::Question(const QJsonObject &json)
    : authorLogin(json["authorLogin"].toString()), id(json["id"].toString()),
      createdDate(json["createdDate"].toString()),
      questionText(json["questionText"].toString()) {
  QJsonArray answersJson = json["answers"].toArray();
  for (const auto &item : answersJson) {
    answers.emplace_back(item.toObject());
  }
}

