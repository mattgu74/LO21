#include "film.h"


ostream& operator<<(ostream& os, const Film& f) {
	return f.afficher(os);
}

