#pragma once
#include"Compte.h"
class ComptePayant:virtual public Compte
{
private:
	float montantNonPaye;
public:
	ComptePayant(float solde);
	float getPercentage(float montant);
	void verser(float montant, float pctge=-1);
	bool retirer(float montant, float pctge=-1);
};

