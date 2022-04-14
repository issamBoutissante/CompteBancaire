#include "CompteEpargne.h"
#include<string>
CompteEpargne::CompteEpargne(float solde,float tauxInteret)
	:Compte(solde) {
	this->tauxInteret = tauxInteret;
}
void CompteEpargne::calculerInteret() { this->solde += (this->solde * this->tauxInteret); }
string CompteEpargne::toString() {
	return Compte::toString() +
		"- Taux : " + to_string(this->tauxInteret)+"\n";
}