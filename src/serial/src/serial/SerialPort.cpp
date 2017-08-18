#include <string.h>
#include <sys/ioctl.h>

#include "serial/SerialPort.h"



SerialPort::SerialPort() {
  port = new boost::asio::serial_port(io);
}


int SerialPort::connect(std::string device, int baud) {
  port->open((char *) device.c_str());
  port->set_option(boost::asio::serial_port_base::baud_rate(baud));
  return 1;
}

void SerialPort::disconnect(void){
  port->close();
}

int SerialPort::sendArray(unsigned char *buffer, int len) {
  int n = boost::asio::write( *port,
                             boost::asio::buffer(buffer,len));
  return n;
}

int SerialPort::sendString(std::string msg){
  std::string tmp = msg + "\n";
  SerialPort::sendArray((unsigned char *) tmp.c_str(), tmp.length()); 
}

int SerialPort::getArray (unsigned char *buffer, int len){
  char rcvChar;
  int i = 0;
  while ( i < len && boost::asio::read( *port, boost::asio::buffer(&rcvChar,1) ) == 1 )
    buffer[i++] = rcvChar;
  return i;
}

void SerialPort::flushPort(boost::asio::serial_port& serial_port, flush_type what)
{
  ::tcflush(serial_port.lowest_layer().native_handle(), what);
}



