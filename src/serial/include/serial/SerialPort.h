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

  int sendArray(char *buffer, int len);
  int sendString(std::string msg);
  int getArray (char *buffer, int len);

  enum flush_type
  {
    flush_receive = TCIFLUSH,
    flush_send = TCIOFLUSH,
    flush_both = TCIOFLUSH
  };

  void flushPort(flush_type what);

  
};



#endif /* SERIALPORT_H_ */
