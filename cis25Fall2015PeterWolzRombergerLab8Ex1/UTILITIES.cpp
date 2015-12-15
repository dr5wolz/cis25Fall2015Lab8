/**
*Program Name: Utilities.cpp
*Discussion:   Utilities
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/

#include <iostream>
using namespace std;
#include "FRACTION.H"
#include "UTILITIES.H"
#include "POINT.H"
#include "SHAPE.h"
#include "RECTANGLE.h"
#include "CIRCLE.h"

void displayClassInfoPeterWolzRomberger() {

	cout << "CIS 25 - C++ Programming\n"
		<< "Laney College\n"
		<< "Peter Wolz-Romberger\n\n"
		<< "Assignment Information --\n"
		<< "  Assignment Number:  Lab 08,\n"
		<< "                      Exercise #1\n"
		<< "  Written by:         Peter Wolz-Romberger\n"
		<< "  Due Date:           2015/12/15\n\n" << endl;
}

void initialize(RectanglePeterW** in) {
	int menuChoice;
	FractionPeterW xValue;
	FractionPeterW yValue;
	int value;
	PointPeterW ur;
	PointPeterW ll;

	if (*in == nullptr)
		delete *in;

	cout << "    Please enter the fraction values for Point #1\n"
		<< "      X Value, Numerator   : ";
	cin >> value;
	xValue.setNum(value);
	cout << "      X Value, Denominator : ";
	cin >> value;
	xValue.setDenom(value);
	cout << "      Y Value, Numerator   : ";
	cin >> value;
	yValue.setNum(value);
	cout << "      Y Value, Denominator : ";
	cin >> value;
	yValue.setDenom(value);
	cout << endl;
	ur = PointPeterW(xValue, yValue);
	xValue.setDenom(1);
	yValue.setDenom(1);

	cout << "    Please enter the fraction values for Point #2\n"
		<< "      X Value, Numerator   : ";
	cin >> value;
	xValue.setNum(value);
	cout << "      X Value, Denominator : ";
	cin >> value;
	xValue.setDenom(value);
	cout << "      Y Value, Numerator   : ";
	cin >> value;
	yValue.setNum(value);
	cout << "      Y Value, Denominator : ";
	cin >> value;
	yValue.setDenom(value);
	cout << endl;
	ll = PointPeterW(xValue, yValue);

	*in = new RectanglePeterW(ur, ll);

}

void initialize(CirclePeterW** in) {
	FractionPeterW xValue;
	FractionPeterW yValue;
	int value;
	PointPeterW ur;
	FractionPeterW r;

	if (*in == nullptr)
		delete *in;

	cout << "    Please enter the fraction values for Point #1\n"
		<< "      X Value, Numerator   : ";
	cin >> value;
	xValue.setNum(value);
	cout << "      X Value, Denominator : ";
	cin >> value;
	xValue.setDenom(value);
	cout << "      Y Value, Numerator   : ";
	cin >> value;
	yValue.setNum(value);
	cout << "      Y Value, Denominator : ";
	cin >> value;
	yValue.setDenom(value);
	cout << endl;
	ur = PointPeterW(xValue, yValue);

	cout << "    Please enter the fraction values for the Radius\n"
		<< "      Radius, Numerator   : ";
	cin >> value;
	r.setNum(value);
	cout << "      Radius, Denominator : ";
	cin >> value;
	r.setDenom(value);


	*in = new CirclePeterW(ur, r);
}

void initialize(CylinderPeterW** in) {
	FractionPeterW xValue;
	FractionPeterW yValue;
	int value;
	PointPeterW ur;
	FractionPeterW r;
	CirclePeterW base;
	FractionPeterW height;

	if (*in == nullptr)
		delete *in;

	cout << "    Please enter the fraction values for Center Point\n"
		<< "      X Value, Numerator   : ";
	cin >> value;
	xValue.setNum(value);
	cout << "      X Value, Denominator : ";
	cin >> value;
	xValue.setDenom(value);
	cout << "      Y Value, Numerator   : ";
	cin >> value;
	yValue.setNum(value);
	cout << "      Y Value, Denominator : ";
	cin >> value;
	yValue.setDenom(value);
	cout << endl;
	ur = PointPeterW(xValue, yValue);

	cout << "    Please enter the fraction values for the Radius\n"
		<< "      Radius, Numerator   : ";
	cin >> value;
	r.setNum(value);
	cout << "      Radius, Denominator : ";
	cin >> value;
	r.setDenom(value);

	base = CirclePeterW(ur, r);

	cout << "    Please enter the Height Numerator : ";
	cin >> value;
	height.setNum(value);
	cout << "    Please enter the Height Denominator : ";
	cin >> value;
	height.setDenom(value);

	*in = new CylinderPeterW(base, height);
}

int rectangleMenu(RectanglePeterW** rec1, RectanglePeterW** rec2) {
	int menuChoice;
	int initializeCheck = 0;
	FractionPeterW rec1Area;
	FractionPeterW rec2Area;

	if (*rec1 == nullptr) {
		initializeCheck = 0;
	}
	else {
		initializeCheck = 1;
	}

	do {
		cout << "\n    ************************************\n"
			<< "    *           RECTANGLE MENU         *\n"
			<< "    *  1. Create two Rectangle objects *\n"
			<< "    *  2. Compare by volume            *\n"
			<< "    *  3. Compare by area              *\n"
			<< "    *  4. Print two Rectangle objects  *\n"
			<< "    *  5. Quit                         *\n"
			<< "    ************************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			initialize(&(*rec1));
			initialize(&(*rec2));
			initializeCheck = 1;
			break;
		case 2:
			if (initializeCheck == 1) {
				cout << "\n      Volume of both rectangles are 0 as they are 2D shapes\n";
			}
			else {
				cout << "\n      Please set values of the Rectangles First\n";
			}
			break;
		case 3:
			if (initializeCheck == 1) {
				rec1Area = (*rec1)->getArea();
				rec2Area = (*rec2)->getArea();
				if (rec1Area > rec2Area) {
					cout << "\n      Rectangle 1 has a greater area of " << rec1Area
						<< "\n      than Rectangle 2's area of " << rec2Area << endl;
				}
				else if (rec1Area == rec2Area) {
					cout << "\n      Both Rectangles have an area of " << rec1Area;
				}
				else {
					cout << "\n      Rectangle 2 has a greater area of " << rec2Area
						<< "\n      than Rectangle 1's area of " << rec1Area << endl;
				}
			}
			else {
				cout << "\n      Please set values of the Rectangles First\n";
			}
			break;
		case 4:
			if (initializeCheck == 1) {
				cout << "\n      " << **rec1 << "\n      " << **rec2 << endl;
			}
			else {
				cout << "\n      Please set values of the Rectangles First\n";
			}
			break;
		case 5:
			cout << endl;
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 5);

	return initializeCheck;
}

int circleMenu(CirclePeterW** cir1, CirclePeterW** cir2) {
	int menuChoice;
	int initializeCheck;
	FractionPeterW cir1Area;
	FractionPeterW cir2Area;

	if (*cir1 == nullptr) {
		initializeCheck = 0;
	}
	else {
		initializeCheck = 1;
	}


	do {
		cout << "\n    *********************************\n"
			<< "    *           CIRCLE MENU         *\n"
			<< "    *  1. Create two Circle objects *\n"
			<< "    *  2. Compare by volume         *\n"
			<< "    *  3. Compare by area           *\n"
			<< "    *  4. Print two circle objects  *\n"
			<< "    *  5. Quit                      *\n"
			<< "    *********************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			initialize(&(*cir1));
			initialize(&(*cir2));
			initializeCheck = 10;
			break;
		case 2:
			if (initializeCheck == 10) {
				cout << "\n      Volume of both Circle are 0 as they are 2D shapes\n";
			}
			else {
				cout << "\n      Please set values of the Circles First\n";
			}
			break;
		case 3:
			if (initializeCheck == 10) {
				cir1Area = (*cir1)->getArea();
				cir2Area = (*cir2)->getArea();
				if (cir1Area > cir2Area) {
					cout << "\n      Circle 1 has a greater area of " << cir1Area
						<< "\n      than Circle 2's area of " << cir2Area << endl;
				}
				else if (cir1Area == cir2Area) {
					cout << "\n      Both Circles have an area of " << cir1Area;
				}
				else {
					cout << "\n      Circle 2 has a greater area of " << cir2Area
						<< "\n      than Cirlce 1's area of " << cir1Area << endl;
				}
			}
			else {
				cout << "\n      Please set values of the Circles First\n";
			}
			break;
		case 4:
			if (initializeCheck == 10) {
				cout << "\n      " << **cir1 << "\n      " << **cir2 << endl;
			}
			else {
				cout << "\n      Please set values of the Circles First\n";
			}
			break;
		case 5:
			cout << endl;
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 5);

	return initializeCheck;
}

void mixedMenu(RectanglePeterW* rec1, RectanglePeterW* rec2, CirclePeterW* cir1, CirclePeterW* cir2) {
	int menuChoice;
	FractionPeterW rec1Area = rec1->getArea();
	FractionPeterW rec2Area = rec2->getArea();
	FractionPeterW cir1Area = cir1->getArea();
	FractionPeterW cir2Area = cir2->getArea();
	int choice1;
	int choice2;
	int secondChoice;


	do {
		cout << "\n    **********************************\n"
			<< "    *  MIXED RECTANGLE & CIRCLE MENU *\n"
			<< "    *  1. Compare by area            *\n"
			<< "    *  2. Compare by volume          *\n"
			<< "    *  3. Print all objects          *\n"
			<< "    *  4. Quit                       *\n"
			<< "    **********************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "\n    **********************************\n"
				<< "    * RECTANGLES AND CIRCLES CHOICES *\n"
				<< "    *  1. Rectangle 1                *\n"
				<< "    *  2. Rectangle 2                *\n"
				<< "    *  3. Circle 1                   *\n"
				<< "    *  4. Circle 2                   *\n"
				<< "    **********************************\n";

			cout << "\n      Please enter the first object  :";
			cin >> choice1;
			cout << "      Please enter the second object :";
			cin >> choice2;
			if (choice1 > choice2) {
				secondChoice = choice1 + (10 * choice2);
			}
			else {
				secondChoice = (choice1 * 10) + choice2;
			}

			switch (secondChoice) {
			case 11:
				cout << "\n        Please enter 2 unique Objects\n";
				break;
			case 12:
				if (rec1Area > rec2Area) {
					cout << "\n      Rectangle 1 has a greater area of " << rec1Area
						<< "\n      than Rectangle 2's area of " << rec2Area << endl;
				}
				else if (rec1Area == rec2Area) {
					cout << "\n      Both Rectangle have an area of " << rec1Area;
				}
				else {
					cout << "\n      Rectangle 2 has a greater area of " << rec2Area
						<< "\n      than Rectangle 1's area of " << rec1Area << endl;
				}
				break;
			case 13:
				if (rec1Area > cir1Area) {
					cout << "\n      Rectangle 1 has a greater area of " << rec1Area
						<< "\n      than Circle 1's area of " << cir1Area << endl;
				}
				else if (rec1Area == cir1Area) {
					cout << "\n      Both Shapes have an area of " << rec1Area;
				}
				else {
					cout << "\n      Circle 1 has a greater area of " << cir1Area
						<< "\n      than Rectangle 1's area of " << rec1Area << endl;
				}
				break;
			case 14:
				if (rec1Area > cir2Area) {
					cout << "\n      Rectangle 1 has a greater area of " << rec1Area
						<< "\n      than Circle 2's area of " << cir2Area << endl;
				}
				else if (rec1Area == cir2Area) {
					cout << "\n      Both Shapes have an area of " << rec1Area;
				}
				else {
					cout << "\n      Circle 2 has a greater area of " << cir2Area
						<< "\n      than Rectangle 1's area of " << rec1Area << endl;
				}
				break;
			case 22:
				cout << "\n        Please enter 2 unique Objects\n";
				break;
			case 23:
				if (rec2Area > cir1Area) {
					cout << "\n      Rectangle 2 has a greater area of " << rec2Area
						<< "\n      than Circle 1's area of " << cir1Area << endl;
				}
				else if (rec2Area == cir1Area) {
					cout << "\n      Both Shapes have an area of " << rec2Area;
				}
				else {
					cout << "\n      Circle 1 has a greater area of " << cir1Area
						<< "\n      than Rectangle 2's area of " << rec2Area << endl;
				}
				break;
			case 24:
				if (rec2Area > cir2Area) {
					cout << "\n      Rectangle 2 has a greater area of " << rec2Area
						<< "\n      than Circle 2's area of " << cir2Area << endl;
				}
				else if (rec2Area == cir2Area) {
					cout << "\n      Both Shapes have an area of " << rec2Area;
				}
				else {
					cout << "\n      Circle 2 has a greater area of " << cir2Area
						<< "\n      than Rectangle 2's area of " << rec2Area << endl;
				}
				break;
			case 33:
				cout << "\n        Please enter 2 unique Objects\n";
				break;
			case 34:
				if (cir1Area > cir2Area) {
					cout << "\n      Circle 1 has a greater area of " << cir1Area
						<< "\n      than Circle 2's area of " << cir2Area << endl;
				}
				else if (cir1Area == cir2Area) {
					cout << "\n      Both Circles have an area of " << cir1Area;
				}
				else {
					cout << "\n      Circle 2 has a greater area of " << cir2Area
						<< "\n      than Cirlce 1's area of " << cir1Area << endl;
				}
				break;
			case 44:
				cout << "\n        Please enter 2 unique Objects\n";
				break;
			}

			break;
		case 2:
			cout << "\n      Please enter the first object  :";
			cin >> choice1;
			cout << "\n      Please enter the second object :";
			cin >> choice2;

			cout << "\n      Volume of both Shapes are 0 as they are 2D shapes\n";
			break;
		case 3:
			cout << "\n      The shapes that you have entered are:\n"
				<< "        Rectangle 1 :\n        "
				<< *rec1 << "\n        Rectangle 2 :\n        " << *rec2
				<< "\n        Circle 1 :\n        " << *cir1
				<< "\n        Circle 2 :\n        " << *cir2 << endl;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);
}