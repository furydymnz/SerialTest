#pragma once
#include "mpu.h"
#include "ring_buffer.h"

class DataProcessor
{
public:
	DataProcessor();
	void calculateRadius(float &rx, float &ry, float &rz);

private:
	void retrieveAcceleration(int &ax, int &ay, int &az);

	MPU mpu;
	char mpuBuffer[50];
	RingBuffer xAcceBuffer, yAcceBuffer, zAcceBuffer;
};


