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
		//TypeDeCompte type;
		//type = new TypeDeCompte()
	}

	void Banque::AjouterUnClient(std::string nom,std::string prenom,int jourNaissance,int moisNaissance,int anneeNaissance)
	{
		/*Client *monClient = new Client(nom,prenom,jourNaissance,moisNaissance,anneeNaissance);
		// Search if client exist in map
		if(this->clients.find((*monClient).GetId()) == this->clients.end())
		{
			// Le client n'existe pas
			this->clients[(*monClient).GetId()] = monClient;
		} else {
			delete monClient;
			std::cerr << "ERROR : Le client " << nom << " " << prenom << " existe déjà !" << std::endl;
		}*/
	}

	void Banque::CreerUnCompte(std::string type, std::string nomClient, std::string prenomClient, int solde)
	{
		// TODO
	}

}
