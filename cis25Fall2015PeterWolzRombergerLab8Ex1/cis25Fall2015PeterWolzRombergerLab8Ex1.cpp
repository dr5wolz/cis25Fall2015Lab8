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
#include "BOX.h"

void mainMenu(void);
void shapeMenu(void);

int main() {
	/*
	RectanglePeterW test1;
	RectanglePeterW test2;
	RectanglePeterW test3;

	test1 = RectanglePeterW(PointPeterW(FractionPeterW(0, 1), FractionPeterW(0, 1)), PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1)));
	test2 = RectanglePeterW(PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1)), PointPeterW(FractionPeterW(2, 1), FractionPeterW(2, 1)));
	test3 = test1 + test2;
	cout << "\n\n\n\n\n\n" << test3 << "\n\n\n\n\n\n\n";
	*/
	/*
	CylinderPeterW test;
	test = CylinderPeterW(CirclePeterW(PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1)), FractionPeterW(2, 2)), FractionPeterW(4, 1));
	cout << test;
	*/

	
	//displayClassInfoPeterWolzRomberger();
	shapeMenu();

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

void shapeMenu() {

	int menuChoice;
	Shape** listOfShapes;
	int sizeOfArray;
	int initalizeCheck = 0;
	RectanglePeterW *tempRec;
	CirclePeterW *tempCir;
	CylinderPeterW *tempCyl;
	BoxPeterW *tempBox;
	sizeOfArray = 8;
	listOfShapes = new Shape*[sizeOfArray];
	
	do {
		cout << "\n*******************************************\n"
			<< "*              MAIN MENU                  *\n"
			<< "*(1) Create 2 RectanglePeterW objects     *\n"
			<< "*(2) Create 2 CirclePeterW objects        *\n"
			<< "*(3) Create 2 BoxPeterW objects           *\n"
			<< "*(4) Create 2 CylinderPeterW objects      *\n"
			<< "*(4) Compare 2 selected objects by area   *\n"
			<< "*(4) Compare 2 selected objects by volume *\n"
			<< "*(4) Print selected objects               *\n"
			<< "*(4) Quit                                 *\n"
			<< "*******************************************\n";

		cout << "Enter your option (1, 2, 3, 4, 5, 6, 7, or 8): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1: cout << "  Create 2 Rectangle objects --\n";
			if (*listOfShapes == nullptr) {
				delete *listOfShapes;
			}
			initialize(&tempRec);
			*listOfShapes = new RectanglePeterW(*tempRec);
			if (*(listOfShapes + 1) == nullptr) {
				delete *(listOfShapes + 1);
			}
			initialize(&tempRec);
			*(listOfShapes + 1) = new RectanglePeterW(*tempRec);
			break;
		case 2: cout << "  Create 2 Circle objects --\n";
			if (*(listOfShapes + 2) == nullptr) {
				delete *(listOfShapes + 2);
			}
			initialize(&tempCir);
			*(listOfShapes + 2) = new CirclePeterW(*tempCir);
			if (*(listOfShapes + 3) == nullptr) {
				delete *(listOfShapes + 3);
			}
			initialize(&tempRec);
			*(listOfShapes + 3) = new RectanglePeterW(*tempRec);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:  
			(*(*listOfShapes)).print();
			(*(*listOfShapes + 1)).print();
			(*(*listOfShapes + 2)).print();
			(*(*listOfShapes + 3)).print();
		case 8:  cout << "  Having Fun ...\n";
			break;
		default:
			cout << "WRONG OPTION!\n";
			break;
		}

	} while (menuChoice != 8);

}

/* PROGRAM OUTPUT

*/

/* COMMENTS ON Code/Output

*/