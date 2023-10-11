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

#include "mazzo.h"

mazzo::mazzo(): i(NUMERO_CARTE-1) {
    ;
}

bool mazzo::addCarta(size_t intero) {
    if (carte.size()==NUMERO_CARTE) {
        throw new std::overflow_error("Errore");
        return false;
    }
    if (doppioni[intero])
        return false;
    else {
        if (carte.size()==0)
            carte.push_back(new carta(intero, intero));
        else
            carte.push_back(new carta(intero, carte[0]->getSeme()*10));
        doppioni[intero]=true;
    }
    return true;
}

carta *mazzo::getCarta() {
    carta *c;
    if (i==FINE_MAZZO) {
        throw new underflow_error("Errore");
        return NULL;
    }
    c=carte[i--];
    return c;
}

void mazzo::mischia()  {
    srand(time(NULL));
    doppioni.assign(NUMERO_CARTE, false);
    size_t carta=rand();
    while (carte.size()<NUMERO_CARTE) {
        carta*=rand();
        carta%=NUMERO_CARTE;
        while (!addCarta(carta)) {
            ++carta;
            carta%=NUMERO_CARTE;
        }
    }
    doppioni.clear();
}

mazzo::~mazzo() {
    vector<carta*>::iterator i;
    for (i=carte.begin(); i!=carte.end(); i++)
        delete *i;
    carte.clear();
    doppioni.clear();
}
