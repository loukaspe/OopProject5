#include "CommonSquare.h"
#include "Square.h"

CommonSquare::CommonSquare(int givenX, int givenY):  Square(SQUARE_TYPE_COMMON, givenX, givenY)
{}

CommonSquare::~CommonSquare()
{}

/* Function for when the user is on a Common Square */
void CommonSquare::displayMenu(Hero* myHero, Grid* myGrid)
{
    // There are two options: Battle or ShowMenu depending on the outcome of the rand and the BATTLE_POSSIBILITY
    int r = rand() % 101;
    if(r >= BATTLE_POSSIBILITY)
        battle(myHero);
    else
        noBattle(myHero, myGrid);

}

/* Function for the battle ( If battle does happen ) */
void CommonSquare::battle(Hero* myHero)
{
    int option;
    showBattleOptions();
    cin >> option;

    while(option != 1 && option != 2 && option != 3 &&
          option != 4 && option != 5)
    {
        cout << "Wrong Option\n";
        showBattleOptions();
        cin >> option;
    }

    if(option == 1)
        attack();                       // ylopoihsh
    else if(option == 2)
        castSpell();                    // ylopoihsh
    else if(option == 3)
        use();                          // ylopoihsh
    else if(option == 4)
        myHero->equip_weapon();         // thelei oplo sthn parenthesi
    else if(option == 5)
        myHero->equip_armor();          // thelei armor sthn parenthesi

    // ekana apla ena menu gia na deis thn logikh, prosthese oti thes
    // kapou sthn battle prepei na dhmiourgountai kai ta terata

}

/* Function of what to do in case there is no battle in the Common Square ( If battle does not happen ) */
void CommonSquare::noBattle(Hero* myHero, Grid* myGrid)
{
    int option;
    showNoBattleOptions();
    cin >> option;

    while(option != 1 && option != 2 && option != 3 &&
          option != 4 && option != 5 && option != 6 )
    {
        cout << "Wrong Option\n";
        showNoBattleOptions();
        cin >> option;
    }

    if(option == 1)                     // oi equip isws theloyn allagh wste na dinei thn dynatothta na dialegoyme kai oplo, oxi mono na ta equip
        myHero->getInventory().print_all();
    else if(option == 2)
        myHero->equip_weapon();         // thelei oplo sthn parenthesi
    else if(option == 3)
        myHero->equip_armor();          // thelei armor sthn parenthesi
    else if(option == 4)
        use();                          // ylopoihsh
    else if(option == 5)
        myHero->showInfo();             // ylopoihsh
    else if(option == 6)
        myGrid->displayMap();

    // ekana apla ena menu gia na deis thn logikh, prosthese oti thes
}

/* Function to show a menu to the user to choose what to do in the common square if not battle happens */
void CommonSquare::showNoBattleOptions()
{
    cout << "Please choose your option:" << endl;
    cout << "Check your Inventory (Press 1)" << endl;
    cout << "Change Equipped Weapon (Press 2)" << endl;
    cout << "Change Equipped Armor (Press 3)" << endl;
    cout << "Use a Potion (Press 4)" << endl;
    cout << "Show Hero's Information (Press 5)" << endl;
    cout << "See the Map (Press 6)" << endl;
}

/* Function to show a menu to the user to choose what to do in the battle */
void CommonSquare::showBattleOptions()
{
    cout << "Please choose your option:" << endl;
    cout << "Attack (Press 1)" << endl;
    cout << "Cast Spell (Press 2)" << endl;
    cout << "Use a Potion (Press 3)" << endl;
    cout << "Change Equipped Weapon (Press 4)" << endl;
    cout << "Change Equipped Armor (Press 5)" << endl;
}
