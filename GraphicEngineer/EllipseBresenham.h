#pragma once
#ifndef ELLIPSEBRESENHAM_H    
#define ELLIPSEBRESENHAM_H

#include <GL/glut.h>
#include <math.h>

void initGLEllipseBresenham();
void draw4pointEllipseBresenham(int xc, int yc, int x, int y);
void EllipseBresenham(int xc, int yc, double a, double b);
void mydisplayEllipseBresenham();
void EllipseBresenhamMethod();

#endif