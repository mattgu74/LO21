#ifndef PLANNING_H
#define PLANNING_H

#include <iostream>
#include <list>

using std::list;
using std::endl;

#include "programmation.h"

typedef std::list<Programmation*> Programmations;

class Planning
{
    
	public:
		typedef Programmations::iterator iterator;
		typedef Programmations::const_iterator const_iterator;
		
		Planning() {};
		Planning(const Planning& p) {programmations = p.programmations;};
		Planning& operator=(const Planning& p) {programmations = p.programmations;};
		
		bool addProgrammation(Programmation& prog);
		bool operator<<(Programmation prog);

		ostream& afficher(ostream& os) const {
			for (Programmations::const_iterator it = programmations.begin();
				it != programmations.end(); ++it) {
					os << " * " << (*it) << endl;
			}
			return os;
		}

		iterator begin() { return programmations.begin(); }

		const_iterator begin() const { return programmations.begin(); }

		iterator end() { return programmations.end(); }

		const_iterator end() const { return programmations.end(); }

	private:
		Programmations programmations;

};


ostream& operator<<(ostream& os, const Planning& planning);

#endif


