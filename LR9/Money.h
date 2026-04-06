#pragma once
#include <iostream>;
using namespace std;
class Money
{
	long dollars;
	int cents;

	public:
	Money(){}
	Money(long d, int c) 
	{
		dollars = d;
		cents = c;
	}

	int operator>(const Money& m) const;
	friend ostream& operator<<(ostream&, const Money&);
};

