/**
*Program Name: CIRCLE.h
*Discussion:   Circle
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/



#include "FRACTION.h";
#include "POINT.h";
#include "SHAPE.h";

using namespace std;
#ifndef CIRCLEPETERW_H
#define CIRCLEPETERW_H

class CirclePeterW : public Shape {
public:

	//base constructors and destructors
	CirclePeterW();
	CirclePeterW(const PointPeterW&, const FractionPeterW&);
	CirclePeterW(const CirclePeterW&);
	~CirclePeterW();

	// Data From Rectangle
	FractionPeterW getArea() override;
	FractionPeterW getR() const;
	PointPeterW getCenter() const;
	FractionPeterW getCenterX() const;
	FractionPeterW getCenterY() const;

	// Print Options
	friend ostream& operator<<(ostream&, const CirclePeterW&);

	// checking values
	void check(CirclePeterW&);

	// overloading Operators
	CirclePeterW& operator=(const CirclePeterW&);
	CirclePeterW& operator+(const CirclePeterW&);

private:
	PointPeterW center;
	FractionPeterW r;
};

#endif