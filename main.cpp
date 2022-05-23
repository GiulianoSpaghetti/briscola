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

using namespace std;

int main() {
    mazzo* m=new mazzo();
    cpu *cp=new cpu();
    giocatore* primo=new giocatore("Michele"),
              *secondo=cp,
              *g=primo,
              *temp;
    carta *c,
          *c1;
    try {
        m->mischia();
    } catch (overflow_error* e) {
        cerr<<e->what();
        return 1;
    } catch (invalid_argument* e) {
        cerr<<e->what();
        return 1;
    }
    int i;
    for (i=0; i<3; i++) {
        try {
            primo->addCarta(m);
            secondo->addCarta(m);
        } catch (overflow_error* e) {
            cerr<<e->what();
            return 1;
        }
    }
    do {
            cout<<"Rimangono "<<m->getNumeroCarte()<<" carte nel mazzo"<<endl;
            cout<<*cp;
            try {
                primo->gioca();
                c=primo->getCartaGiocata();
                cout<<endl<<"Carta giocata: "<<*c<<endl<<endl;
                secondo->gioca(primo);
                c1=secondo->getCartaGiocata();
                cout<<"Carta giocata: "<<*c1<<endl;
#ifdef WIN32
                system("pause");
                system("cls");
#else
		system("Premere un tasto per continuare...; read dummy");
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
                cout<<"Partita finita"<<endl;
                break;
            }
    } while (true);
}
