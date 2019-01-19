
#include<GL/glut.h>
#include<math.h>
using namespace std;
#include <stdio.h> 
#include <GL/glut.h>
void DrawCircle(void)
{
	
	glEnd();
	glFlush();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(2.0, 4.0, 0.0);
	glVertex3f(8.0, 4.0, 0.0);
	glVertex3f(8.0, 6.0, 0.0);
	glVertex3f(2.0, 6.0, 0.0);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	printf("hello world\n");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(300, 300);
	glutCreateWindow("square");

	glClearColor(0.0, 0.0, 0.0, 0.0);         // black background 
	glMatrixMode(GL_PROJECTION);              // setup viewing projection                          // start with identity matrix 
	gluOrtho2D(0.0, 200.0, 0.0, 200);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	float cx = 100;
	float cy = 100; float r = 100; int num_segments = 1000;
	glBegin(GL_POINTS);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glutDisplayFunc(DrawCircle);
	glutMainLoop();

	return 0;
}