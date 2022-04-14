#include "CompteSimple.h"
#include<string>
CompteSimple::CompteSimple(float solde,float decouvert)
	:Compte(solde) {
	this->decouvertInitial=this->decouvert = decouvert;
}
void CompteSimple::verser(float montant) {
	float marge = (this->decouvertInitial - this->decouvert);
	if (marge>0) {
		if (marge >= montant) {
			this->decouvert += montant;
		}
		else {
			this->decouvert = decouvertInitial;
			this->solde=montant - marge;
		}
	}
	else
		this->solde += montant;
}
bool CompteSimple::retirer(float montant) {
	if (Compte::retirer(montant)) return true;
	if (montant > (this->solde + this->decouvert)) return false;
	this->decouvert -= (montant - this->solde);
	this->solde = 0;
	return true;
}
string CompteSimple::toString() {
	return Compte::toString() + "\n" +
		"- Decouvert : " + to_string(this->decouvert) + "\n";
}