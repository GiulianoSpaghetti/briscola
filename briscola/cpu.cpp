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

#include "cpu.h"

internat* cpu::inter;

cpu::cpu() {
    nome="cpu";
    srand(time(NULL));
}

cpu::cpu(string nome) {
    this->nome=nome;
    srand(time(NULL));
}

int cpu::getBriscola() {
    int i;
    for (i=0; i<mano.size(); i++)
        if (mano[i]->isBriscola())
            break;
    if (i==mano.size())
        return NON_TROVATA;
    else
        return i;
}

int cpu::getSoprataglio(carta *c, bool maggiore) {
    bool trovata=false;
    int i;
    if (maggiore) {
        for (i=mano.size()-1; i>=0; i--)
            if (c->getSeme()==mano[i]->getSeme() && *c<*mano[i]) {
                trovata=true;
                break;
            } else if (c->getSeme()==mano[i]->getSeme() && *mano[i]<*c)
                break;
    } else {
        for (i=0; i<mano.size(); i++)
            if (c->getSeme()==mano[i]->getSeme() && *c<*mano[i]) {
                trovata=true;
                break;
            }
    }
    if (trovata)
        return i;
    else
        return NON_TROVATA;
}

void cpu::gioca() {
    if (mano.size()==0) {
        throw new underflow_error("Errore");
        return;
    }
    for (iCartaGiocata=mano.size()-1; iCartaGiocata>0 && (mano[iCartaGiocata]->getPunteggio()>4 || mano[iCartaGiocata]->isBriscola()); iCartaGiocata--);
}


void cpu::gioca(giocatore* g) {
    carta* c=g->getCartaGiocata();
        int i=rand();
    if (!c->isBriscola()) {
        if ((iCartaGiocata=getSoprataglio(c, true))>NON_TROVATA)
            return;
        if (c->getPunteggio()>0 && (iCartaGiocata=getBriscola())>NON_TROVATA) {
            if (g->getCartaGiocata()->getPunteggio()>4)
                return;
            if (mano[iCartaGiocata]->getPunteggio()>0)
                if (i%10<5)
                    return;
        }
    } else {
        if (i%10<5 && (iCartaGiocata=getSoprataglio(c, false))>NON_TROVATA)
            return;
    }
    iCartaGiocata=0;
}

ostream& operator<<(ostream& o, cpu& c) {
    o<<cpu::inter->get_translated_string(internat::STRINGS::POINTS_OF) << " " << c.nome << ": " << c.punteggio << endl;
    return o;
}
