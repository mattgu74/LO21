#ifndef BANQUE_H
#define BANQUE_H


#include <map>
#include <vector>
#include <string>


#include "client.h"
#include "typecompte.h"
#include "compte.h"



namespace BANQUE {

class Banque
{
	public:
		void Initialiser(std::string);
		void CreerUnTypeDeCompte(std::string,int, int, float);
		void AjouterUnClient(std::string, std::string,int, int, int);
		void CreerUnCompte(std::string, std::string, std::string, int);
		// & Compte GetCompte(std::string,std::string,std::string);



	private:
		std::string nom;
		std::map<std::string, TypeDeCompte> typesDeCompte;
		std::map<std::string, Client> clients;
};

}


#endif
