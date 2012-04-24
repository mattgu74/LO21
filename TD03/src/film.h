#ifndef FILM_H
#define FILM_H

#include <string>
#include <ostream>
#include "time.h"

using std::string;
using std::ostream;

class Film
{
public:
    Film(const string t="", const int d=0)  : titre(t), duree(d) {};
    ~Film() {};
    
	TIME::Duree getDuree() const {return duree;};
	string getTitre() const {return titre;};

	Film& setDuree(const TIME::Duree &d) {duree=d; return *this;}
	Film& setDuree(const int d) {duree=TIME::Duree(d); return *this;}

	ostream& afficher(ostream& os) const {
		os << titre << " (" << duree << ")";
		return os;
	}
    
private:
    string titre;
	TIME::Duree duree;
};

ostream& operator<<(ostream& os, const Film& f);

#endif // FILM_H

