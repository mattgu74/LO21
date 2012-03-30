#ifndef COMPTE_H
#define COMPTE_H

#include <string>

#include "typecompte.h"

namespace BANQUE
{

class Compte
{
	public:
		Compte();
		Compte(TypeDeCompte & typeDeCompte, int solde=0);

		std::string GetId() const;
		void Deposer(int);
		void Retirer(int);
		void TransfererVers(int,Compte &);

	private:
		TypeDeCompte * typeDeCompte;
		int solde;
};

}


#endif
