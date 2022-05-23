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

#ifndef _GIOCATORE_H_
#define _GIOCATORE_H_

#include <iostream>
#include <fstream>
#include <vector>

#include "carta.h"
#include "mazzo.h"

#undef NUMERO_CARTE
#define NESSUNA_CARTA_GIOCATA -1

class giocatore {
    public:
        giocatore();
        giocatore(wxString nome);
        void addCarta(mazzo* m) throw (overflow_error*, underflow_error*);
        carta *getCarta(int i) {return mano[i];}
        carta* getCartaGiocata() throw (invalid_argument*);
        int getIndiceCartaGiocata() {return iCartaGiocata;}
        wxString getNome() {return nome;}
        int getNumeroCarte() {return mano.size();}
        size_t getPunteggio() {return punteggio;}
        size_t getPunteggioCartaGiocata() throw (invalid_argument*);
        virtual void gioca() throw (underflow_error*);
        virtual void gioca(giocatore* g) throw (underflow_error*);
        bool hasCartaGiocata() {return iCartaGiocata!=NESSUNA_CARTA_GIOCATA;}
        void setCartaGiocata(int i) throw (overflow_error*, underflow_error*);
        void setNome(wxString n) {nome=n;}
        void setPunteggio(giocatore *g) throw (invalid_argument*) {punteggio=punteggio+getPunteggioCartaGiocata()+g->getPunteggioCartaGiocata();}
        friend ostream& operator<<(ostream& o, giocatore& g);
        virtual ~giocatore();
    protected:
        wxString nome;
        vector<carta*> mano;
        int iCartaGiocata;
        size_t numeroCarte, punteggio;

};

#endif
