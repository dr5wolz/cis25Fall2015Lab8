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
	cout << "calling Circle()\n";
}

CylinderPeterW::CylinderPeterW(const CirclePeterW& in1, const FractionPeterW& in2) {
	base = in1;
	height = in2;
	check(*this);
	cout << "calling Circle()\n";
}

CylinderPeterW::CylinderPeterW(const CylinderPeterW& in) {
	base = in.base;
	height = in.height;
	cout << "calling Circle()\n";
}

CylinderPeterW::~CylinderPeterW() {
	cout << "calling ~Circle()\n";
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
	out << "Cylinder has a base of " << in.base << " and a height of " << in.height
		<< " and a area of:"
		<< FractionPeterW((FractionPeterW(304, 50) * (in.base.getR())) * (in.base.getR() * in.height));
	return out;
}



FractionPeterW CylinderPeterW::getArea() {
	return FractionPeterW((FractionPeterW(304,50) * base.getR()) * (base.getR() * height));
}


/*
CylinderPeterW& CylinderPeterW::operator+(const CylinderPeterW& in) {
return CylinderPeterW(PointPeterW(FractionPeterW(((center.getX() + in.center->getX())/2)),
FractionPeterW((center.getY() + (in).center->getY())/2)), FractionPeterW(r + in.r));
}
*/