#include <GL/freeglut.h>
#include <math.h>
#include <iostream>
#include "EllipseBresenham.h"
#include "EllipseMidpoint.h"
using namespace std;

int main(int argc, char** argv) {
	int select;
	cout << "Nhap lua chon cua ban" << endl;
	cout << "1.EllipseBresenham" << endl << "2.EllipseMidpoint" << endl;
	cout << "0.Thoat" << endl; 
	//cach 2
	//glutInit(&argc, argv);
	while(true) {
		cin >> select;
		//cach 1
		glutInit(&argc, argv); 
		if (select == 1) {
			EllipseBresenhamMethod();
		}
		else if (select == 2) {
			EllipseMidpointMethod();
		}
		else if (select == 0) {
			break;
		}
	}
}