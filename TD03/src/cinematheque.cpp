#include "cinematheque.h"

Cinematheque * Cinematheque::singleton = 0;

Cinematheque& Cinematheque::ajouterFilm(const string& t, int d) {
	try {
		const Film &f = getFilm(t);
	}
	catch (CinemaException &e) {
		films[t] = Film(t,d);
		return *this;
	}

	throw CinemaException("Le film '"+t+"' est déjà dans la cinémathèque");
}

const Film& Cinematheque::getFilm(const string& t) const {
	FilmMap::const_iterator it = films.find(t);
	if (it == films.end()) {
		throw CinemaException("Le film '" + t + "n'existe pas dans la cinémathèque");
	}
	else {
		return it->second;
	}
}

