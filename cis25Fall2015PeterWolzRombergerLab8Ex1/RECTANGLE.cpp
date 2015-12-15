/**
*Program Name: RECTANGLE.h
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

RectanglePeterW::RectanglePeterW() {
	ur = PointPeterW(FractionPeterW(1, 1), FractionPeterW(1, 1));
	ll = PointPeterW(FractionPeterW(0, 1), FractionPeterW(0, 1));

	cout << "calling Rectangle()\n";
}

RectanglePeterW::RectanglePeterW(const PointPeterW& in1, const PointPeterW& in2) {
	ur = in1;
	ll = in2;
	check(*this);
	cout << "calling Rectangle()\n";
}

RectanglePeterW::RectanglePeterW(const RectanglePeterW& in) {
	ur = in.ur;
	ll = in.ll;
	cout << "calling Rectangle()\n";
}

RectanglePeterW::~RectanglePeterW() {
	cout << "calling ~Rectangle()\n";
}

void RectanglePeterW::check(RectanglePeterW&) {
	FractionPeterW temp;
	int num;
	int denom;
	while (ur.getX() == ll.getX() || ur.getY() == ll.getY()) {
		cout << "\n    Not valid points as the X or Y values are on a line"
			<< "\n    Please enter new values for the conflicting points";
		if (ur.getX() == ll.getX()) {
			cout << "\n    please enter new X value Numerator: ";
			cin >> num;
			cout << "\n    please enter new X value Denominator: ";
			cin >> denom;
			temp = FractionPeterW(num, denom);
			if (temp > ur.getX()) {
				ur.setX(temp);
			} else {
				ll.setX(temp);
			}
		} else {
			cout << "\n    please enter new Y value Numerator: ";
			cin >> num;
			cout << "\n    please enter new Y value Denominator: ";
			cin >> denom;
			temp = FractionPeterW(num, denom);
			if (temp > ur.getY()) {
				ur.setY(temp);
			} else {
				ll.setY(temp);
			}
		}
	};

	
	if (ur.getX() > ll.getX()) {
		if (ll.getY() > ur.getY()) {
			temp = ll.getY();
			ll.setY(ur.getY());
			ur.setY(temp);
		}
	} else {
		if (ll.getY() > ur.getY()) {
			temp = ur.getY();
			ur.setY(ll.getY());
			ll.setY(temp);
		}

		temp = ur.getX();
		ur.setX(ll.getX());
		ll.setX(temp);
	}
}

RectanglePeterW& RectanglePeterW::operator=(const RectanglePeterW& in) {
	ur = in.ur;
	ll = in.ll;
	return *this;
}

ostream& operator<<(ostream& out, const RectanglePeterW& in) {
	out << "Rectangle bounded by " << in.ll << " and " << in.ur;
	return out;
}

FractionPeterW RectanglePeterW::getArea() {
	return FractionPeterW(FractionPeterW(ur.getX() - ll.getX()) * FractionPeterW(ur.getY() - ll.getY()));
}

FractionPeterW RectanglePeterW::getXDif() const {
	return FractionPeterW(ur.getX() - ll.getX());
}

FractionPeterW RectanglePeterW::getYDif() const {
	return FractionPeterW(ur.getY() - ll.getY());
}

RectanglePeterW RectanglePeterW::operator+(const RectanglePeterW& in) {
	return RectanglePeterW(PointPeterW((ll.getX() + in.ll.getX()) / FractionPeterW(2, 1),
		(ll.getY() + ((in.ll).getY())) / FractionPeterW(2, 1)),
		PointPeterW(
		((ll.getX() + in.ll.getX()) / (FractionPeterW(2, 1)) + (getXDif() + (in.getXDif())) / FractionPeterW(2, 1)),
		((ll.getY() + in.ll.getY()) / (FractionPeterW(2, 1)) + (getYDif() + (in.getYDif())) / FractionPeterW(2, 1))));
}

FractionPeterW RectanglePeterW::getLLY() const {
	return FractionPeterW(ll.getY());
}

FractionPeterW RectanglePeterW::getLLX() const {
	return FractionPeterW(ll.getX());
}

FractionPeterW RectanglePeterW::getURY() const {
	return FractionPeterW(ur.getY());
}

FractionPeterW RectanglePeterW::getURX() const {
	return FractionPeterW(ur.getX());
}

void RectanglePeterW::print() {
	cout << "Rectangle bounded by " << ll << " and " << ur;
}