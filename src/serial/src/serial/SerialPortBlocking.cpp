#include <string.h>
#include <sys/ioctl.h>

#include "serial/SerialPortBlocking.h"
#include "serial/blocking_reader.h"



SerialPortBlocking::SerialPortBlocking(){
  port = new boost::asio::serial_port(io);
}


int SerialPortBlocking::connect(std::string device, int baud, size_t timeout) {
  try{
    port->open((char *) device.c_str());
    port->set_option(boost::asio::serial_port_base::baud_rate(baud));
    reader = new blocking_reader(port, timeout);
    return 1;
  }
  catch(...){
    return 0;
  }
}

void SerialPortBlocking::disconnect(void){
  port->close();
}

int SerialPortBlocking::sendArray(char *buffer, int len) {
  int n = boost::asio::write( *port,
                             boost::asio::buffer(buffer,len));
  return n;
}

int SerialPortBlocking::sendString(std::string msg){
  std::string tmp = msg + "\n";
  SerialPortBlocking::sendArray((char *) tmp.c_str(), tmp.length()); 
}

int SerialPortBlocking::getArray (char *buffer, int len){
  char rcvChar;
  int i = 0;
  while ( i < len && reader->read_char(rcvChar))
    buffer[i++] = rcvChar;
  return i;
}

int SerialPortBlocking::isOpen(){
  return port->is_open();
}

void SerialPortBlocking::flushPort(flush_type what){
  ::tcflush(this->port->lowest_layer().native_handle(), what);
}



