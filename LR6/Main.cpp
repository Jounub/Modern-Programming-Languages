#include "Stroka.h"
#include <iostream>

using namespace std;

int main()
{
	Stroka s1("qwert"), s3, s4(s1), s5;
	s3.vvod();
	cout << "s3 = ";
	s3.vyvod();
	s3 = "asdfg";
	cout << "s3 = "; 
	s3.vyvod();

	cout << "s1 = ";
	s1.vyvod();

	cout << "s4 = ";
	s4.vyvod();

	s5 = s1 + s3 + s4;
	cout << "s5 length = " << s5.dlina() << endl;
	s5.vyvod();
	if (s1 == s5)
		cout << "Strings s1 and s5 are equal" << endl;
	else
		if (s1 == s4)
			cout << "Strings s1 and s4 are equal" << endl;
    return 0;
}
