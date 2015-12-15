/**
*Program Name: POINT.cpp
*Discussion:   Points
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/

#include <iostream>
using namespace std;
#include "FRACTION.H"
#include "UTILITIES.H"
#include "POINT.H"

PointPeterW::PointPeterW() {
	x = FractionPeterW(0, 1);
	y = FractionPeterW(0, 1);
	cout << "calling Point()\n";
}

PointPeterW::PointPeterW(const FractionPeterW& inX, const FractionPeterW& inY) {
	x = inX;
	y = inY;
	cout << "calling Point()\n";
}

PointPeterW::PointPeterW(const PointPeterW& in) {
	x = in.x;
	y = in.y;
	cout << "calling Point()\n";
}

PointPeterW::~PointPeterW(){
	cout << "calling ~Point()\n";
}

void PointPeterW::setX(const FractionPeterW& in) {
	x = in;
}

void PointPeterW::setY(const FractionPeterW& in) {
	y = in;
}

FractionPeterW PointPeterW::getX() const{
	return FractionPeterW(x);
}

FractionPeterW PointPeterW::getY() const{
	return FractionPeterW(y);
}

void PointPeterW::moveBy(const FractionPeterW& delX, const FractionPeterW& delY) {
	x = x + delX;
	y = y + delY;
}

void PointPeterW::moveBy(const int& iOld) {
	x = x + iOld;
	y = y + iOld;
}

void PointPeterW::moveBy(const FractionPeterW& in) {
	x = x + in;
	y = y + in;
}

void PointPeterW::flipByX() {
	y.setNum(-y.getNum());
}

void PointPeterW::flipByY() {
	x.setNum(-x.getNum());
}

void PointPeterW::flipThoughOrigin() {
	x.setNum(-x.getNum());
	y.setNum(-y.getNum());
}

void PointPeterW::print() {
	cout << "Point: (" << x << ", " << y << ")";
}

ostream& operator<<(ostream& out, const PointPeterW& in) {
	out << "Point: (" << in.x << ", " << in.y << ")";
	return out;
}
