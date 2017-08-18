#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>

#include <boost/asio/serial_port.hpp> 
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp> 
#include <boost/bind.hpp>
 
class SerialPort {
 private:
  boost::asio::io_service io;
  boost::asio::serial_port *port;
 public:
    SerialPort();
  
  int connect (std::string device, int baud);
  void disconnect(void);

  int sendArray(unsigned char *buffer, int len);
  int sendString(std::string msg);
  int getArray (unsigned char *buffer, int len);

  void flushPort(boost::asio::serial_port& serial_port, flush_type what);

  enum flush_type
  {
    flush_receive = TCIFLUSH,
    flush_send = TCIOFLUSH,
    flush_both = TCIOFLUSH
  };
};



#endif /* SERIALPORT_H_ */
