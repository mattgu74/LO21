#ifndef EVENEMENT_H_INCLUDED
#define EVENEMENT_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

#include "time.h"

using namespace TIME;

class Ev_1j
{
    protected:
        Date _date;
        string _objet;

    public:
        Ev_1j(int j, int m, int a, const string& s) : _date(j,m,a), _objet(s) {};
        Ev_1j(const Ev_1j& ev) : _date(ev._date), _objet(ev._objet) {};
        virtual ~Ev_1j() {};
        virtual Ev_1j * clone() const { return new Ev_1j(*this); };
        const string& get_description() const { return _objet; }
        const Date& get_date() const { return _date; }
        virtual void afficher(ostream& f= cout) const {
            f<<"******** evt ********"<<endl;
            f<<"Date="<<_date<<" Objet="<<_objet<<endl;
        }
};

class Ev_1j_dur : public Ev_1j
{
    protected:
        Horaire _debut;
        Duree _duree;

    public:
        Ev_1j_dur(int j, int m, int a, const string& s,
            int hh, int hm, int dh, int dm) : Ev_1j(j, m, a, s), _debut(hh,hm), _duree(dh, dm) {};
        Ev_1j_dur(const Ev_1j_dur& ev) : Ev_1j(ev), _debut(ev._debut), _duree(ev._duree) {};
        Ev_1j_dur * clone() const { return new Ev_1j_dur(*this); };
        const Horaire& get_debut() const { return _debut; };
        const Duree& get_duree() const { return _duree; };

        void afficher(ostream& f= cout) const {
            Ev_1j::afficher(f);
            f<<"Debut="<<_debut<<" Durée="<<_duree<<endl;
        }
};


class Rdv : public Ev_1j_dur
{
    protected:
        string _lieu;
        string _personne;

    public:
        Rdv(int j, int m, int a, const string& s,
            int hh, int hm, int dh, int dm,
            const string& lieu, const string& personne) :
            Ev_1j_dur(j,m,a,s,hh,hm,dh,dm),
            _lieu(lieu), _personne(personne) {};
        Rdv(const Rdv& rdv) : Ev_1j_dur(rdv), _lieu(rdv._lieu), _personne(_personne) {};
        Rdv * clone() const { return new Rdv(*this); };

        const string& get_lieu() const { return _lieu; };
        const string& get_personne() const { return _personne; };

        void afficher(ostream& f=cout) const {
            Ev_1j_dur::afficher(f);
            f << "Lieu=" << _lieu << " Personne=" << _personne << endl;
        }
};

ostream& operator<<(ostream& os, const Ev_1j& ev);


class Agenda_iterator
{
    private:
        Ev_1j ** _ptr;
    public:
        Agenda_iterator() : _ptr(0) {};
        Agenda_iterator(Ev_1j** ptr) : _ptr(ptr) {};

        bool operator!=(const Agenda_iterator& it) { return it._ptr != _ptr; };
        Agenda_iterator& next() {++_ptr; return *this;};
        Ev_1j& value() {return **_ptr;};
};

class Agenda
{
    protected:
        Ev_1j** _events;
        int _nb_events;
        int _taille_max;

    public:
        friend class Agenda_iterator;
        typedef Agenda_iterator iterator;
        Agenda(int i = 10);
        virtual ~Agenda();
        Agenda& operator<<(const Ev_1j& ev);
        virtual void afficher(ostream& f=cout) const;
        Agenda_iterator first() { return Agenda_iterator(_events); }
        Agenda_iterator end() { return Agenda_iterator(_events+_nb_events); };
};



ostream& operator<<(ostream& os, const Agenda& a);

#endif // EVENEMENT_H_INCLUDED
