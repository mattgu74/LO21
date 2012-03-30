#include "client.h"

#include <iostream>
#include <sstream>

#include "tools.h"

using std::string;
using std::cerr;
using std::cout;
using std::endl;
using std::map;
using std::ostringstream;


namespace BANQUE {


Client::Client() {}

Client::Client(const std::string & nom, const std::string & prenom, int jour, int moi, int annee) {
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = annee - 1900;
	timeinfo->tm_mon = moi - 1;
	timeinfo->tm_mday = jour;

	this->dateDeNaissance = mktime ( timeinfo );
	if (this->dateDeNaissance < 0) {
		cerr << "Date de naissance non valide" << endl;
		throw "Date de naissance non valide";
	}

	this->nom = nom;
	this->prenom = prenom;
	firstUpper(this->nom);
	firstUpper(this->prenom);
	
}


string Client::nomPrenomToId(const string & nom, const string & prenom) {
	return firstUpper(nom) + firstUpper(prenom);
}

string Client::GetId() const {
	return Client::nomPrenomToId(this->nom, this->prenom);
}

void Client::CreerCompte(TypeDeCompte & typeDeCompte, int soldeInitial) {
	if (this->TypeDeCompteExist(typeDeCompte)) {
		cerr << "le type de compte existe déjà" << endl;
	}
	else {
		Compte compte(typeDeCompte, soldeInitial);
		this->comptes[compte.GetId()] = compte;
	}
}


bool Client::TypeDeCompteExist(const TypeDeCompte & typeDeCompte) {
	return this->TypeDeCompteExist(typeDeCompte.GetId());
}

bool Client::TypeDeCompteExist(const string & id_typeDeCompte) {
	return (this->GetCompte(id_typeDeCompte) != 0);
}

Compte * Client::GetCompte(const string & id_typeDeCompte) {
	map<string,Compte>::iterator it = this->comptes.find(id_typeDeCompte);
	if (it == this->comptes.end()) {
		return 0;
	}
	else {
		return &(it->second);
	}
}

Compte * Client::GetCompte(const TypeDeCompte & typeDeCompte) {
	return this->GetCompte(typeDeCompte.GetId());
}

string Client::str() const {
    ostringstream stream;
	struct tm * timeinfo = localtime ( &(this->dateDeNaissance) );
	char * buffer = new char[80];
	
	strftime (buffer,80,"(%d/%M/%Y)",timeinfo);
	
	stream << this->prenom << " " << this->nom << " " << buffer;
	
	return stream.str();
}






}
