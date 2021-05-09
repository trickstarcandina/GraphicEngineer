#pragma once
#ifndef ELLIPSEBRESENHAM_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define ELLIPSEBRESENHAM_H

#include <GL/glut.h>
#include <math.h>

void initGLEllipseBresenham();
void draw4pointEllipseBresenham(int xc, int yc, int x, int y);
void EllipseBresenham(int xc, int yc, double a, double b);
void mydisplayEllipseBresenham();

#endif