#include <iostream>
using namespace std;

#include "evenement.h"

int main()
{
    Ev_1j ev_1j(1, 3, 2010, "un ev de 1j");
    cout << ev_1j << endl;

    Ev_1j_dur ev_1j_dur(4, 12, 2020, "un ev de 1j avec durée", 5,42, 1,30);
    cout << ev_1j_dur << endl;

    Rdv rdv(10, 11, 2013, "un rdv", 10,42, 1,0, "un garage", "du beau monde");
    cout << rdv << endl;

    Agenda agenda(1);

    agenda << ev_1j << ev_1j_dur << rdv;
    cout << agenda << endl;

    cout << "iterator" << endl;
    Agenda::iterator end = agenda.end();
    for (Agenda::iterator it = agenda.first(); it!=end; it.next()) {
        cout << it.value() << endl;
    }

    return 0;
}
