#include "Compte.h"
#include<string>

int Compte::nbComptes = 0;
Compte::Compte(float solde) {
	this->solde = solde;
	this->code = ++nbComptes;
}
void Compte::verser(float montant) {
	this->solde += montant;
}
bool Compte::retirer(float montant) {
	if (montant > this->solde)
		return false;
    this->solde -= montant;
	return true;
}
string Compte::toString() {
	return "- Code : " + to_string(this->code) + "\n"+
	"- Solde : " + to_string(this->solde) + "\n"+
	"- Nombre Comptes : " + to_string(this->nbComptes)+"\n";
}