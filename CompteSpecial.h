#pragma once
#include"CompteEpargne.h"
#include"ComptePayant.h"
#include"CompteSimple.h"
class CompteSpecial:public CompteSimple,public CompteEpargne,public ComptePayant
{
private:
	float pctge;
	float emprunt;
	float empruntMax;
public:
	// pour client Choisir s’il veut un découvert de plus ou non
	enum Emprunt {
		Oui, Non
	};
	// Parce que on a de method verser Chacune avec sa propre logic
	// pour ca je veux donner la main a l'utilisateur pour choisir
	enum TypeVersement {
		Simple, Payant
	};
public:
	CompteSpecial(float solde, float taux,float pctge, float empruntMax,float decouvert);
	void verser(float montant, TypeVersement typeVersement);
	/// <summary>
	/// Pour Retirer De CompteSimple
	/// </summary>
	/// <param name="montant"></param>
	/// <param name="emprunt"></param>
	/// <returns></returns>
	bool retirer(float montant, Emprunt emprunt);
	/// <summary>
	/// Pour Retirer De ComptePayant
	/// </summary>
	/// <param name="montant"></param>
	/// <returns></returns>
	bool retirer(float montant);
	string toString();
};