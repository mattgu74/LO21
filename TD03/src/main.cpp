#include <iostream>
#include "cinematheque.h"
#include "cinema.h"
#include "time.h"

using std::cout;
using std::endl;
using TIME::Date;
using TIME::TimeException;

int main(int argc, char *argv[])
{
	try {
		Cinematheque& collection=*Cinematheque::GetInstance();
		collection.ajouterFilm("Kill Bill 1", 123);
		collection.ajouterFilm("Kill Bill 2", 156);
		collection.ajouterFilm("2001, Space Odyssey", 152);
		collection.ajouterFilm("School of Rock", 118);
		collection.ajouterFilm("Freaky Friday", 112);
		Cinema cine("Majestic",2);
		cine[0].getPlanning()<<Programmation(collection.getFilm("Kill Bill 1"),Date(5,5,2010),Date(11,5,2010));
		cine[1].getPlanning()<<Programmation(collection.getFilm("Kill Bill 2"),Date(5,5,2010),Date(11,5,2010));
		cine[0].getPlanning()<<Programmation(collection.getFilm("2001, Space Odyssey"),Date(12,5,2010),Date(18,5,2010));
		cine[0].getPlanning()<<Programmation(collection.getFilm("School of Rock"),Date(19,5,2010),Date(25,5,2010));
		cine[1].getPlanning()<<Programmation(collection.getFilm("Freaky Friday"),Date(12,5,2010),Date(25,5,2010));
		cout << cine << endl;
		std::cout<<"\nEssai Iterateur\n";
		for(Planning::iterator it=cine[0].getPlanning().begin();
		it!=cine[0].getPlanning().end();++it)
			std::cout<<*it<<"\n";
		for(Planning::iterator it=cine[1].getPlanning().begin();
		it!=cine[1].getPlanning().end();++it)
			std::cout<<*it<<"\n";
		Cinematheque::libereInstance();
	}
	catch(CinemaException e){ std::cout<<e.GetInfo()<<"\n"; }
	catch(TimeException e){ std::cout<<e.GetInfo()<<"\n"; }
	
	std::cout<<"Fin projet cinema\n";

    return 0;
}


