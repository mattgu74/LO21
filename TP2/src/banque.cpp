#include <iostream>
#include <map>
#include "banque.h"
#include "typecompte.h"
#include "client.h"

namespace BANQUE {

	void Banque::Initialiser(std::string nom) {
		this->nom = nom;
	}

	void Banque::CreerUnTypeDeCompte(std::string nom, int soldeMin, int soldeMax, float taux) {
		TypeDeCompte *type = new TypeDeCompte(nom,soldeMin,soldeMax,taux);
		// Search if type exist in map
		if(this->typesDeCompte.find((*type).GetId()) == this->typesDeCompte.end())
		{
			// Le type n'existe pas
			this->typesDeCompte[(*type).GetId()] = *type;
		} else {
			delete type;
			std::cerr << "ERROR : Le type de compte " << nom << " existe déjà !" << std::endl;
		}
	}

	void Banque::AjouterUnClient(std::string nom,std::string prenom,int jourNaissance,int moisNaissance,int anneeNaissance)
	{
		Client *monClient = new Client(nom,prenom,jourNaissance,moisNaissance,anneeNaissance);
		// Search if client exist in map
		if(this->clients.find((*monClient).GetId()) == this->clients.end())
		{
			// Le client n'existe pas
			this->clients[(*monClient).GetId()] = *monClient;
		} else {
			delete monClient;
			std::cerr << "ERROR : Le client " << nom << " " << prenom << " existe déjà !" << std::endl;
		}
	}

	void Banque::CreerUnCompte(std::string type, std::string nomClient, std::string prenomClient, int solde)
	{
		// TODO
	}

}
