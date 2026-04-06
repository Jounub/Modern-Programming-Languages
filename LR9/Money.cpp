#include "Money.h"

int Money::operator>(const Money& amt) const
{
	return
		(dollars > amt.dollars) ||
		((dollars == amt.dollars) && (cents > amt.cents));
}

ostream& operator<<(ostream& os, const Money &amt)
{
	os << "$" << amt.dollars << '.' << amt.cents;
	return os;
}
