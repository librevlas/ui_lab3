#include "MainWindow.h"

#include <QApplication>

#include <QStyleFactory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*for (const auto &item : QStyleFactory::keys()) {
      qDebug() << item;
    }*/
//    a.setStyle(QStyleFactory::create("Windows"));
    a.setStyleSheet(R"(
QWidget {
    background-color: #eeeeee;
}

/* QLabel */
QLabel {
    color: #000000; /* Sets the text color to black */
    font: 18px; /* Sets the font size to 18 pixels */
    background-color: #eeeeee;
}

/* QPushButton */
QPushButton {
    color: #ffffff; /* Sets the text color to white */
    background-color: #0077ff; /* Sets the background color to a shade of blue */
    border-radius: 10px; /* Sets the border radius to create rounded corners */
    padding: 10px; /* Adds some padding around the button text */
}

QPushButton:pressed {
    background-color: #0055cc; /* Changes the button color when pressed */
}

/* QLineEdit */
QLineEdit {
    color: #000000; /* Sets the text color to black */
    background-color: #ffffff; /* Sets the background color to white */
    border: 1px solid #0077ff; /* Sets a blue border */
    padding: 5px; /* Adds some padding around the text */
}
)");
    MainWindow w;
    w.show();
    return a.exec();
}
