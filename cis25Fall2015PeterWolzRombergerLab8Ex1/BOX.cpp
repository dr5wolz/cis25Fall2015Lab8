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
#include "RECTANGLE.h"
#include "BOX.h"

BoxPeterW::BoxPeterW() {
	base = RectanglePeterW(PointPeterW(FractionPeterW(0, 1), FractionPeterW(0, 1)), PointPeterW(FractionPeterW(1, 1), FractionPeterW(1,1)));
	height = FractionPeterW(1, 1);
	cout << "calling Box()\n";
}

BoxPeterW::BoxPeterW(const RectanglePeterW& in1, const FractionPeterW& in2) {
	base = in1;
	height = in2;
	check(*this);
	cout << "calling Box()\n";
}

BoxPeterW::BoxPeterW(const BoxPeterW& in) {
	base = in.base;
	height = in.height;
	cout << "calling Box()\n";
}

BoxPeterW::~BoxPeterW() {
	cout << "calling ~Box()\n";
}

void BoxPeterW::check(BoxPeterW& in) {
	if (FractionPeterW(0, 1) > in.height) {
		cout << "    Height CANNOT BE =< 0 Height SET TO 1\n";
		in.height = FractionPeterW(1, 1);
	}
}

BoxPeterW& BoxPeterW::operator=(const BoxPeterW& in) {
	base = in.base;
	height = in.height;
	return *this;
}

FractionPeterW BoxPeterW::getArea() {
	return FractionPeterW((base.getArea() + (base.getXDif() * height) + (base.getYDif() * height)) * FractionPeterW(2, 1));
}


FractionPeterW BoxPeterW::getVolume() {
	return FractionPeterW(base.getArea() * height);
}



ostream& operator<<(ostream& out, const BoxPeterW& in) {
	out << "\n        Box has a base of " << in.base << "\n        and a height of " << in.height
		<< "\n        and a area of:"
		<< FractionPeterW((((in.base.getXDif()) * (in.base.getYDif())) +
		((in.base.getXDif()) * (in.height)) + ((in.base.getYDif()) * (in.height))) * FractionPeterW(2, 1))
		<< "\n        and a volume of:"
		<< FractionPeterW(in.base.getXDif() * in.base.getYDif() * in.height);
	return out;
}

BoxPeterW& BoxPeterW::operator+(const BoxPeterW& in) {
	RectanglePeterW largerBase;
	FractionPeterW largerH;
	PointPeterW newLL;
	PointPeterW newUR;

	if (base.getArea() > FractionPeterW((in.base.getXDif() * in.base.getYDif()))) {
		largerBase = base;
	} else {
		largerBase = in.base;
	}

	if (height > in.height) {
		largerH = height;
	} else {
		largerH = in.height;
	}

	newLL = PointPeterW(FractionPeterW((base.getLLX() + in.base.getLLX()) / FractionPeterW(2,1)),
		FractionPeterW((base.getLLY() + in.base.getLLY()) / FractionPeterW(2, 1)));

	newUR = PointPeterW(FractionPeterW(newLL.getX() + largerBase.getXDif()),
		FractionPeterW(newLL.getY() + largerBase.getYDif()));

	return BoxPeterW(RectanglePeterW(newLL, newUR),
		FractionPeterW(largerH));
}

void BoxPeterW::print() {
	cout << "\n        Box has a base of " << base << "\n        and a height of " << height
		<< "\n        and a area of:"
		<< FractionPeterW((((base.getXDif()) * (base.getYDif())) +
		((base.getXDif()) * (height)) + ((base.getYDif()) * (height))) * FractionPeterW(2, 1))
		<< "\n        and a volume of:"
		<< FractionPeterW(base.getXDif() * base.getYDif() * height);
}