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
        void displayMenu(Hero**);
        void showBattleOptions();
        void battle(Hero**);
        void noBattle(Hero*, Grid*);
        void battleHerosTurn(Hero**, Monster* Monsters[4]);
        void battleMonstersTurn();
        void showNoBattleOptions();
        void fill_monsters(Monster* Monsters[4],int);
        void print_monsters_in_battle(Monster* monsters[4]);
        void attack(Monster* monsters[4], Hero*);
        void castSpell(Monster* monsters[4], Hero*);
        void use(Hero*);
        void afterBattle(Hero** myHeroes);
};

#endif // COMMONSQUARE_H
