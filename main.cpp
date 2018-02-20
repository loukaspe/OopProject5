#include <iostream>
#include <string>
#include <fstream>
//#include "Item.h"
//#include "Spell.h"
#include "Grid.h"
//#include "Living.h"


using namespace std;

int main(void)
{
	/*string a;
	cout << "Hello World!" << endl;
	cout << "Olympiakos" << endl;
	cout << "A change has been made!" << endl;*/
	Paladin pal;
	pal.print_stats();

	Grid* myGrid = new Grid(3, 3);
    char a;
	myGrid->displayMap();
    for(int i = 0; i < 5; i++)
    {
        //cin >> a;
        //myGrid->moveGrid(a);
            //myGrid->displayMap();

    }

    ifstream inFile;
    inFile.open("items.txt");
    Market* myMarket = new Market(inFile);
    myMarket->print_all();
    inFile.close();

	return 0;
}
