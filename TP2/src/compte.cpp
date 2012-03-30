#include "compte.h"

#include <iostream>

using std::string;
using std::cerr;
using std::endl;

namespace BANQUE {

Compte::Compte() {
	this->typeDeCompte = 0;
}

Compte::Compte(TypeDeCompte & typeDeCompte, int solde) {
	this->typeDeCompte = &typeDeCompte;
	this->solde = solde;
}


string Compte::GetId() const {
	return this->typeDeCompte->GetId();
}

void Compte::SetSolde(int solde) {
	if (this->typeDeCompte->soldeOk(solde)) {
		this->solde = solde;
	}
	else {
		cerr << "opération non valide" << endl;
		throw "opération non valide";
	}
}
	

void Compte::Deposer(int amount) {
	if (amount < 0) {
		cerr << "tentative de dépose d'un montant négatif" << endl;
		throw "tentative de dépose d'un montant négatif";
	}
	else {
		this->SetSolde(this->solde + amount);
	}
}

void Compte::Retirer(int amount) {
	if (amount < 0) {
		cerr << "tentative de retirer d'un montant négatif" << endl;
		throw "tentative de retirer d'un montant positif";
	}
	else {
		this->SetSolde(this->solde - amount);
	}
}

void Compte::TransfererVers(int amount,Compte & to) {
	to.Deposer(amount);
	try {
		this->Retirer(amount);
	}
	catch (const string &s) {
		to.Retirer(amount);
		throw s;
	}
}







}
