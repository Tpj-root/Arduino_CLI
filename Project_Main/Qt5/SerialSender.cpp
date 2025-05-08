#include "SerialSender.h"
#include "ui_SerialSender.h"

SerialSender::SerialSender(QWidget *parent)
    : QWidget(parent), ui(new Ui::SerialSender), serial(new QSerialPort(this))
{
    ui->setupUi(this);

    connect(ui->connectButton, &QPushButton::clicked, this, &SerialSender::connectSerial);
    connect(ui->sendButton, &QPushButton::clicked, this, &SerialSender::sendCommand);
    connect(serial, &QSerialPort::readyRead, this, &SerialSender::readData);
}

SerialSender::~SerialSender() {
    if (serial->isOpen()) serial->close();
    delete ui;
}

void SerialSender::connectSerial() {
    serial->setPortName("/dev/ttyUSB0");
    serial->setBaudRate(QSerialPort::Baud115200);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);

    if (serial->open(QIODevice::ReadWrite)) {
        ui->statusLabel->setText("Connected");
    } else {
        ui->statusLabel->setText("Connection Failed");
    }
}

void SerialSender::sendCommand() {
    QString cmd = ui->inputLine->text().trimmed() + "\n";
    serial->write(cmd.toUtf8());
}

void SerialSender::readData() {
    QString response = serial->readAll();
    ui->outputBox->append(response);
}

