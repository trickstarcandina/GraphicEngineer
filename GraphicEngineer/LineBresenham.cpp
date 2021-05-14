#include <GL/freeglut.h>
#include <math.h>

void initGLBreseham()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
    glOrtho(100, 320, 100, 240, -1, 1);
}
void LineBreseham(int x1, int y1, int x2, int y2)
{

    int Dx = x2 - x1;
    int Dy = y2 - y1;
    int p = 2 * Dy - Dx;
    int x = x1;
    int y = y1;
    glBegin(GL_POINTS);//lenh ve
    glVertex2i(x, y);//ve toa do bat dau
    while (x < x2)
    {
        if (p < 0)
            p += 2 * Dy;
        else
        {
            p += 2 * (Dy - Dx);
            y++;
        }
        x++;
        glVertex2i(x, y);//ve diem do ra
    }
    glEnd();
}
void lineBresenham(int x1, int y1, int x2, int y2) {
    int x, y, Dx, Dy, p;
    Dx = x2 - x1;
    Dy = y2 - y1;
    p = 2 * Dy - Dx;
    x = x1;
    y = y1;

    int x_unit = 1, y_unit = 1;

    if (x2 - x1 < 0)
        x_unit = -x_unit;
    if (y2 - y1 < 0)
        y_unit = -y_unit;
    glBegin(GL_POINTS);
    if (x1 == x2)   // tru?ng h?p v? du?ng th?ng d?ng
    {
        while (y != y2 + 1)
        {
            y += y_unit;
            glVertex2i(x, y);
        }
    }

    else if (y1 == y2)  // tru?ng h?p v? du?ng ngang
    {
        while (x != x2 + 1)
        {
            x += x_unit;
            glVertex2i(x, y);
        }
    }
    // tru?ng h?p v? các du?ng xiên
    else {
        glVertex2i(x, y);
        while (x != x2) {
            if (p < 0) p += 2 * Dy;
            else {
                p += 2 * (Dy - Dx);
                y += y_unit;
            }
            x += x_unit;
            glVertex2i(x, y);
        }
    }
    glEnd();
}
void mydisplayBreseham()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    //LineBres(10, 10, 200, 200);
    lineBresenham(200, 200, 50, 60);
    lineBresenham(200, 200, 50, 200);

    lineBresenham(200, 200, 50, 300);
    lineBresenham(200, 200, 200, 400);

    lineBresenham(200, 200, 300, 400);
    lineBresenham(200, 200, 300, 200);

    lineBresenham(200, 200, 400, 60);
    lineBresenham(200, 200, 200, 60);
    glViewport(0, 0, 640, 480);
    glFlush();

}

void LineBresenhamMethod() {
    int mode = GLUT_SINGLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DEMO THUAT TOAN VE DOAN THANG - BRESENHAM");
    initGLBreseham();
    glutDisplayFunc(mydisplayBreseham);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    //cach 1
    glutMainLoop();
    //cach 2
    //glutMainLoopEvent();
}


