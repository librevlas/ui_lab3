#ifndef UI_LAB3_CONNECTWIDGET_H
#define UI_LAB3_CONNECTWIDGET_H

#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>

class ConnectWidget : public QWidget {
  Q_OBJECT

public:
  ConnectWidget(QWidget *parent);

signals:
  void connectToServer(QString url);

private:
  QLabel *mUrlLabel;
  QLineEdit *mUrlEdit;
  QPushButton *mConnectButton;
};

#endif // UI_LAB3_CONNECTWIDGET_H
