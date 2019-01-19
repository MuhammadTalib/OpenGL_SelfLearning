#include <GL/glut.h>
void func();
void textt(void);
void textt(void)
{
	glEnd();
	glFlush();


}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("name");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	
	glColor3f(1, 0, 0);
	func();

	glutDisplayFunc(textt);
	glutSwapBuffers();
	glutMainLoop();
	return 0;
}

void func()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 120, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0, 0, -30);
	char text[32] = "Talib";
	glColor3f(0, 0, 0);
	glRasterPos3f(-25, 20, -30);
	for (int i = 0; text[i] != '\0'; i++)
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);


	glEnd();
	

}
