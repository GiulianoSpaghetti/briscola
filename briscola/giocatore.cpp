/**********************************************************************************
 *   Copyright (C) 2007 by Giulio Sorrentino                                      *
 *   numerone@fastwebnet.it                                                       *
 *                                                                                *
 *   This program is free software; you can redistribute it and/or modify         *
 *   it under the terms of the GNU Lesser General Public License as published by  *
 *   the Free Software Foundation; either version 3 of the License, or            *
 *   (at your option) any later version.                                          *
 *                                                                                *
 *   This program is distributed in the hope that it will be useful,              *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                *
 *   GNU General Public License for more details.                                 *
 *                                                                                *
 *   You should have received a copy of the GNU General Public License            *
 *   along with this program; if not, write to the                                *
 *   Free Software Foundation, Inc.,                                              *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.                    *
 **********************************************************************************/

#include "giocatore.h"

internat *giocatore::inter;

giocatore::giocatore(): iCartaGiocata(NESSUNA_CARTA_GIOCATA), numeroCarte(3), punteggio(0)  {
    this->nome="";
}

giocatore::giocatore(string nome): iCartaGiocata(NESSUNA_CARTA_GIOCATA), numeroCarte(3), punteggio(0) {
    this->nome=nome;
}

void giocatore::addCarta(mazzo* m) {
    if (mano.size()==numeroCarte) {
        throw new overflow_error("Errore");
        return;
    } else {
        carta *c;
        vector<carta*>::iterator i;
        try {
            c=m->getCarta();
        } catch (underflow_error* e) {
            numeroCarte--;
            if (numeroCarte==0)
                throw;
            return;
        }
        for (i=mano.begin(); i!=mano.end(); i++)
            if (*c<**i)
                break;
        mano.insert(i, c);
    }
}

carta* giocatore::getCartaGiocata() {
    if (iCartaGiocata==NESSUNA_CARTA_GIOCATA) {
        throw new invalid_argument("Errore");
        return NULL;
    }
    return mano[iCartaGiocata];
}

size_t giocatore::getPunteggioCartaGiocata() {
    carta *c=getCartaGiocata();
    size_t p=c->getPunteggio();
    vector<carta*>::iterator i;
    for (i=mano.begin(); i!=mano.end() && *i!=c; i++);
    mano.erase(i);
    iCartaGiocata=NESSUNA_CARTA_GIOCATA;
    return p;
}

void giocatore::gioca() {
    if (mano.size()==0) {
        throw new underflow_error("");
        return;
    }
    std::cout<<*this<< inter->get_translated_string(internat::STRINGS::PROMPT)<< ": ";
    do {
        cin>>iCartaGiocata;
    } while (iCartaGiocata<1 || iCartaGiocata>mano.size());
    iCartaGiocata--;
}

void giocatore::gioca(giocatore* g) {
    gioca();
}

void giocatore::setCartaGiocata(int i) {
    if (i<0)
        throw new underflow_error("");
    else if (i>=mano.size())
        throw new overflow_error("");
    else
        iCartaGiocata=i;
}

ostream& operator<<(ostream& o, giocatore& g) {
    o<<g.inter->get_translated_string(internat::STRINGS::POINTS_OF)<<" "<<g.nome << ": " << g.punteggio << endl;
    o<<g.inter->get_translated_string(internat::PROMPT_CARDS)<<" "<<g.nome << ":" << endl;
    for (int i=0; i<g.mano.size(); i++)
        o<<*g.mano[i]<<" ";
    o<<endl;
    return o;
}

giocatore::~giocatore() {
    vector<carta*>::iterator i;
    for (i=mano.begin(); i!=mano.end(); i++)
        delete *i;
    mano.resize(0);
}

