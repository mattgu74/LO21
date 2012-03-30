#ifndef TYPE_COMPTE_H
#define TYPE_COMPTE_H


#include <string>

namespace BANQUE  {

class TypeDeCompte
{
	public:
		TypeDeCompte();
		std::string & GetName() const;

	private:
		std::string name;

};

}


#endif
