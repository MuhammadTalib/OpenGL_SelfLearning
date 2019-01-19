//this shows one way to get FPS using an inprecise clock
//see idle() and change
// 1. to go as fast as hardware: #undef REGULATE_FPS  
// 2. to throttle to 1/35ms=29FPS: #define REGULATE_FPS
#include <cstdlib>
#include <iostream>

//linux openGL headers
#include <GL/gl.h>
#include <GL/glut.h>

GLint gFramesPerSecond = 0;

void FPS(void) {
	static GLint Frames = 0;         // frames averaged over 1000mS
	static GLuint Clock;             // [milliSeconds]
	static GLuint PreviousClock = 0; // [milliSeconds]
	static GLuint NextClock = 0;     // [milliSeconds]

	++Frames;
	Clock = glutGet(GLUT_ELAPSED_TIME); //has limited resolution, so average over 1000mS
	if (Clock < NextClock) return;

	gFramesPerSecond = Frames / 1; // store the averaged number of frames per second

	PreviousClock = Clock;
	NextClock = Clock + 1000; // 1000mS=1S in the future
	Frames = 0;
}

void idle() {
#define REGULATE_FPS
#ifdef REGULATE_FPS
	static GLuint PreviousClock = glutGet(GLUT_ELAPSED_TIME);
	static GLuint Clock = glutGet(GLUT_ELAPSED_TIME);
	static GLfloat deltaT;

	Clock = glutGet(GLUT_ELAPSED_TIME);
	deltaT = Clock - PreviousClock;
	if (deltaT < 35) { return; }
	else { PreviousClock = Clock; }
#endif

	printf(".");
	FPS(); //only call once per frame loop 
	glutPostRedisplay();
}

void display() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	// Set the drawing color (RGB: WHITE)
	printf("FPS %d\n", gFramesPerSecond);
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_LINE_STRIP); {
		glVertex3f(0.25, 0.25, 0.0);
		glVertex3f(0.75, 0.25, 0.0);
		glVertex3f(0.75, 0.75, 0.0);
		glVertex3f(0.25, 0.75, 0.0);
		glVertex3f(0.25, 0.25, 0.0);
	}
	glEnd();

	glutSwapBuffers();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 27:  // escape key
		exit(0);
		break;
	default:
		break;
	}
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("FPS test");

	glutIdleFunc(idle);
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);

	init();

	glutMainLoop();
	return 0;
}