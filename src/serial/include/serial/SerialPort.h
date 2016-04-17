#ifndef SERIALPORT_H_
#define SERIALPORT_H_

#include <stdio.h>
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#include <boost/asio/serial_port.hpp> 
#include <boost/asio.hpp>
#include <boost/asio/deadline_timer.hpp> 
#include <boost/bind.hpp>
 
const int blockTimeMS = 10;
 
class SerialPort {
 private:
  boost::asio::io_service io;
  boost::asio::serial_port *port;
 public:
    SerialPort();
  
  int connect ();
  int connect (char * device, int baud);
  void disconnect(void);

  int sendArray(unsigned char *buffer, int len);
  int getArray (unsigned char *buffer, int len);
};


#endif /* SERIALPORT_H_ */
