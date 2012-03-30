#ifndef TYPE_COMPTE_H
#define TYPE_COMPTE_H


#include <string>

namespace BANQUE  {

class TypeDeCompte
{
	public:
		TypeDeCompte(std::string, int, int, float);
		
		static std::string nameToId(const std::string & s);
		std::string GetId() const;
		std::string GetName() const;

		bool soldeOk(const int solde) const;

	private:
		std::string name;
		int soldeMin;
		int soldeMax;
		float taux;

};

}


#endif
