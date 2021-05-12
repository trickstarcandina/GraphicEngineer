#pragma once
#ifndef CIRCLEBRESENHAM_H    
#define CIRCLEBRESENHAM_H

#include <GL/glut.h>
#include <math.h>

void initGLCircleBresenham();
void draw8pointCircleBresenham(int xc, int yc, int x, int y);
void CircleBresenham(int xc, int yc, int R);
void mydisplayCircleBresenham();
void CircleBresenhamMethod();

#endif