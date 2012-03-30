#include "compte.h"

using std::string;

namespace BANQUE {

Compte::Compte() {
	this->typeDeCompte = 0;
}

Compte::Compte(TypeDeCompte * typeDeCompte, int solde) {
	this->typeDeCompte = typeDeCompte;
	this->solde = solde;
}


string Compte::GetId() const {
	return this->typeDeCompte->GetId();
}









}
