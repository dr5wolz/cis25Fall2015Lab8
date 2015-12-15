/**
*Program Name: POINT.h
*Discussion:   Points
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/

#ifndef POINTPETERW_H
#define POINTPETERW_H

class PointPeterW : public FractionPeterW {
public:

	//default constructor
	PointPeterW();

	//copy constructor
	PointPeterW(const PointPeterW&);

	//default destructor
	~PointPeterW();

	// full constructor
	PointPeterW(const FractionPeterW&, const FractionPeterW&);

	// base funtions for getting and setting data
	FractionPeterW getX(void) const;
	FractionPeterW getY(void) const;
	void setX(const FractionPeterW&);
	void setY(const FractionPeterW&);

	// movement of point
	void moveBy(const FractionPeterW&, const FractionPeterW&);
	void moveBy(const int&);
	void moveBy(const FractionPeterW&);

	// flipping of point
	void flipByX();
	void flipByY();
	void flipThoughOrigin();

	// print options
	void print();

	// operators
	friend ostream& operator<<(ostream&, const PointPeterW&);
	//PointPeterW operator+=(const PointPeterW&);
	//PointPeterW operator-=(const PointPeterW&);
	//PointPeterW operator=(const PointPeterW&);
	//PointPeterW operator+(const PointPeterW&);
	//PointPeterW operator-(const PointPeterW&);
	//PointPeterW& operator*(const PointPeterW&);
	//PointPeterW operator/(const PointPeterW&);

private:
	FractionPeterW x;
	FractionPeterW y;
};


#endif