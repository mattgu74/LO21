#include "typecompte.h"

#include "tools.h"


using std::string;

namespace BANQUE {

TypeDeCompte::TypeDeCompte(std::string name, int min, int max, float taux) {
	this->name = tolower(name);
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

string TypeDeCompte::nameToId(const string & s) {
	return tolower(s);
}

bool TypeDeCompte::soldeOk(const int solde) const {
	return (this->soldeMin <= solde) and (solde <= this->soldeMax);
}


}


