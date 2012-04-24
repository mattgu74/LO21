#ifndef CINEMA_H
#define CINEMA_H

#include <string>
#include <vector>

#include "salle.h"

using std::string;
using std::vector;


class Cinema
{
	typedef std::vector<Salle> Salles;
public:
    Cinema(const string& s, unsigned int i=0) : name(s), salles(Salles(i)) {};

    Salle& operator[](unsigned int i) { return salles[i]; };
    const Salle& operator[](unsigned int i) const { return salles[i]; }

    ostream& afficher(ostream& os) const {
		for (Salles::const_iterator it=salles.begin();
			it != salles.end(); ++it) {
			os << (*it) << endl;
		}
		return os;
	}

private:
    string name;
    Salles salles;
};


ostream& operator<<(ostream& os, const Cinema& cine);

#endif // CINEMA_H
