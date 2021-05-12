#include <GL/freeglut.h>
#include <math.h>

void initGLCircleMidpoint(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1 chon mau nen (0.0f, 0.0f, 0.0f, 1.0f) mau den
	glOrtho(-320, 320, -240, 240, -1, 1);
}
void draw8pointCircleMidpoint(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc - x, yc + y);
	glEnd();
}
void CircleMidpoint(int xc, int yc, int R)
{
	float P;
	int y = R;
	int x = 0;//Chon diem dau tien (x,y) = (0,r)
	P = 5 / 4 - R;
	draw8pointCircleMidpoint(xc, yc, x, y);
	while (x < y)  // dam bao dieu kiem diem can ve khong vuot qua 1/8 cung trong thu nhat
	{
		if (P < 0)	// x(i+1) = x(i)+1  ; y(i+1)= y(i);
		{
			P += 2 * x + 3;

		}
		else      // x(i+1) = x(i)+1 ; y(i+1) = y(i)-1
		{
			P += 2 * (x - y) + 5;
			y--;
		}

		x++;
		draw8pointCircleMidpoint(xc, yc, x, y);
	}
}

void mydisplayCircleMidpoint(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	CircleMidpoint(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0, 0, 640, 480);
	glFlush();
}

void CircleMidpointMethod() {
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG TRON - MIDPOINT");
	initGLCircleMidpoint();
	glutDisplayFunc(mydisplayCircleMidpoint);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//cach 1
	glutMainLoop();
	//cach 2
	//glutMainLoopEvent();
}

