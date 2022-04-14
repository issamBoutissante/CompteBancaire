#pragma once
#include<iostream>
using namespace std;
class Compte
{
private:
	int code;
	static int nbComptes;
protected:
	float solde;
public:
	Compte(float solde);
	void verser(float montant);
	bool retirer(float montant);
	string toString();
};
