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

#ifndef _CPU_H_
#define _CPU_H_

#include <stdlib.h>
#include "giocatore.h"

#define NON_TROVATA -1

class cpu: public giocatore {
    public:
        cpu();
        cpu(string nome);
        virtual void gioca();
        virtual void gioca(giocatore* g);
        friend ostream& operator<<(ostream& o, cpu& c);
    private:
        int cercaSoprataglio();
        int getSoprataglio(carta* c, bool maggiore);
        int getBriscola();
};

#endif
