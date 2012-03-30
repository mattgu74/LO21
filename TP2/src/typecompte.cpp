#include "typecompte.h"

#include "tools.h"


using std::string;

namespace BANQUE {

TypeDeCompte::TypeDeCompte() {}



string TypeDeCompte::GetName() const {
	return this->name;
}

string TypeDeCompte::GetId() const {
	return this->name;
}


string TypeDeCompte::nameToId(const string & s) {
	return tolower(s);
}


}


