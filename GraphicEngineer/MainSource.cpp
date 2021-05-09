#include <GL/glut.h>
#include <math.h>
#include "EllipseBresenham.h"

int main(int argc, char** argv) {
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);

	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG ELLIPSE - BRESENHAM");

	initGLEllipseBresenham();
	glutDisplayFunc(mydisplayEllipseBresenham);
	glutMainLoop();
	
}
