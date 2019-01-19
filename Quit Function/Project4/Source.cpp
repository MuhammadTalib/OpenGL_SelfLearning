#include<windows.h>
#include <glut.h>

#include<iostream>
#include<stdlib.h>
using namespace std;
void showme(void);
void quit(unsigned char, int, int);
int win;
int main()
{
	glutInit();
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(620, 620);
	win = glutCreateWindow("Teapot");
	glutDisplayFunc(showme);
	glutKeyboardFunc(quit);
	glClearColor(0.2, 0.5, 0.2, 0.2);
	glutMainLoop();
	return 0;
}
void quit(unsigned char key, int x, int y)
{
	cout << "Key: " << key << " pressed" << endl;
	cout << "Cursor position: " << x << " " << y << endl;
	if (key == 'q')
	{
		glutDestroyWindow(win);
		exit(0);
	}
}
void showme(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.9, -0.5);
	glVertex2f(0.3, -1.0);
	glVertex2f(0.0, 1.0);
	glEnd();
	glFlush();
}