/**
*Program Name: RECTANGLE.h
*Discussion:   Rectangles
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/


#include "FRACTION.h";
#include "POINT.h";
#include "SHAPE.h";

using namespace std;
#ifndef RECTANGLEPETERW_H
#define RECTANGLEPETERW_H

class RectanglePeterW : public Shape {
public:

	//base constructors and destructors
	RectanglePeterW();
	RectanglePeterW(const PointPeterW&, const PointPeterW&);
	RectanglePeterW(const RectanglePeterW&);
	~RectanglePeterW();

	// Data From Rectangle
	FractionPeterW getArea() override;
	FractionPeterW getXDif() const;
	FractionPeterW getYDif() const;
	FractionPeterW getLLX() const;
	FractionPeterW getLLY() const;
	FractionPeterW getURX() const;
	FractionPeterW getURY() const;

	// Print Options
	friend ostream& operator<<(ostream&, const RectanglePeterW&);
	void print() override;

	// checking values
	void check(RectanglePeterW&);

	// overloading Operators
	RectanglePeterW& operator=(const RectanglePeterW&);
	RectanglePeterW operator+(const RectanglePeterW&);

private:
	PointPeterW ur;
	PointPeterW ll;
};

#endif
