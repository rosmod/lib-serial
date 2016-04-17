#include <string.h>
#include <sys/ioctl.h>

#include "serial/SerialPort.h"

SerialPort::SerialPort() {
  port = new boost::asio::serial_port(io);
}

int SerialPort::connect() {
  port->open("/dev/ttyO5");
  port->set_option(boost::asio::serial_port_base::baud_rate(9600));
  return 1;
}

int SerialPort::connect(char *device, int baud) {
  port->open(device);
  port->set_option(boost::asio::serial_port_base::baud_rate(baud));
  return 1;
}

void SerialPort::disconnect(void)
{
  port->close();
}

int SerialPort::sendArray(unsigned char *buffer, int len) {
  int n = boost::asio::write( *port,
			      boost::asio::buffer(buffer,len));
  return n;
}

int SerialPort::getArray (unsigned char *buffer, int len)
{
  char rcvChar;
  int i = 0;
  while ( i < len && boost::asio::read( *port, boost::asio::buffer(&rcvChar,1) ) == 1 )
    buffer[i++] = rcvChar;
  return i;
}

