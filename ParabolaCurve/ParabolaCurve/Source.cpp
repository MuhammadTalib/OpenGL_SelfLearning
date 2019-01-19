#include <gl/glut.h>

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}

void display() {
	GLfloat midY = 100;
	GLfloat midX = 100;

	GLfloat y = 0;

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (GLfloat x = -200; x <= 200; x += 0.05) {
		y = x * x;
		glVertex2f(midX + x, midY + y);
	}
	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(400, 400);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Quadratic Formula");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}