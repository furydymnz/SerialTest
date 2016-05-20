#include "mpu.h"

using namespace boost;

void MPU::setupMPU()
{
	io = new asio::io_service();
	port = new asio::serial_port(*io);
	port->open("COM4");
	port->set_option(asio::serial_port_base::baud_rate(115200));

	//port.close();
}

void MPU::readUntilEndline(char *str)
{
	char c = 0;
	int i = 0;
	while (c != 10) {
		asio::read(*port, asio::buffer(&c, 1));
		str[i++] = c;
	}
	str[i] = 0;
}
