#include "CommonSquare.h"
#include "Square.h"

CommonSquare::CommonSquare(int givenX, int givenY):  Square(SQUARE_TYPE_COMMON, givenX, givenY)
{}

CommonSquare::~CommonSquare()
{}

/* Function for when the user is on a Common Square */
void CommonSquare::displayMenu(Hero** myHeroes, Grid* myGrid)
{
    // There are two options: Battle or ShowMenu depending on the outcome of the rand and the BATTLE_POSSIBILITY
    int r = rand() % 101;
    if(r >= BATTLE_POSSIBILITY)
        for(int i = 0; i < 3; i++)
                battle(myHeroes);
    else
        for(int i = 0; i < 3; i++)
            if(myHeroes[i] != NULL)
                noBattle(myHeroes[i], myGrid);

}

/* Function for the battle ( If battle does happen ) */
void CommonSquare::battle(Hero** myHeroes)
{
    /* dhmiourgia teratwn */
    Monster* Monsters[4];
	int lvl = Heroes[0]->get_level();
	Fill_monsters(Monsters,lvl);

	while(checkIfHeroesAreDead() && checkIfMonstersAreDead())
    {
        battleHerosTurn(myHeroes, Monsters);
        battleMonstersTurn(myHeroes, Monsters);
    }

    afterBattle();
}

/* Function for the Heroes' turn in the battle */
void CommonSquare::battleHerosTurn(Hero** myHeroes, Monster* Monsters[4])
{
    int option;

    for(int i = 0; i < 3; i++)
    {
        if(myHeroes[i] != NULL)
        {
            showBattleOptions();
            cin >> option;

            while(option != 1 && option != 2 && option != 3 &&
                  option != 4 && option != 5)
            {
                cout << "Wrong Option\n";
                showBattleOptions();
                cin >> option;
            }

            // ti kanei to flag?

            if(option == 1)
                attack(myHeroes[i], Monsters);
            else if(option == 2)
                castSpell(Monsters, myHeroes[i]);
            else if(option == 3)
                use(myHeroes[i]);
            else if(option == 4)
                myHero->equip_weapon();         // thelei oplo sthn parenthesi
            else if(option == 5)
                myHero->equip_armor();          // thelei armor sthn parenthesi
        }
    }

    // prepei na pairnei kai ligo zwh kai magikh energeia
    // prepei na emfanizontai ta statistika toy hrwa
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
/* Function to create the monsters in the battle */
void CommonSquare::fill_monsters(Monster* Monsters[4],int lvl)
{
	int tmp;
	tmp = rand() % 3;
	if (tmp == 0)
	{
		Monsters[0] = new Dragon(lvl + rand() % 3 - 1);
	}
	else if (tmp == 1)
	{
		Monsters[0] = new Exoskeleton(lvl + rand() % 3 - 1);
	}
	else
	{
		Monsters[0] = new Spirit(lvl + rand() % 3 - 1);
	}
	for (int i = 1; i < 4; i++)
	{
		tmp = rand() % 2;
		if (tmp == 0)
		{
			Monsters[i] = NULL;
		}
		else
		{
			tmp = rand() % 3;
			if (tmp == 0)
			{
				Monsters[i] = new Dragon(lvl + rand() % 3 - 1);
			}
			else if (tmp == 1)
			{
				Monsters[i] = new Exoskeleton(lvl + rand() % 3 - 1);
			}
			else
			{
				Monsters[i] = new Spirit(lvl + rand() % 3 - 1);
			}
		}
	}
	cout << "Monsters spawned" << endl;
}

/* Function to print out what monsters exist in the battle field for the user to choose where to attack */
void CommonSquare::print_monsters_in_battle(Monster* monsters[4])
{
	cout << "MONSTERS IN BATTLE: { ";
	for (int i = 0; i < 4; i++)
	{
		if (monsters[i] != NULL)
		{
			cout << i << " ";
		}
	}
	cout << "}" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (monsters[i] != NULL)
		{
			cout <<"#"<< i << "-Monster's data:" << endl;
			monsters[i]->print_data();
		}
	}
}

/* Function for the Heroes to attack the monsters in the battle function */
void CommonSquare::attack(Monster* monsters[4], Hero* myHero)
{
    int damage;
    int mchoice;
    damage = (myHero->getEquippedWeapon()->get_damage() + myHero->get_strength()/4)*myHero->buffs.get_all_dmg();
    print_monsters_in_battle(Monsters);
    cout << "Select the monster you want to attack: " << endl;
    cin >> mchoice;
    cout << endl;
    while (mchoice > 3 || Monsters[mchoice] == NULL)       // edw giati 3 kai oxi 4?
    {
        cout << "Bad input!\nPlease choose again:" << endl;
        cin >> mchoice;
    }
    Monsters[mchoice]->receive_damage(damage);
    if (Monsters[mchoice]->get_c_health() == 0)
    {
        delete Monsters[mchoice];
        Monsters[mchoice] = NULL;
    }
}

/* Function for the heroes to cast a spell to the monsters in the battle function */
void CommonSquare::castSpell(Monster* monsters[4], Hero* myHero)
{
    if (myHero->inv.is_spell_list_empty() == true)
    {
        cout << "The spell list is empty!" << endl;
    }
    else
    {
        int schoice;
        myHero->inv.print_spells();
        cout << "Please input the number of the spell to use: " << endl;
        cin >> schoice;
        cout << endl;
        while (schoice > Heroes[i]->inv.get_spell_list_size() || schoice < 1)
        {
            cout << "Bad input!\nPlease choose again:" << endl;
            cin >> schoice;
        }
        else
        {
            schoice--;
            if (myHero->inv.get_spell_manareq(schoice) > myHero->get_magicpower())
            {
                cout << "Not enough Mana to cast the spell!" << endl;
            }
            else
            {
                int damage;
                int mchoice;
                myHero->sub_magicpower(myHero->inv.get_spell_manareq(schoice));
                damage = (myHero->inv.get_spell_damage(schoice) + (myHero->get_dexterity() / 3))*myHero->buffs.get_all_dmg();
                print_monsters_in_battle(Monsters);
                cout << "Select the monster you want to cast the spell to: ";
                cin >> mchoice;
                cout << endl;
                while (mchoice > 3 || Monsters[mchoice] == NULL)
                {
                    cout << "Bad input!\nPlease choose again:" << endl;
                    cin >> mchoice;
                }

                Monsters[mchoice]->receive_damage(damage);
                if (Monsters[mchoice]->get_c_health() == 0)
                {
                    delete Monsters[mchoice];
                    Monsters[mchoice] = NULL;
                }
                else
                {
                    if (myHero->inv.get_spell_type(schoice) == "Fire")
                    {
                        Monsters[mchoice]->buffs.add_dmgbuff(-5, 3);
                    }
                    else if (myHero->inv.get_spell_type(schoice) == "Ice")
                    {
                        Monsters[mchoice]->buffs.add_defbuff(-5, 3);
                    }
                    else
                    {
                        Monsters[mchoice]->buffs.add_agibuff(-5, 3);
                    }
                }
            }
        }
    }
}

/* Function for the hero to use potion in the battle function */
void CommonSquare::use(Hero* myHero)
{
    if (myHero->inv.is_potion_list_empty() == true)
    {
        cout << "Potion list is empty!" << endl;
    }
    else
    {
        int pchoice;
        myHero->inv.print_potions();
        cout << "Please input the number of the potion to use: ";
        cin >> pchoice;
        cout << endl;
        while (pchoice < 1 || pchoice > myHero->inv.get_potion_list_size())
        {
            cout << "Bad input!\nPlease choose again:" << endl;
            cin >> pchoice;
        }
        else
        {
            pchoice--;
            if (myHero->inv.get_potion_type(pchoice) == "Health")
            {
                myHero->restore_health(myHero->inv.get_potion_power(i));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Magic")
            {
                myHero->restore_magicpower(myHero->inv.get_potion_power(i));
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Damage")
            {
                myHero->buffs.add_dmgbuff(myHero->inv.get_potion_power(pchoice),3);
            }
            else if (myHero->inv.get_potion_type(pchoice) == "Defence")
            {
                myHero->buffs.add_defbuff(myHero->inv.get_potion_power(pchoice), 3);
            }
            else
            {
                myHero->buffs.add_agibuff(myHero->inv.get_potion_power(pchoice), 3);
            }
        }
    }
}

/* Function for the aftermath of the war */
void CommonSquare::afterBattle(Hero** myHeroes)
{
    // lefta kai empeiria ston hrwa analoga me level monsters
    // an xasoyn xanoyn ta misa lefta
    // an exei pethanei pairnei th mish zwh
}
