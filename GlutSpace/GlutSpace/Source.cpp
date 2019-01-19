#include <stdlib.h> 
#include <stdio.h> 
#include <math.h> 
#include <GL/glut.h>
#define KEY_ESC 27 /* GLUT doesn't supply this */
int myrandom(int m) {

	return rand() % 255;

}

GLvoid display(GLvoid) {
	/* Do all your OpenGL rendering here */
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case 27:             // ESCAPE key
		exit(0);
		break;
	case 32:

		glClearColor((double)myrandom(255) / 255, (double)myrandom(255) / 255, (double)myrandom(255) / 255, (double)myrandom(255) / 255);
		glutPostRedisplay();
		break;
	}
}

void init() {
	glClearColor(1.0, 1.0, 0.0, 1.0);
}

int main(int argc, char* argv[]) {
	GLint width;
	GLint height;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	width = glutGet(GLUT_SCREEN_WIDTH);
	height = glutGet(GLUT_SCREEN_HEIGHT);
	glutInitWindowPosition(width / 4, height / 4);
	glutInitWindowSize(width / 2, height / 2);
	glutCreateWindow(argv[0]);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	init();
	glutMainLoop();
	return 0;
}