#include <GL/freeglut.h>
#include <math.h>

void initGLPolygons() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // mau nen 
	glOrtho(-320, 320, -240, 240, -1, 1); // cau hinh toa do
}

typedef struct Dinh {
	int x, y;
};
void VeDaGiac(Dinh d[], int n) {
	for (int i = 0; i < n - 1; i++) {
		glBegin(GL_LINES);// khởi tạo vẽ đường thẳng
		glVertex2f(d[i].x, d[i].y);// điểm thứ 1
		glVertex2f(d[i + 1].x, d[i + 1].y);// điểm t2
		glEnd();// kết thúc vẽ
		glFlush();
	}
	glBegin(GL_LINES);// khởi tạo vẽ đoạn thẳng
	glVertex2f(d[0].x, d[0].y);// điểm thứ 1
	glVertex2f(d[n - 1].x, d[n - 1].y); // điểm thứ 2
	glEnd();
	glFlush();
}

void mydisplayPolygons() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); // tạo màu vẽ, màu đỏ
	//Dinh d[4] = { {-20,50},{40,50},{-60,-20},{40,-20} };
	Dinh d[4] = { {-80,200},{160,200},{-240,-80},{160,-80} };
	VeDaGiac(d, 4);
}
void PolygonsMethod() {
	int mode = GLUT_SINGLE | GLUT_RGB;
	glutInitDisplayMode(mode);// thiết lập cấu hình, chế độ hiển thị
	glutInitWindowSize(640, 480);// set kích thước cửa sổ 640x480
	glutInitWindowPosition(0, 0);// khởi tại vị trí cửa sổ (0,0)
	glutCreateWindow("DEMO THUAT TOAN SINH DA GIAC");//tiêu đề cửa sổ
	initGLPolygons();
	glutDisplayFunc(mydisplayPolygons);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
	//cach 1
	glutMainLoop();
	//cach 2
	//glutMainLoopEvent();
}