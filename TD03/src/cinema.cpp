#include "cinema.h"


ostream& operator<<(ostream& os, const Cinema& cine) {
	return cine.afficher(os);
}


