#ifndef TYPE_COMPTE_H
#define TYPE_COMPTE_H


#include <string>

namespace BANQUE  {

class TypeDeCompte
{
	public:
		TypeDeCompte();
		
		static std::string nameToId(const std::string & s);
		std::string GetId() const;
		std::string GetName() const;

	private:
		std::string name;

};

}


#endif
