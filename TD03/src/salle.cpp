#include "salle.h"

unsigned int Salle::_id = 0;

ostream& operator<<(ostream& os, const Salle& salle) {
	return salle.afficher(os);
}

