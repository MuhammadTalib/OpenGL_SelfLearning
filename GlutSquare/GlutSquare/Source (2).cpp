
#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

#include<string>


using namespace std;

void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
	glFlush();
}
void String()
{
	//glMatrixMode(GL_PROJECTION);
	char text[32] = "Text";
	glColor3f(0, 0, 0);
	glRasterPos2f(50, 50);
	for (int i = 0; text[i] != '\0'; i++)
	glutBitmapCharacter(GLUT_BITMAP_8_BY_13, text[i]);
	glEnd();
}

void square()
{
	
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(2.0, 2.0);
	glVertex2f(50.0, 2.0);
	glVertex2f(50.0, 50.0);
	glVertex2f(2, 50.0);
	glEnd();
	
}
void square1()
{
	glColor3f(0.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex2f(50.0, 50.0);
	glVertex2f(100.0, 50.0);
	glVertex2f(100.0, 100.0);
	glVertex2f(50, 100.0);
	glEnd();

}
void display(void)
{
	
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("square");

	glClearColor(1.0, 1.0, 1.0, 0.0);         // black background 
	glLoadIdentity();                           // start with identity matrix 
	gluOrtho2D(0.0, 200.0, 0.0, 245);
	glClear(GL_COLOR_BUFFER_BIT);
	
	square();
	glutDisplayFunc(display);
	glutSwapBuffers();

	String();
	glutDisplayFunc(display);
	glutSwapBuffers();
	
	

	glutMainLoop();

	return 0;
}