#include "client.h"

#include "tools.h"

using std::string;


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
		throw "Date de naissance non valide";
	}

	this->nom = nom;
	this->prenom = prenom;
	firstUpper(this->nom);
	firstUpper(this->prenom);
	
}


string Client::nomPrenomToId(const string & nom, const string & prenom) {
	return nom + prenom;
}

string Client::GetId(const string & nom, const string & prenom) const {
	return Client::nomPrenomToId(nom, prenom);
}













}
