#include "banque.h"
#include "typecompte.h"

namespace BANQUE {

	void Banque::Initialiser(std::string nom) {
		this->nom = nom;
	}

	void Banque::CreerUnTypeDeCompte(std::string nom, int soldeMin, int soldeMax, float taux) {
		//TypeDeCompte type;
		//type = new TypeDeCompte()
	}

	void Banque::AjouterUnClient(std::string nom,std::string prenom,int jourNaissance,int moisNaissance,int anneeNaissance)
	{
		// todo
	}

	void Banque::CreerUnCompte(std::string type, std::string nomClient, std::string prenomClient, int solde)
	{
		// TODO
	}

}
