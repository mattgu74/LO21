#ifndef SALLE_H
#define SALLE_H


#include "planning.h"

class Salle
{
public:
	Salle() : id(_id++) {};
	Planning& getPlanning() {return planning;};
	const Planning& getPlanning() const {return planning;};

	ostream& afficher(ostream& os) const {
		os << planning;
		return os;
	}
	
private:
	static unsigned int _id;
	unsigned int id;
	Planning planning;
};

ostream& operator<<(ostream& os, const Salle& salle);

#endif // SALLE_H
