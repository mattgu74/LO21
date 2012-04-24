#include "evenement.h"
#include <new>


ostream& operator<<(ostream& os, const Ev_1j& ev) {
    ev.afficher(os);
    return os;
}




ostream& operator<<(ostream& os, const Agenda& a) {
    a.afficher(os);
    return os;
}


Agenda::Agenda(int i) : _nb_events(0), _taille_max(i) {
    _events = new Ev_1j*[i];
}

Agenda::~Agenda() {
    for (int i=0; i < _nb_events; ++i) {
        delete _events[i];
    }
    delete[] _events;
}

Agenda& Agenda::operator<<(const Ev_1j& ev) {
    if (_nb_events >= _taille_max) {
        Ev_1j **temp = new Ev_1j*[_taille_max];
        for (int i=0; i<_taille_max; ++i) {
            temp[i] = _events[i];
        }
        delete[] _events;
        int new_taille_max = _taille_max*2;
        _events = new Ev_1j*[new_taille_max];
        for (int i=0; i<_taille_max; ++i) {
            _events[i] = temp[i];
        }
        delete[] temp;
        _nb_events = _taille_max;
        _taille_max = new_taille_max;
    }
    _events[_nb_events] = ev.clone();
    ++_nb_events;
    return *this;
}

void Agenda::afficher(ostream& f) const {
    f << "******** agenda ********" << endl;
    for (int i=0; i<_nb_events; ++i) {
        f << "Event " << i << " : " << endl;
        f << (*_events[i]) << endl;
    }
}

