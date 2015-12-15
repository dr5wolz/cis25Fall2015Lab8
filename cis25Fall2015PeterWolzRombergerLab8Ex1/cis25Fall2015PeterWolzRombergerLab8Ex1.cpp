/**
*Program Name:	cis25Fall2015PeterWolzRombergerLab7Ex1.cpp
*Discussion:	Shapes
*Writen by:		Peter Wolz-Romberger
*Date:			2015/12/15
*/

#include <iostream>
using namespace std;
#include "FRACTION.H"
#include "UTILITIES.H"
#include "POINT.H"
#include "SHAPE.h"
#include "RECTANGLE.h"
#include "CIRCLE.h"
#include "CYLINDER.h"

void mainMenu(void);

int main() {
	CylinderPeterW test;

	test = CylinderPeterW(CirclePeterW(PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1)), FractionPeterW(2, 2)), FractionPeterW(4, 1));

	cout << test.getArea();


	
	//displayClassInfoPeterWolzRomberger();
	//mainMenu();

}


void mainMenu() {

	int menuChoice;
	RectanglePeterW *rec1 = nullptr;
	RectanglePeterW *rec2 = nullptr;
	CirclePeterW *cir1 = nullptr;
	CirclePeterW *cir2 = nullptr;
	int initalizeCheck = 0;

	do {
		cout << "\n*************************************\n"
			<< "*              MAIN MENU            *\n"
			<< "*(1) Rectangle Tasks                *\n"
			<< "*(2) Circle Tasks                   *\n"
			<< "*(3) Mixed Rectangle & Circle Tasks *\n"
			<< "*(4) Quit                           *\n"
			<< "*************************************\n";

		cout << "Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1: cout << "  Rectangle Tasks --\n";
			if (initalizeCheck == 0 || initalizeCheck == 10) {
				initalizeCheck += rectangleMenu(&rec1, &rec2);
			}
			else {
				rectangleMenu(&rec1, &rec2);
			}
			break;
		case 2: cout << "  Circle Tasks --\n";
			if (initalizeCheck == 0 || initalizeCheck == 1) {
				initalizeCheck += circleMenu(&cir1, &cir2);
			}
			else {
				circleMenu(&cir1, &cir2);
			}
			break;
		case 3: cout << "  Mixed Rectangle & Circle Tasks --\n";
			if (initalizeCheck == 11) {
				mixedMenu(rec1, rec2, cir1, cir2);
			}
			else {
				cout << "\n    Not a proper call as no Points are available!\n";
			}
			break;
		case 4:  cout << "  Having Fun ...\n";
			break;
		default:
			cout << "WRONG OPTION!\n";
			break;
		}

	} while (menuChoice != 4);

}


/* PROGRAM OUTPUT

*/

/* COMMENTS ON Code/Output

*/