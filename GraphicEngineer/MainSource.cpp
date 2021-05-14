#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "EllipseBresenham.h"
#include "EllipseMidpoint.h"
#include "CircleBresenham.h"
#include "CircleMidpoint.h"
#include "polygons.h"
#include "character.h"
#include "LineIntersection.h"
#include "LineBresenham.h"
#include "LineMidpoint.h"
using namespace std;

int main(int argc, char** argv) {
	int select;
	cout << "Nhap lua chon cua ban" << endl;
	cout << "1.Line Bresenham" <<endl << "2.Line Midpoint" << endl;
	cout << "3.Ellipse Bresenham" << endl << "4.Ellipse Midpoint" << endl;
	cout << "5.Circle Bresenham" << endl << "6.Circle Midpoint" << endl;
	cout << "7.Polygons (Sinh Da Giac)" << endl << "8.Character (Sinh Ki Tu)" << endl;
	cout << "9.LineIntersection (Giao diem)" << endl;
	cout << "0.Thoat" << endl; 
	//cach 2
	//glutInit(&argc, argv);
	while(true) {
		cin >> select;
		if (select == 0) break;
		//cach 1
		switch (select) {
			case 1:
				glutInit(&argc, argv);
				LineBresenhamMethod();
				break;
			case 2:
				glutInit(&argc, argv);
				LineMidpointMethod();
				break;
			case 3:
				glutInit(&argc, argv);
				EllipseBresenhamMethod();
				break;
			case 4:
				glutInit(&argc, argv);
				EllipseMidpointMethod();
				break;
			case 5: 
				glutInit(&argc, argv);
				CircleBresenhamMethod();
				break;
			case 6:
				glutInit(&argc, argv);
				CircleMidpointMethod();
				break;
			case 7:
				glutInit(&argc, argv);
				PolygonsMethod();
				break;
			case 8:
				glutInit(&argc, argv);
				CharacterMethod();
				break;
			case 9:
				LineIntersectionMethod();
				break;
			default:
				cout << "Ban da nhap sai vui long nhap lai" << endl;
				break;
		}
	}
}