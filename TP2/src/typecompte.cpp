#include "typecompte.h"

#include "tools.h"


using std::string;

namespace BANQUE {

TypeDeCompte::TypeDeCompte(std::string name, int min, int max, float taux) {
	this->name = toupper(name);
	this->soldeMin = min;
	this->soldeMax = max;
	this->taux = taux;
}



string TypeDeCompte::GetName() const {
	return this->name;
}

string TypeDeCompte::GetId() const {
	return this->name;
}

float TypeDeCompte::GetTaux() const {
	return this->taux;
}

int TypeDeCompte::GetSoldeMin() const {
	return this->soldeMin;
}

int TypeDeCompte::GetSoldeMax() const {
	return this->soldeMax;
}

string TypeDeCompte::nameToId(const string & s) {
	return toupper(s);
}

bool TypeDeCompte::soldeOk(const int solde) const {
	return (this->soldeMin <= solde) and (solde <= this->soldeMax);
}


}


