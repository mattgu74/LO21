#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <ctime>
#include <map>

#include "compte.h"
#include "typecompte.h"

namespace BANQUE {

class Client
{
	public:
		Client();

		/**
		 * @param {const string&} nom
		 * @param {const string&} prenom
		 * @param {int} jour
		 * @param {int} moi
		 * @param {int} annee
		 */
		Client(const std::string & nom, const std::string & prenom, int jour, int moi, int annee);

		/**
		 * Récupérer un id de client à partir de son nom + prenom
		 * @param {const string&} nom
		 * @param {const string&} prenom
		 */
		static std::string nomPrenomToId(const std::string & nom, const std::string & prenom);
		std::string getId(const std::string & nom, const std::string & prenom) const;
		
		/**
		 * @param {TypeDeCompte*} typeDeCompte
		 * @param {int} soldeInitial (default=0)
		 */
		void creerCompte(TypeDeCompte * typeDeCompte, int soldeInitial=0);

	private:
		std::string nom, prenom;
		std::time_t dateDeNaissance;
		std::map<std::string, Compte> comptes;
		

};

}

#endif
