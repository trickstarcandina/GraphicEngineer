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
using namespace std;

int main(int argc, char** argv) {
	int select;
	cout << "Nhap lua chon cua ban" << endl;
	cout << "1.EllipseBresenham" << endl << "2.EllipseMidpoint" << endl;
	cout << "3.CircleBresenham" << endl << "4.CircleMidpoint" << endl;
	cout << "5.Polygons(Sinh Da Giac)" << endl << "6.Character(Sinh Ki Tu)" << endl;
	cout << "7.LineIntersection(Giao diem)" << endl;
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
				EllipseBresenhamMethod();
				break;
			case 2:
				glutInit(&argc, argv);
				EllipseMidpointMethod();
				break;
			case 3: 
				glutInit(&argc, argv);
				CircleBresenhamMethod();
				break;
			case 4:
				glutInit(&argc, argv);
				CircleMidpointMethod();
				break;
			case 5:
				glutInit(&argc, argv);
				PolygonsMethod();
				break;
			case 6:
				glutInit(&argc, argv);
				CharacterMethod();
				break;
			case 7:
				LineIntersectionMethod();
				break;
			default:
				cout << "Ban da nhap sai vui long nhap lai" << endl;
				break;
		}
	}
}