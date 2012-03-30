#include "compte.h"

#include <iostream>
#include <sstream>

using std::string;
using std::cerr;
using std::endl;
using std::stringstream;
using std::ostringstream;


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
		stringstream stream;
		stream << "depot " << amount;
		this->historique.push_back(stream.str());
	}
}

void Compte::Retirer(int amount) {
	if (amount < 0) {
		cerr << "tentative de retirer d'un montant négatif" << endl;
		throw "tentative de retirer d'un montant positif";
	}
	else {
		this->SetSolde(this->solde - amount);
		stringstream stream;
		stream << "retrait " << amount;
		this->historique.push_back(stream.str());
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
	stringstream stream;
	stream << "transfert " << amount << " vers " << to.GetId();
	this->historique.push_back(stream.str());
	stream.clear();
	stream << "reception transfert " << amount << " de " << this->GetId();
	to.historique.push_back(stream.str());
}

/*
OMPTE NUM 0
PROPRIETAIRE :Clement Fouque (30/06/1987)
compte CODEVI remunere au taux de 1.250000 %
PLAFOND :6000.000000 SOLDE MINIMUM AUTORISE :50.000000
SOLDE ACTUEL :600.000000
HISTORIQUE :
15/03/2010 -- reception transfert 200.00 du compte CHEQUE 1
15/03/2010 --
creation 400.00
*/


string Compte::str() const {
	ostringstream stream;

	stream << "Compte" << this->typeDeCompte->GetName() << "remunere au taux de " << this->typeDeCompte->GetTaux() << "%" << endl;
	stream << "Plafond de " << this->typeDeCompte->GetSoldeMax() << "  Solde minimum autorise : " << this->typeDeCompte->GetSoldeMin() << endl;
	stream << "Historique :" << endl << "todo thomas historique" << endl;
	return stream.str();
}




}
