#include <iostream>
#include <GL/glfw.h>
using namespace std;
int main()
{
	GLFWimage image;
	if (glfwReadImage("ship.tga", &image, GLFW_ORIGIN_UL_BIT) != GL_TRUE);
	cout << "FAILED";
	system("PAUSE");
	return 0;
}