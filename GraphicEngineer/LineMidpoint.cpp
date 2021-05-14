#include <GL/freeglut.h>
#include <math.h>

void initGLMidpoint()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //R=0,G=0,B=0, anpha=1
    glOrtho(100, 320, 100, 240, -1, 1);
}
void lineMidpoint(int x1, int y1, int x2, int y2)
{

    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dy <= dx) {
        int d = dy - (dx / 2);
        int x = x1, y = y1;
        glBegin(GL_POINTS);//lenh ve
        glVertex2i(x, y);//ve toa do bat dau

        while (x < x2)
        {
            x++;

            // E or East is chosen
            if (d < 0)
                d = d + dy;

            // NE or North East is chosen
            else
            {
                d += (dy - dx);
                y++;
            }
            glVertex2i(x, y);//ve diem do ra
        }
    }
    else if (dx < dy)
    {
        int d = dx - (dy / 2);
        int x = x1, y = x1;
        glBegin(GL_POINTS);//lenh ve
        glVertex2i(x, y);//ve toa do bat dau
        while (y < y2)
        {
            y++;
            if (d < 0)
                d = d + dx;
            else
            {
                d += (dx - dy);
                x++;
            }
            glVertex2i(x, y);//ve diem do ra
        }
    }

    glEnd();
}

void mydisplayMidpoint()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    lineMidpoint(10, 10, 200, 200);
    lineMidpoint(200, 200, 50, 60);
    lineMidpoint(200, 200, 50, 200);

    lineMidpoint(200, 200, 50, 300);
    lineMidpoint(200, 200, 200, 400);

    lineMidpoint(200, 200, 300, 400);
    lineMidpoint(200, 200, 300, 200);

    lineMidpoint(200, 200, 400, 60);
    lineMidpoint(200, 200, 200, 60);
    glViewport(0, 0, 640, 480);
    glFlush();

}

void LineMidpointMethod() {
    int mode = GLUT_SINGLE | GLUT_RGB;
    glutInitDisplayMode(mode);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("DEMO THUAT TOAN VE DOAN THANG - MIDPOINT");

    initGLMidpoint();
    glutDisplayFunc(mydisplayMidpoint);
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);
    //cach 1
    glutMainLoop();
    //cach 2
    //glutMainLoopEvent();
}


