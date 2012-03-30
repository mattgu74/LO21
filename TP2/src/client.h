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
		 * stringifier
		 * @return {string}
		 */
		std::string str() const;
		
		std::string str_comptes() const;
		
		/**
		 * Récupérer un id de client à partir de son nom + prenom
		 * @param {const string&} nom
		 * @param {const string&} prenom
		 * @return {string} id
		 */
		static std::string nomPrenomToId(const std::string & nom, const std::string & prenom);
		/**
		 * Récupérer l'id du client
		 * @return {string} id
		 */
		std::string GetId() const;
		
		/**
		 * @param {TypeDeCompte*} typeDeCompte
		 * @param {int} soldeInitial (default=0)
		 */
		void CreerCompte(TypeDeCompte & typeDeCompte, int soldeInitial=0);

		/**
		 * est ce que le client a déjà un compte de ce type ?
		 * @param {const string &} id_typeDeCompte
		 * @return {bool}
		 */
		bool TypeDeCompteExist(const std::string & id_typeDeCompte);
		/**
		 * est ce que le client a déjà un compte de ce type ?
		 * @param {const TypeDeCompte &} typeDeCompte
		 * @return {bool}
		 */
		bool TypeDeCompteExist(const TypeDeCompte & typeDeCompte);

		
		Compte * GetCompte(const std::string & id_typeDeCompte);
		Compte * GetCompte(const TypeDeCompte & typeDeCompte);

	private:
		std::string nom, prenom;
		std::time_t dateDeNaissance;
		std::map<std::string, Compte> comptes;
		

};

}

#endif
