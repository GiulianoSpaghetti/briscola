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

#ifndef _MAZZO_H_
#define _MAZZO_H_

#include <fstream>
#include <stdexcept>
#include <vector>

#include <ctime>
#include <cstdlib>

#include "carta.h"
#define NUMERO_CARTE 40

class mazzo {
    public:
        mazzo();
        carta *getCarta();
        carta *getCartaBriscola() {return carte[0];}
        int getNumeroCarte() {return i+1;}
        bool hasCarte() {return i>-1;}
        void mischia();
        virtual ~mazzo();
    private:
        enum {FINE_MAZZO=-1};
        vector<carta*> carte;
        vector<bool> doppioni;
        bool addCarta(size_t intero);
        int i;
};

#endif
