#include <GL/freeglut.h>
#include <math.h>

void initGLEllipseBresenham(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
	glOrtho(-320, 320, -240, 240, -1, 1);
}
void draw4pointEllipseBresenham(int xc, int yc, int x, int y){
	glBegin(GL_POINTS);

	glVertex2i(x + xc, y + yc);
	glVertex2i(x + xc, -y + yc);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - x, yc + y);

	glEnd();
}
void EllipseBresenham(int xc, int yc, double a, double b){

	int x = 0;
	int y = b;

	float x0 = a * a / sqrt(a * a + b * b);
	float P = a * a * (1 - 2 * b) + b * b;
	draw4pointEllipseBresenham(xc, yc, x, y);
	while (x <= x0){
		if (P < 0)
			P += (2 * b * b) * (2 * x + 3);
		else{

			P += (2 * b * b) * (2 * x + 3) + 4 * a * a * (1 - y);
			y--;
		}
		x++;
		draw4pointEllipseBresenham(xc, yc, x, y);
	}

	x = a;
	y = 0;

	P = b * b * (1 - 2 * a) + a * a;
	draw4pointEllipseBresenham(xc, yc, x, y);
	while (x > x0)
	{
		if (P < 0)
			P += (2 * a * a) * (2 * y + 3);
		else{
			P += (2 * a * a) * (2 * y + 3) + 4 * b * b * (1 - x);

			x--;
		}
		y++;
		draw4pointEllipseBresenham(xc, yc, x, y);
	}

}

void mydisplayEllipseBresenham(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	EllipseBresenham(0, 0, 300, 200); //T?m C(0,0) b?n k?nh 200
	glViewport(0, 0, 640, 480);
	glFlush();
}

void EllipseBresenhamMethod() {
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG ELLIPSE - BRESENHAM");
	initGLEllipseBresenham();
	glutDisplayFunc(mydisplayEllipseBresenham);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//cach 1
	glutMainLoop();
	//cach 2
	//glutMainLoopEvent();
}