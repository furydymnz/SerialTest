#pragma once
#include <boost/asio/serial_port.hpp>
#include <boost/asio.hpp>

using namespace boost;

class MPU
{
public:
	void setupMPU();
	void readUntilEndline(char *str);
protected:
private:
	asio::io_service *io;
	asio::serial_port *port;
};
