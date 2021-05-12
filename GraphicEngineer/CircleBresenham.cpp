#include <GL/freeglut.h>
#include <math.h>
void initGLCircleBresenham(){
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1 thiet lap nen cua so 
	glOrtho(-320, 320, -240, 240, -1, 1);	// thiet lap toa do ve
}
void draw8pointCircleBresenham(int xc, int yc, int x, int y) // xc ,yc toa do tam 
{
	glBegin(GL_POINTS);  // ve diem
	glVertex2i(xc + x, yc + y); // ve diem goc phan 8 thu 1
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc - y, yc - x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc - x, yc + y);
	glEnd();
}
void CircleBresenham(int xc, int yc, int R)	// toa do tam , ban kinh
{
	int p;
	int y = R; //Chon diem dau tien (x,y) = (0,r)
	int x = 0;
	p = 3 - 2 * R; // công thuc tình trong thuât Bresebham
	draw8pointCircleBresenham(xc, yc, x, y);
	while (x < y) // dam bao dieu kiem diem can ve khong vuot qua 1/8 cung trong thu nhat
	{
		if (p < 0)	  // y(i+1) = y(i)
			p += 4 * x + 6;
		else
		{
			p += 4 * (x - y) + 10; // y(i+1) = y(i) -1
			y--;
		}
		x++;
		draw8pointCircleBresenham(xc, yc, x, y);// ve diem voi x , y moi 
	}
}

void mydisplayCircleBresenham(){
	glClear(GL_COLOR_BUFFER_BIT); // xoa tat ca cac mau trong vung dinh khung
	glColor3f(1.0, 0.0, 0.0); // thiet lap cac tham so mau ve
	CircleBresenham(0, 0, 200); //Tâm C(0,0) bán kính 200
	glViewport(0, 0, 640, 480); // thiet lap khung nhin
	glFlush(); // day khung trong ra vung dinh khung
}

void CircleBresenhamMethod() {
	int mode = GLUT_SINGLE | GLUT_RGB; // khoi tao mau
	glutInitDisplayMode(mode);
	glutInitWindowSize(640, 480); // thiet lap kich thuoc cua so  
	glutInitWindowPosition(200, 0);
	glutCreateWindow("DEMO THUAT TOAN VE DUONG TRON - BRESENHAM");
	initGLCircleBresenham();
	glutDisplayFunc(mydisplayCircleBresenham);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//cach 1
	glutMainLoop();
	//cach 2
	//glutMainLoopEvent();
}

