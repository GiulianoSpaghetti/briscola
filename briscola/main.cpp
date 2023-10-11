/***************************************************************************
 *   Copyright (C) 2007 by Giulio Sorrentino                               *
 *   numerone@fastwebnet.it                                                *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include <iostream>
#include "mazzo.h"
#include "giocatore.h"
#include "cpu.h"

#include <windows.h>
#include "internat.h"
using namespace std;

static internat* inter;

int main(int argc, char *argv[]) {
    wstring s1, s2;
    if (argc != 4) {
        cout << "Must be passed 3 parameters: the name of user, the name of cpu and an integer indicating the translation number." << endl;
        return EXIT_FAILURE;
    }
    int i = atoi(argv[3]);
    if (i == 1)
        std::setlocale(LC_ALL, "it_IT.UTF8");
    else {
        std::setlocale(LC_ALL, "en_US.UTF8");
        i = 0;
    }
    inter = new internat(i);
    carta::inter = inter;
    giocatore::inter = inter;
    cpu::inter = inter;
    bool primaPartita = true;
    size_t puntiUtente = 0, puntiCpu = 0;
    mazzo* m = new mazzo();
    string s = argv[2];
    s1 = wstring(s.begin(), s.end());
    cpu *cp=new cpu(s1);
    s = argv[1];
    s1 = wstring(s.begin(), s.end());
    giocatore* primo=new giocatore(s1),
              *secondo=cp,
              *g=primo,
              *temp;
    carta *c,
          *c1;
    try {
        m->mischia();
    } catch (overflow_error* e) {
        cerr<<e->what();
        return EXIT_FAILURE;
    } catch (invalid_argument* e) {
        cerr<<e->what();
        return EXIT_FAILURE;
    }
    for (i=0; i<3; i++) {
        try {
            primo->addCarta(m);
            secondo->addCarta(m);
        } catch (overflow_error* e) {
            cerr<<e->what();
            return EXIT_FAILURE;
        }
    }
    wcout << L"Briscola CUI 2.1 by numerone " << inter->get_translated_string(internat::STRINGS::TESTING_ARM64) << endl;
    do {
        if (m->getNumeroCarte() > 0) {
            wcout << inter->get_translated_string(internat::STRINGS::IN_DECK) << L" " << m->getNumeroCarte() << L" " << inter->get_translated_string(internat::STRINGS::CARDS) << L" " << endl;
            wcout << inter->get_translated_string(internat::STRINGS::TRUMP_CARD_IS) << L" "<< * (m->getCartaBriscola()) << endl;
        }
            wcout<<*cp;
            try {
                primo->gioca();
                c=primo->getCartaGiocata();
                wcout << endl << inter->get_translated_string(internat::STRINGS::GAMED_CARD) << L": "<< *c << endl << endl;
                secondo->gioca(primo);
                c1=secondo->getCartaGiocata();
                wcout << inter->get_translated_string(internat::STRINGS::GAMED_CARD) << L": " << *c1 << endl;
#ifdef WIN32
                system("pause");
                system("cls");
#else
		system("echo Premere un tasto per continuare...; read dummy");
		system("clear");
#endif
                if ((c->getSeme()==c1->getSeme() && *c<*c1) || (!c->isBriscola() && c1->isBriscola())) {
                    temp=primo;
                    primo=secondo;
                    secondo=temp;
                }
                primo->setPunteggio(secondo);
                try {
                    primo->addCarta(m);
                    secondo->addCarta(m);
                } catch (overflow_error *e) {
                    ;
                }
            } catch (underflow_error* e) {
                puntiUtente += g->getPunteggio();
                puntiCpu += cp->getPunteggio();
                wcout<< inter->get_translated_string(internat::STRINGS::ENDED_GAME)<<endl;
                if (puntiUtente == puntiCpu)
                    wcout << s2;
                else if (puntiUtente > puntiCpu)
                    wcout << inter->get_translated_string(internat::STRINGS::YOU_WIN) << " "<<puntiUtente - puntiCpu << L" " << inter->get_translated_string(internat::STRINGS::POINTS) << endl;
                else
                    wcout << inter->get_translated_string(internat::STRINGS::YOU_LOOSE) << " "<< puntiCpu - puntiUtente << L" " << inter->get_translated_string(internat::STRINGS::POINTS) << endl;
                if (primaPartita)
                    wcout << inter->get_translated_string(internat::STRINGS::PLAY_SECOND_MATCH) << endl;
                else {
                    puntiUtente = puntiCpu = 0;
                    wcout << inter->get_translated_string(internat::STRINGS::PLAY_NEW_MATCH) << endl;
                }
                cin >> i;
                if (i==1)
                {
                    primaPartita =! primaPartita;

                    delete m;
                    m = new mazzo();
                    delete cp;
                    s = argv[2];
                    s1 = wstring(s.begin(), s.end());
                    cp = new cpu(s1);
                    delete g;
                    s = argv[1];
                    s1 = wstring(s.begin(), s.end());
                    g = new giocatore(s1);
                    if (primaPartita) {
                        secondo = cp;
                        primo = g;
                    }
                    else {
                        primo = cp;
                        secondo = g;
                    }
                    try {
                        m->mischia();
                    }
                    catch (overflow_error* e) {
                        cerr << e->what();
                        return EXIT_FAILURE;
                    }
                    catch (invalid_argument* e) {
                        cerr << e->what();
                        return EXIT_FAILURE;
                    }
                    for (i = 0; i < 3; i++) {
                        try {
                            primo->addCarta(m);
                            secondo->addCarta(m);
                        }
                        catch (overflow_error* e) {
                            cerr << e->what();
                            return EXIT_FAILURE;
                        }
                    }
                } else
                    break;
            }
    } while (true);
    return EXIT_SUCCESS;
}
