/**
*Program Name: SHAPE.h
*Discussion:   Shapes
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/



#include "FRACTION.h";
#include "POINT.h";
using namespace std;
#ifndef SHAPEPETERW_H
#define SHAPEPETERW_H

class Shape : public FractionPeterW {
public:
	virtual FractionPeterW getVolume() {
		return FractionPeterW(0, 1);
	}

	virtual FractionPeterW getArea() = 0;
};

#endif
