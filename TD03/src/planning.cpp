#include "planning.h"

ostream& operator<<(ostream& os, const Planning& planning) {
	return planning.afficher(os);
}


bool Planning::addProgrammation(Programmation& prog) {
	Programmation *p = new Programmation(prog);
	
	if (programmations.empty()) {
		programmations.push_back(p);
	}
	else {
		Programmations::iterator it;
		for (it=programmations.begin(); it!=programmations.end(); ++it) {
			if (prog.getIntervalle().GetDebut() < (*it)->getIntervalle().GetDebut()) {
				break;
			}
		}

		// intersection
		if ((*it)->getIntervalle() && prog.getIntervalle()) {
			return false;
		}

		if (it != programmations.begin()) {

			--it;
			
			// intersection
			if ((*it)->getIntervalle() && prog.getIntervalle()) {
				return false;
			}
		}

		programmations.insert(it, p);
		
	}
}

bool Planning::operator<<(Programmation prog) {
	return addProgrammation(prog);
}



