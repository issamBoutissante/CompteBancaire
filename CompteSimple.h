#pragma once
#include "Compte.h"
class CompteSimple:virtual public Compte
{
protected:
	float decouvert;
	float decouvertInitial;
public:
	CompteSimple(float solde, float decouvert);
	void verser(float montant);
	bool retirer(float montant);
	string toString();
};

