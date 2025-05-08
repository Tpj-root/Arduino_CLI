#include "SerialSender.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    SerialSender window;
    window.setWindowTitle("Serial Command Sender");
    window.resize(400, 300);
    window.show();

    return app.exec();
}

