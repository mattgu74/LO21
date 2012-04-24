#ifndef CINEMATHEQUE_H
#define CINEMATHEQUE_H

#include <string>
#include <map>


#include "cinemaexception.h"
#include "film.h"

typedef std::map<std::string, Film>		FilmMap;

using std::map;
using std::string;


class Cinematheque
{
public:
	static Cinematheque * GetInstance() {
		if (singleton==0) {
			singleton = new Cinematheque;
		}
		return singleton;
	};;
	static void libereInstance() {};
	
    Cinematheque& ajouterFilm(const string& t, int d);
    
    const Film& getFilm(const string& t) const;

private:
    Cinematheque() {};
    Cinematheque(const Cinematheque& c) {};
    void operator=(const Cinematheque& c) {};
    ~Cinematheque() {};
    
	FilmMap films;
	
	static Cinematheque *singleton;

};


#endif // CINEMATHEQUE_H


