#include "programmation.h"



ostream& operator<<(ostream& os, const Programmation& prog) {
	return prog.afficher(os);;
}

