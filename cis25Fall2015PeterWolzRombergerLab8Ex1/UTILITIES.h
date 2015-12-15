/**
*Program Name:	UTILITIES.h
*Discussion:	Shapes
*Writen by:		Peter Wolz-Romberger
*Date:			2015/12/15
*/

#include <iostream>
using namespace std;
#include "FRACTION.H"
#include "POINT.H"
#include "SHAPE.h"
#include "RECTANGLE.h"
#include "CIRCLE.h"
#include "BOX.h"
#include "CYLINDER.h"

#ifndef UTILITIES_H
#define UTILITIES_H

void displayClassInfoPeterWolzRomberger(void);
int rectangleMenu(RectanglePeterW**, RectanglePeterW**);
int circleMenu(CirclePeterW**, CirclePeterW**);
void mixedMenu(RectanglePeterW*, RectanglePeterW*, CirclePeterW*, CirclePeterW*);
void initialize(RectanglePeterW**);
void initialize(CirclePeterW**);
void initialize(BoxPeterW**);
void initialize(CylinderPeterW**);

#endif
