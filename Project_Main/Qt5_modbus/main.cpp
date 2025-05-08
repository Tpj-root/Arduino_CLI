#include <QCoreApplication>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QModbusRtuSerialClient>

class ModbusMaster : public QObject
{
    Q_OBJECT

public:
    ModbusMaster() : serialPort(new QSerialPort(this)), modbusClient(new QModbusRtuSerialClient())
    {
        // Set up the serial port to communicate with the Arduino
        serialPort->setPortName("/dev/ttyUSB0");
        serialPort->setBaudRate(QSerialPort::Baud9600);
        serialPort->setDataBits(QSerialPort::Data8);
        serialPort->setParity(QSerialPort::NoParity);
        serialPort->setStopBits(QSerialPort::OneStop);
        serialPort->setFlowControl(QSerialPort::NoFlowControl);

        if (!serialPort->open(QIODevice::ReadWrite)) {
            qDebug() << "Failed to open serial port";
            return;
        }

        // Set up Modbus RTU client
        modbusClient->setConnectionParameter(QModbusRtuSerialClient::SerialPortNameParameter, serialPort->portName());
        modbusClient->setConnectionParameter(QModbusRtuSerialClient::SerialPortBaudRateParameter, 9600);
        modbusClient->setConnectionParameter(QModbusRtuSerialClient::SerialPortDataBitsParameter, 8);
        modbusClient->setConnectionParameter(QModbusRtuSerialClient::SerialPortParityParameter, QSerialPort::NoParity);
        modbusClient->setConnectionParameter(QModbusRtuSerialClient::SerialPortStopBitsParameter, QSerialPort::OneStop);

        // Try to connect to the slave device (Arduino)
        if (!modbusClient->connectDevice()) {
            qDebug() << "Failed to connect to Modbus slave";
            return;
        }

        // Create a request to read holding registers
        QModbusDataUnit readUnit(QModbusDataUnit::HoldingRegisters, 0, 5);  // Read 5 registers starting from address 0
        if (auto reply = modbusClient->readData(readUnit)) {
            connect(reply, &QModbusReply::finished, this, &ModbusMaster::onReadFinished);
        } else {
            qDebug() << "Failed to send read request";
        }
    }

private slots:
    void onReadFinished()
    {
        auto reply = qobject_cast<QModbusReply *>(sender());
        if (!reply) {
            return;
        }

        if (reply->error() == QModbusDevice::NoError) {
            // Print the received data
            QModbusDataUnit unit = reply->result();
            QByteArray receivedData;
            for (int i = 0; i < unit.valueCount(); ++i) {
                receivedData.append((char)unit.value(i));  // Convert to characters
            }
            qDebug() << "Received from Arduino:" << receivedData;
        } else {
            qDebug() << "Read error:" << reply->errorString();
        }
        reply->deleteLater();
    }

private:
    QSerialPort *serialPort;
    QModbusRtuSerialClient *modbusClient;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ModbusMaster master;
    return a.exec();
}

#include "main.moc"
