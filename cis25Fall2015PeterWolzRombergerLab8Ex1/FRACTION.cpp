/**
*Program Name: Fraction.cpp
*Discussion:   Fractions
*Writen by:    Peter Wolz-Romberger
*Date:         2015/12/15
*/

#include "FRACTION.h"
#include <iostream>
using namespace std;


FractionPeterW::FractionPeterW() : num(0), denom(1) {
	cout << "calling Fraction()\n";
}

FractionPeterW::FractionPeterW(int n) : num(n), denom(1) {
	cout << "calling Fraction()\n";
}

FractionPeterW::FractionPeterW(const FractionPeterW &n) : num(n.num), denom(n.denom) {
	(*this).reduce();
	cout << "calling Fraction()\n";
}

FractionPeterW::FractionPeterW(int n, int d) : num(n), denom(d) {
	(*this).reduce();
	cout << "calling Fraction()\n";
}

void FractionPeterW::print() {
	cout << num << " / " << denom;
}

void FractionPeterW::setDenom(int d) {
	denom = d;
	(*this).reduce();
}

void FractionPeterW::setNum(int n) {
	num = n;
	(*this).reduce();
}

int FractionPeterW::getDenom() const {
	return denom;
}

int FractionPeterW::getNum() const {
	return num;
}

FractionPeterW::~FractionPeterW() {
	cout << "calling ~Fraction()\n";
}

void FractionPeterW::reduce() {
	int i;
	for (i = 2; i <= denom; i++) {
		if (denom % i == 0) {
			if (num % i == 0) {
				num /= i;
				denom /= i;
				i--;
			}
		}
	}

	if (denom < 0) {
		denom = -denom;
		num = -num;
	}
	if (denom == 0) {
		cout << "DENOMINATOR CANNOT BE 0! DENOMINATOR SET TO 1!";
		denom = 1;
	}
}

ostream& operator<<(ostream& out, const FractionPeterW& in) {
	out << in.num << " / " << in.denom;
	return out;
}

FractionPeterW FractionPeterW::operator-(const FractionPeterW& in) {
	return FractionPeterW((num*in.denom - in.num*denom), (denom*in.denom));
}

FractionPeterW FractionPeterW::operator+(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom + in.num*denom, in.denom*denom);
}

FractionPeterW FractionPeterW::operator*(const FractionPeterW& in) {
	return FractionPeterW(num*in.num, denom*in.denom);
}

FractionPeterW FractionPeterW::operator/(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom, denom*in.num);
}

FractionPeterW& FractionPeterW::operator=(const FractionPeterW& in) {
	num = in.num;
	denom = in.denom;
	return FractionPeterW(in.num, in.denom);
}

FractionPeterW FractionPeterW::add(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom + in.num*denom, in.denom*denom);
}

FractionPeterW FractionPeterW::subtract(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom - in.num*denom, denom*in.denom);
}

FractionPeterW FractionPeterW::divide(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom, denom*in.num);
}

FractionPeterW FractionPeterW::multiply(const FractionPeterW& in) {
	return FractionPeterW(num*in.num, denom*in.denom);
}

bool FractionPeterW::operator>(const FractionPeterW& in) {
	if ((num * in.denom) > (in.num * denom)) {
		return true;
	}

	return false;
}

bool FractionPeterW::operator==(const FractionPeterW& in) {
	if (num == in.num && denom == in.denom) {
		return true;
	}

	return false;
}
