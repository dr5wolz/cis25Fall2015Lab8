/**
*Program Name: FRACTION.h
*Discussion:   Fractions header
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/10
*/

using namespace std;
#ifndef FRACTIONPETERW_H
#define FRACTIONPETERW_H
#include <iostream>

//class FractionPeterW;

class FractionPeterW {
public:
	FractionPeterW();
	FractionPeterW(int);
	FractionPeterW(const FractionPeterW&);
	void print();
	FractionPeterW(int, int);
	void setNum(int);
	int getDenom(void) const;
	void setDenom(int);
	int getNum(void) const;
	~FractionPeterW();
	friend ostream& operator<<(ostream&, const FractionPeterW&);
	void reduce(void);

	FractionPeterW& operator=(const FractionPeterW&);
	FractionPeterW operator+(const FractionPeterW&);
	FractionPeterW operator-(const FractionPeterW&);
	FractionPeterW operator*(const FractionPeterW&);
	FractionPeterW operator/(const FractionPeterW&);
	bool operator==(const FractionPeterW&);
	//FractionPeterW& operator+=(const FractionPeterW&);
	//FractionPeterW& operator-=(const FractionPeterW&);
	//FractionPeterW& operator-=(const int&);
	//FractionPeterW& operator+=(const int&);
	friend FractionPeterW& operator-(FractionPeterW&);
	FractionPeterW& operator-();
	bool operator>(const FractionPeterW&);


	FractionPeterW add(const FractionPeterW&);
	FractionPeterW subtract(const FractionPeterW&);
	FractionPeterW multiply(const FractionPeterW&);
	FractionPeterW divide(const FractionPeterW&);

private:
	int num;
	int denom;
};

#endif
