#pragma once
#include"Compte.h"
class CompteEpargne:virtual public Compte
{
private:
	float tauxInteret;
public:
	CompteEpargne(float solde, float tauxInteret);
	void calculerInteret();
	string toString();
};

