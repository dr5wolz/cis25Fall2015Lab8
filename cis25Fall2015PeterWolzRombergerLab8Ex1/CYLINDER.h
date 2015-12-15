/**
*Program Name: CYLINDER.h
*Discussion:   Cylinder
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/



#include "FRACTION.h";
#include "POINT.h";
#include "SHAPE.h";
#include "CIRCLE.h";

using namespace std;
#ifndef CYLINDERPETERW_H
#define CYLINDERPETERW_H

class CylinderPeterW : public Shape,  public CirclePeterW, virtual FractionPeterW {
public:

	//base constructors and destructors
	CylinderPeterW();
	CylinderPeterW(const CirclePeterW&, const FractionPeterW&);
	CylinderPeterW(const CylinderPeterW&);
	~CylinderPeterW();

	// Data From Rectangle
	FractionPeterW getArea() override;
	FractionPeterW getVolume() override;

	// Print Options
	friend ostream& operator<<(ostream&, const CylinderPeterW&);
	void print() override;

	// checking values
	void check(CylinderPeterW&);

	// overloading Operators
	CylinderPeterW& operator=(const CylinderPeterW&);
	CylinderPeterW& operator+(const CylinderPeterW&);

private:
	CirclePeterW base;
	FractionPeterW height;
};

#endif