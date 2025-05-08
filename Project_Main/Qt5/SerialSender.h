#ifndef SERIALSENDER_H
#define SERIALSENDER_H

#include <QWidget>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class SerialSender; }
QT_END_NAMESPACE

class SerialSender : public QWidget {
    Q_OBJECT

public:
    SerialSender(QWidget *parent = nullptr);
    ~SerialSender();

private slots:
    void connectSerial();
    void sendCommand();
    void readData();

private:
    Ui::SerialSender *ui;
    QSerialPort *serial;
};

#endif // SERIALSENDER_H

