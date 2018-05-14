#ifndef SERIALPORTBLOCKING_H_
#define SERIALPORTBLOCKING_H_

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>

#include <boost/asio/serial_port.hpp> 
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp> 
#include <boost/bind.hpp>

#include "smc/blocking_reader.h"
 
class SerialPortBlocking {
 private:
  boost::asio::io_service io;
  boost::asio::serial_port *port;
  blocking_reader *reader;
public:
    SerialPortBlocking();
  
  int connect (std::string device, int baud, size_t timeout);
  void disconnect(void);

  int sendArray(char *buffer, int len);
  int sendString(std::string msg);
  int getArray (char *buffer, int len);
  int isOpen();

  enum flush_type
  {
    flush_receive = TCIFLUSH,
    flush_send = TCOFLUSH,
    flush_both = TCIOFLUSH
  };

  void flushPort(flush_type what);

  
};



#endif /* SERIALPORT_H_ */
