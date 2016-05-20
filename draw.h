#pragma once
#include "GL\glew.h"
#include "GL\freeglut.h"
#include <iostream>

class Drawing
{
public:
	static void initDraw(int argc, char **argv, void(*callback)(), void(*calc)(int));
	static void startLoop();
	static void DrawCircle(float cx, float cy, float r, int num_segments = 20);
	static void resetTimer(int ms, void(*calc)(int));
};
