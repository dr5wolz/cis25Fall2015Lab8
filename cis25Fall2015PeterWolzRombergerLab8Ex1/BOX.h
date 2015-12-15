/**
*Program Name: BOX.h
*Discussion:   Cylinder
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/



#include "FRACTION.h";
#include "POINT.h";
#include "SHAPE.h";
#include "RECTANGLE.h";

using namespace std;
#ifndef BOXPETERW_H
#define BOXPETERW_H

class BoxPeterW : public Shape, public RectanglePeterW, virtual FractionPeterW {
public:

	//base constructors and destructors
	BoxPeterW();
	BoxPeterW(const RectanglePeterW&, const FractionPeterW&);
	BoxPeterW(const BoxPeterW&);
	~BoxPeterW();

	// Data From Rectangle
	FractionPeterW getArea() override;
	FractionPeterW getVolume() override;

	// Print Options
	friend ostream& operator<<(ostream&, const BoxPeterW&);
	void print() override;

	// checking values
	void check(BoxPeterW&);

	// overloading Operators
	BoxPeterW& operator=(const BoxPeterW&);
	BoxPeterW& operator+(const BoxPeterW&);

private:
	RectanglePeterW base;
	FractionPeterW height;
};

#endif