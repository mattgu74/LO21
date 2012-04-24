#ifndef PROGRAMMATION_H
#define PROGRAMMATION_H

#include "time.h"
#include "film.h"

class Programmation
{
public:
	Programmation(const Film& film, const TIME::Date& d, const TIME::Date& f) : film(film), intervalle(d,f) {};
	Programmation(const Programmation& prog) : film(prog.film), intervalle(prog.intervalle) {};

	const TIME::Intervalle& getIntervalle() {return intervalle;};

	ostream& afficher(ostream& os) const {
		os << intervalle << " " << film;
		return os;
	}
	
private:
	const Film& film;
	TIME::Intervalle intervalle;
};

ostream& operator<<(ostream& os, const Programmation& prog);

#endif // PROGRAMMATION_H
