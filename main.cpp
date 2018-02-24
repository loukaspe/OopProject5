#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdlib>
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
    int heroesNumber;
    int r;
    Hero* myHeroes[3] = {NULL, NULL, NULL};

    cout << "\tWelcome to our Game\n\nPlease choose how many Heroes you want (One to Three):" << endl;
	cin >> heroesNumber;
	while(heroesNumber > 3 || heroesNumber < 1)
    {
        cout << "Wrong  Input\nPlease choose between one and three:" << endl;
        cin >> heroesNumber;
    }

    ifstream inFile;
    inFile.open("items.txt");
    Market* myMarket = MarketSquare::getMarket(inFile);
    inFile.close();

    srand(time(NULL));
    for(int i = 0; i < heroesNumber; i++)
    {
        r = rand()%3;
        if(r == 0)
        {
            myHeroes[i] = new Paladin();
        }
        else if(r == 1)
        {
            myHeroes[i] = new Sorcerer();
        }
        else if(r == 2)
        {
            myHeroes[i] = new Warrior();
        }
    }

    Grid* myGrid = new Grid(5, 5);

    while(1)
    {
        play(myGrid, myHeroes);
    }

	return 0;
}

void play(Grid* myGrid, Hero** myHeroes)
{
    bool didItMove;
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
        didItMove = myGrid->moveGrid();
        if(didItMove == true)                       // if the hero actually moved and didnt stay in the same square
            myGrid->displayMenu(myHeroes);
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
    cout << "Quit Game (Press 4)" << endl << endl;
}

void endGame()
{

}
