#include <iostream>
#include <map>
#include <string>
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
			this->typesDeCompte.insert ( std::pair<std::string,TypeDeCompte>((*type).GetId(),*type) );
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
			this->clients.insert ( std::pair<std::string,Client>((*monClient).GetId(),*monClient) );
		} else {
			delete monClient;
			std::cerr << "ERROR : Le client " << nom << " " << prenom << " existe déjà !" << std::endl;
		}
	}

	void Banque::CreerUnCompte(std::string type, std::string nomClient, std::string prenomClient, int solde)
	{
		// Search if client and type de compte exist
		std::map<std::string,Client>::iterator it_client = this->clients.find(Client::nomPrenomToId(nomClient, prenomClient));
		std::map<std::string,TypeDeCompte>::iterator it_typeCompte = this->typesDeCompte.find(TypeDeCompte::nameToId(type));
		if(it_client != this->clients.end()
				&& it_typeCompte != this->typesDeCompte.end())
		{
			it_client->second.CreerCompte(it_typeCompte->second, solde);
		} else {
			std::cerr << "ERROR : Le client ou le type de compte n'existe pas... Impossible de créer un compte." << std::endl;
		}
	}

	Compte & Banque::GetCompte(std::string type, std::string nomClient, std::string prenomClient)
	{
		// Search if client and type de compte exist
		std::map<std::string,Client>::iterator it_client = this->clients.find(Client::nomPrenomToId(nomClient, prenomClient));
		std::map<std::string,TypeDeCompte>::iterator it_typeCompte = this->typesDeCompte.find(TypeDeCompte::nameToId(type));
		if(it_client != this->clients.end()
				&& it_typeCompte != this->typesDeCompte.end())
		{
			it_client->second.GetCompte(it_typeCompte->second);
		} else {
			std::cerr << "ERROR : Le client ou le type de compte n'existe pas... Impossible d'obtenir le compte" << std::endl;
			throw "error impossible d'obtenir le compte";
		}
	}

	void Banque::Afficher()
	{
		std::cout << "TODO :: AFFICHAGE !! " << std::endl;
	}

}
