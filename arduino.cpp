// Arduino.cpp

#include "arduino.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>

Arduino::Arduino()
{
    data = "";
    arduino_port_name = "";
    arduino_is_available = false;
    serial = new QSerialPort;
}

QString Arduino::getarduino_port_name()
{
    return arduino_port_name;
}

QSerialPort *Arduino::getserial()
{
    return serial;
}

int Arduino::connect_arduino()
{
    // Find and open the serial port for Arduino
    foreach (const QSerialPortInfo &serial_port_info, QSerialPortInfo::availablePorts())
    {
        if (serial_port_info.hasVendorIdentifier() && serial_port_info.hasProductIdentifier())
        {
            if (serial_port_info.vendorIdentifier() == arduino_uno_vendor_id && serial_port_info.productIdentifier() == arduino_uno_producy_id)
            {
                arduino_is_available = true;
                arduino_port_name = serial_port_info.portName();
            }
        }
    }

    qDebug() << "Arduino port name is :" << arduino_port_name;

    if (arduino_is_available)
    {
        // Configure the communication settings
        serial->setPortName(arduino_port_name);

        if (serial->open(QSerialPort::ReadWrite))
        {
            serial->setBaudRate(QSerialPort::Baud9600);
            serial->setDataBits(QSerialPort::Data8);
            serial->setParity(QSerialPort::NoParity);
            serial->setStopBits(QSerialPort::OneStop);
            serial->setFlowControl(QSerialPort::NoFlowControl);
            return 0; // Connection successful
        }

        return 1; // Failed to open the serial port
    }

    return -1; // Arduino not found
}

int Arduino::close_arduino()
{
    if (serial->isOpen())
    {
        serial->close();
        return 0; // Successfully closed the serial port
    }

    return 1; // Serial port was not open
}

QByteArray Arduino::read_from_arduino()
{
    if (serial->isReadable())
    {
        data = serial->readAll(); // Read the received data
        qDebug() << "Received data from Arduino:" << data;
        return data;
    }

    return QByteArray(); // No data was read
}

int Arduino::write_to_arduino(QByteArray d)
{
    if (serial->isWritable())
    {
        serial->write(d); // Write data to Arduino
    }
    else
    {
        qDebug() << "Couldn't write to serial!";
        return 1; // Failed to write data
    }

    return 0; // Successfully wrote data
}
