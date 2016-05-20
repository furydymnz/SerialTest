// SerialTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "draw.h"
#include "mpu.h"

float rx, ry, rz;

MPU mpu;

void callback(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1.0);
	glLineWidth(5);


	glColor3f(1.0, 0, 0);
	Drawing::DrawCircle(0, 0, rx, 50);

	glColor3f(0, 1.0, 0);
	Drawing::DrawCircle(0, 0, ry, 50);

	glColor3f(0, 0, 1.0);
	Drawing::DrawCircle(0, 0, rz, 50);

	glutSwapBuffers();
}


void calc(int data)
{
	char a[100];
	const float MAX = 16384;
	static int i = 0;
	
	int x, y, z;
	glutPostRedisplay();
	mpu.readUntilEndline(a);

	std::istringstream ss(a);
	ss >> x >> y >> z;
	std::cout << x << "\t" << y << "\t" << z << "\n";

	x = x < 0 ? -x : x;
	y = y < 0 ? -y : y;
	z = z < 0 ? -z : z;

	rx = x / MAX;
	ry = y / MAX;
	rz = z / MAX;

	Drawing::resetTimer(0, calc);
}

int main(int argc, char **argv)
{
	mpu.setupMPU();
	Drawing::initDraw(argc, argv, callback, calc);
	Drawing::startLoop();
	
	return 0;
}
