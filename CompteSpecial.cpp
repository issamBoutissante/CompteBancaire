#include "CompteSpecial.h"
#include<string>

CompteSpecial::CompteSpecial(float solde, float taux, float pctge, float empruntMax, float decouvert)
	:CompteSimple(solde,decouvert),CompteEpargne(taux,solde),ComptePayant(solde),Compte(solde) {
	this->pctge = pctge;
	this->empruntMax = empruntMax;
	this->emprunt = 0;
}
void CompteSpecial::verser(float montant, TypeVersement typeVersement) {
	if (typeVersement == TypeVersement::Simple) {
		if (this->emprunt == 0)
			CompteSimple::verser(montant);
		else
		{
			if (this->emprunt > montant)
				this->emprunt -= montant;
			else {
				float rest = montant - this->emprunt;
				this->emprunt = 0;
				CompteSimple::verser(rest);
			}
		}
	}
	else 
		ComptePayant::verser(montant, this->pctge*montant);
}
bool CompteSpecial::retirer(float montant, Emprunt emprunt) {
	if (CompteSimple::retirer(montant)) return true;
	if (emprunt == Emprunt::Oui) { 
		float empVoulue = montant - (this->solde + this->decouvert); 
		if (empVoulue > this->empruntMax)return false;
		this->solde += empVoulue; 
		this->emprunt +=(empVoulue+ empVoulue*0.07); 
		CompteSimple::retirer(montant);
		return true;
	}
	return false;
}
bool CompteSpecial::retirer(float montant) {
	return ComptePayant::retirer(montant, this->pctge*montant);
}
string CompteSpecial::toString() {
	return CompteSimple::toString() + "\n" +
		"- Emprunte : " + to_string(this->emprunt) + "\n";
		"- Percentage : " + to_string(this->pctge) + "\n";
		"- Emprunte Max : " + to_string(this->empruntMax)+"\n";
}