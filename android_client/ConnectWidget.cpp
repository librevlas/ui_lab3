#include "ConnectWidget.h"

ConnectWidget::ConnectWidget(QWidget *parent)
    : QWidget(parent), mUrlLabel(new QLabel("Server Url", this)),
      mUrlEdit(new QLineEdit(this)),
      mConnectButton(new QPushButton("Connect", this)) {
  QFormLayout *layout = new QFormLayout(this);
  layout->addRow(mUrlLabel, mUrlEdit);
  layout->addWidget(mConnectButton);

  mUrlEdit->setText("http://192.168.1.104:3000");

  connect(mConnectButton, &QPushButton::clicked, this,
          [this]() { emit connectToServer(mUrlEdit->text()); });
}
