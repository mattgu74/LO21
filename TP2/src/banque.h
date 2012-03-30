#ifndef BANQUE_H
#define BANQUE_H


#include <map>
#include <vector>
#include <string>


#include "client.h"
#include "typecompte.h"



namespace BANQUE {

class Banque
{
	public:
		Banque(std::string nom);

	private:
		std::string nom;
		std::map<std::string, TypeDeCompte> typesDeCompte;
		std::map<std::string, Client> clients;
};

}


#endif
