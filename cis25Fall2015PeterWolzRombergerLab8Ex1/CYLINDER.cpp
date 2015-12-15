/**
*Program Name: CYLINDER.h
*Discussion:   Rectangle
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/

#include <iostream>
using namespace std;
#include "FRACTION.H"
#include "UTILITIES.H"
#include "POINT.H"
#include "SHAPE.h"
#include "CIRCLE.h"
#include "CYLINDER.h"

CylinderPeterW::CylinderPeterW() {
	base = CirclePeterW(PointPeterW(FractionPeterW(0, 1), FractionPeterW(0, 1)), FractionPeterW(1,1));
	height = FractionPeterW(1, 1);
	cout << "calling Cylinder()\n";
}

CylinderPeterW::CylinderPeterW(const CirclePeterW& in1, const FractionPeterW& in2) {
	base = in1;
	height = in2;
	check(*this);
	cout << "calling Cylinder()\n";
}

CylinderPeterW::CylinderPeterW(const CylinderPeterW& in) {
	base = in.base;
	height = in.height;
	cout << "calling Cylinder()\n";
}

CylinderPeterW::~CylinderPeterW() {
	cout << "calling ~Cylinder()\n";
}

void CylinderPeterW::check(CylinderPeterW& in) {
	if (FractionPeterW(0, 1) > in.height) {
		cout << "    Height CANNOT BE =< 0 Height SET TO 1\n";
		in.height = FractionPeterW(1, 1);
	}
}

CylinderPeterW& CylinderPeterW::operator=(const CylinderPeterW& in) {
	base = in.base;
	height = in.height;
	return *this;
}

ostream& operator<<(ostream& out, const CylinderPeterW& in) {
	out << "\n        Cylinder has a base of " << in.base << "\n        and a height of " << in.height
		<< "\n        and a area of:"
		<< FractionPeterW((FractionPeterW(304, 50) * (in.base.getR())) * (in.base.getR() * in.height))
		<< "\n        and a volume of:"
		<< FractionPeterW(FractionPeterW(157 / 50) * (in.base.getR()) * (in.base.getR()) * in.height);
	return out;
}



FractionPeterW CylinderPeterW::getArea() {
	return FractionPeterW((FractionPeterW(304,50) * base.getR()) * (base.getR() * height));
}

FractionPeterW CylinderPeterW::getVolume() {
	return FractionPeterW(FractionPeterW(157 / 50) * (base.getR()) * (base.getR()) * height);
}



CylinderPeterW& CylinderPeterW::operator+(const CylinderPeterW& in) {
	FractionPeterW largerR;
	FractionPeterW largerH;

	if (base.getR() > in.base.getR()) {
		largerR = base.getR();
	} else {
		largerR = in.base.getR();
	}

	if (height > in.height) {
		largerH = height;
	} else {
		largerH = in.height;
	}

	return CylinderPeterW(CirclePeterW(PointPeterW(
		FractionPeterW(((base.getCenter()).getX() + (in.base.getCenter()).getX()) / FractionPeterW(2, 1)),
		FractionPeterW(((base.getCenter()).getY() + (in.base.getCenter()).getY()) / FractionPeterW(2, 1))),
		FractionPeterW(largerR)), FractionPeterW(largerH));
}

void CylinderPeterW::print() {
	cout << "\n        Cylinder has a base of " << base << "\n        and a height of " << height
		<< "\n        and a area of:"
		<< FractionPeterW((FractionPeterW(304, 50) * (base.getR())) * (base.getR() * height))
		<< "\n        and a volume of:"
		<< FractionPeterW(FractionPeterW(157 / 50) * (base.getR()) * (base.getR()) * height);
}