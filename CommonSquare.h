#ifndef COMMONSQUARE_H
#define COMMONSQUARE_H

#include "Square.h"
#include "Living.h"

class CommonSquare: public Square
{
    public:
        CommonSquare(int, int);
        ~CommonSquare();
        void displayMenu(Hero*);

};

#endif // COMMONSQUARE_H
