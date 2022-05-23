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

#include "carta.h"

carta::carta(size_t intero, int cartaBriscola) throw(invalid_argument*) {
    setSeme(intero/10);
    setValore(intero%10);
    briscola=seme==cartaBriscola/10;
}

carta::carta(size_t seme, size_t valore, int cartaBriscola) throw(invalid_argument*) {
        setSeme(seme);
        setValore(valore);
        briscola=seme==cartaBriscola/10;
}

size_t carta::getPunteggio() {
    switch(valore) {
        case 0: return 11;
        case 2: return 10;
        case 9: return 4;
        case 8: return 3;
        case 7: return 2;
        default: return 0;
    }
}

wxString carta::getSemeStr() {
    wxString semeBriscola;
    switch (seme) {
        case 0: semeBriscola=_("Bastoni"); break;
        case 1: semeBriscola=_("Coppe"); break;
        case 2: semeBriscola=_("Denari"); break;
        case 3: semeBriscola=_("Spade"); break;
    }
    return semeBriscola;
}



bool carta::isBriscola() {
    return briscola;
}

void carta::setSeme(size_t seme) throw (invalid_argument*) {
    if (seme>=0 && seme <4)
        this->seme=seme;
    else {
        std::string err="Seme passato: ";
        throw new std::invalid_argument(err);
    }
}

void carta::setValore(size_t valore) throw (invalid_argument *) {
    if (valore>=0 && valore <10)
        this->valore=valore;
    else
        throw new std::invalid_argument("Valore passato: ");
}

ostream& operator<<(ostream& o, carta& c) {
    string s;
    switch(c.seme) {
        case 0: s="bastoni"; break;
        case 1: s="coppe"; break;
        case 2: s="denari"; break;
        case 3: s="spade"; break;
    }
    o<<c.valore+1<<" "<<s;
    if (c.briscola)
        o<<"*";
    return o;
}

bool operator<(carta& c1, carta& c2) {
    if (c1.getPunteggio()<c2.getPunteggio())
        return true;
    if (c1.getPunteggio()>c2.getPunteggio())
        return false;
    if (!c1.isBriscola() && c2.isBriscola())
        return true;
    if (c1.isBriscola() && !c2.isBriscola())
        return false;
    if (c1.valore<c2.valore)
        return true;
    return false;
}
