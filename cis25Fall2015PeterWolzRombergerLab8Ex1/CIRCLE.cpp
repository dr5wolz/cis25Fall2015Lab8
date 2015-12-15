/**
*Program Name: CIRCLE.h
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

CirclePeterW::CirclePeterW() {
	center= PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1));
	r = FractionPeterW(1, 1);
	cout << "calling Circle()\n";
}

CirclePeterW::CirclePeterW(const PointPeterW& in1, const FractionPeterW& in2) {
	center= in1;
	r = in2;
	check(*this);
	cout << "calling Circle()\n";
}

CirclePeterW::CirclePeterW(const CirclePeterW& in) {
	center= in.center;
	r = in.r;
	cout << "calling Circle()\n";
}

CirclePeterW::~CirclePeterW() {
	cout << "calling ~Circle()\n";
}

void CirclePeterW::check(CirclePeterW& in) {
	if (FractionPeterW(0, 1) > in.r) {
		cout << "    RADIUS CANNOT BE =< 0 RADIUS SET TO 1\n";
		in.r = FractionPeterW(1, 1);
	}
}

CirclePeterW& CirclePeterW::operator=(const CirclePeterW& in) {
	center= in.center;
	r = in.r;
	return *this;
}

ostream& operator<<(ostream& out, const CirclePeterW& in) {
	out << "\n        Circle has a center of " << in.center<< " and a radius of " << in.r
		<< "\n        and a area of:" 
		<< FractionPeterW(in.r.getNum() * in.r.getNum() * 157,
		in.r.getDenom() * in.r.getDenom() * 50);
	return out;
}

FractionPeterW CirclePeterW::getArea() {
	return FractionPeterW(r.getNum() * r.getNum() * 157, r.getDenom() * r.getDenom() * 50);
}

CirclePeterW& CirclePeterW::operator+(const CirclePeterW& in) {
	return CirclePeterW(PointPeterW(FractionPeterW(((center.getX() + in.center.getX()) / FractionPeterW(2, 1))),
		FractionPeterW(((center.getY()) + (in.center.getY()) / FractionPeterW(2, 1)))), FractionPeterW(r + in.r));
}

FractionPeterW CirclePeterW::getR() const {
	return FractionPeterW(r);
}

PointPeterW CirclePeterW::getCenter() const {
	return PointPeterW(center.getX(), center.getY());
}

FractionPeterW CirclePeterW::getCenterX() const {
	return FractionPeterW(center.getX());
}

FractionPeterW CirclePeterW::getCenterY() const {
	return FractionPeterW(center.getY());
}

void CirclePeterW::print() {
	cout << "\n        Circle has a center of " << center << " and a radius of " << r
		<< "\n        and a area of:"
		<< FractionPeterW(r.getNum() * r.getNum() * 157,
		r.getDenom() * r.getDenom() * 50);
}