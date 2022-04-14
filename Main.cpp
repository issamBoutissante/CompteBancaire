#include <iostream>
#include"CompteSimple.h"
#include"CompteSpecial.h"
using namespace std;

int main()
{
	CompteSpecial c(10000,0.5,0.1,30000,1000);
	cout << c.toString() << endl;
	c.retirer(1000);
	cout << c.toString() << endl;
	c.verser(1000, CompteSpecial::TypeVersement::Payant);
	cout << c.toString() << endl;
	return 200;
}