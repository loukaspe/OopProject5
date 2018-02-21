#ifndef COMMONSQUARE_H
#define COMMONSQUARE_H
#include "Grid.h"
#include "Square.h"
#include "Living.h"

int BATTLE_POSSIBILITY = 50;

class CommonSquare: public Square
{
    public:
        CommonSquare(int, int);
        ~CommonSquare();
        void displayMenu(Hero*);
        void showBattleOptions();
        void battle(Hero*);
        void noBattle(Hero*, Grid* myGrid);
        void showNoBattleOptions();

};

#endif // COMMONSQUARE_H
