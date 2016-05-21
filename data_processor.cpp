#include "data_processor.h"
#include <iostream>

#define MOVING_AVERAGE_SIZE 5
#define ACCELERATION_MAX 16384


DataProcessor::DataProcessor():
	xAcceBuffer(MOVING_AVERAGE_SIZE), 
	yAcceBuffer(MOVING_AVERAGE_SIZE), 
	zAcceBuffer(MOVING_AVERAGE_SIZE)
{
	mpu.setupMPU();
}

void DataProcessor::calculateRadius(float &rx, float &ry, float &rz)
{
	int ax, ay, az;
	ax = ay = az = rx = ry = rz = 0;

	retrieveAcceleration(ax, ay, az);

	xAcceBuffer.push(ax);
	yAcceBuffer.push(ay);
	zAcceBuffer.push(az);

	rx = xAcceBuffer.calculateAverage() / ACCELERATION_MAX;
	ry = yAcceBuffer.calculateAverage() / ACCELERATION_MAX;
	rz = zAcceBuffer.calculateAverage() / ACCELERATION_MAX;

	rx = rx < 0 ? -rx : rx;
	ry = ry < 0 ? -ry : ry;
	rz = rz < 0 ? -rz : rz;
}

void DataProcessor::retrieveAcceleration(int &ax, int &ay, int &az)
{
	mpu.readUntilEndline(mpuBuffer);

	std::istringstream ss(mpuBuffer);
	ss >> ax >> ay >> az;
}
