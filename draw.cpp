#include "draw.h"

void Drawing::DrawCircle(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta); //pre-calculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0;


	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex 

		t = x;					//apply the rotation matrix
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void Drawing::resetTimer(int ms, void(*calc)(int))
{
	glutTimerFunc(ms, calc, -1);
}

void Drawing::initDraw(int argc, char **argv, void(*callback)(), void(*calc)(int))
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL First Window");

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(callback);
	resetTimer(30, calc);
}

void Drawing::startLoop()
{
	glutMainLoop();
}
