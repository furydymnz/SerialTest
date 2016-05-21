// SerialTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "draw.h"
#include "data_processor.h"

float rx, ry, rz;
DataProcessor dataProcessor;

void callback(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 1.0);
	glLineWidth(5);


	glColor3f(1.0, 0, 0);
	Drawing::DrawCircle(0.5, 0.5, rx/2, 50);

	
	glColor3f(0, 1.0, 0);
	Drawing::DrawCircle(0.5, -0.5, ry/2, 50);

	glColor3f(0, 0, 1.0);
	Drawing::DrawCircle(-0.5, -0.5, rz/2, 50);
	
	glutSwapBuffers();
}

void forceRefresh(int data)
{
	glutPostRedisplay();

	dataProcessor.calculateRadius(rx, ry, rz);

	//TODO calculate interval for bounded FPS
	Drawing::resetTimer(0, forceRefresh);

}

int main(int argc, char **argv)
{
	
	Drawing::initDraw(argc, argv, callback, forceRefresh);
	Drawing::startLoop();
	
	return 0;
}
