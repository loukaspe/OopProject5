#include <iostream>
#include <string>
#include <fstream>
#include "Item.h"
#include "Spell.h"
#include "Grid.h"
#include "MarketSquare.h"
#include "Market.h"
#include "CommonSquare.h"
#include "nonAccessibleSquare.h"
#include "Inventory.h"
#include "Buff.h"
#include "Buff_list.h"
#include "Square.h"
#include "Living.h"

void play(Grid*, Hero**);
void showPlayOptions();
void endGame();

using namespace std;

int main(void)
{

	return 0;
}

void play(Grid* myGrid, Hero** myHeroes)
{
    int option;
    showPlayOptions();
    cin >> option;

    while(option > 4 || option < 1)
    {
        cout << "Wrong Choice\nPlease choose again:" << endl;
        cin >> option;
    }

    if(option == 1)
    {
        myGrid->moveGrid();
    }
    else if(option == 2)
    {
        myGrid->displayMap();
    }
    else if(option == 3)
    {
        for(int i = 0; i < 3; i++)
        {
            if(myHeroes[i] != NULL)
            {
                myHeroes[i]->print_stats();
            }
        }
    }
    else if(option == 4)
    {
        endGame();
    }
}

void showPlayOptions()
{
    cout << "Please choose your option:" << endl;
    cout << "Move on Grid (Press 1)" << endl;
    cout << "See the Map (Press 2)" << endl;
    cout << "Show Hero's Information (Press 3)" << endl;
    cout << "Quit Game (Press 4)" << endl;
}

void endGame()
{

}
