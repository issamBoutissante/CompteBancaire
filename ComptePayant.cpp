#include "ComptePayant.h"

ComptePayant::ComptePayant(float solde) :Compte(solde) {
	this->montantNonPaye = 0;
}
float ComptePayant::getPercentage(float montant) {
	return montant < 30000 ? montant * 0.05 : montant * 0.07;
}
void ComptePayant::verser(float montant, float pctge) {
	float percentage = pctge == -1 ? this->getPercentage(montant) : pctge;
	Compte::verser(montant - percentage);
	if (this->solde > this->montantNonPaye) {
		this->solde -= this->montantNonPaye;
		this->montantNonPaye = 0;
	}
}
bool ComptePayant::retirer(float montant,float pctge) {
	float percentage = pctge == -1 ? this->getPercentage(montant) : pctge;
	if (!Compte::retirer(montant))return false;
	if (this->solde > percentage)
		this->solde -= percentage;
	else {
		this->montantNonPaye += percentage-this->solde;
		this->solde = 0;
	}
	return true;
}