#ifndef SPELL
#define SPELL

#include <iostream>
#include <string>



using namespace std;

class Spell
{
protected:
	string name;
	string type;
	int price;
	int min_lvl;
	int damage;
	int mana_req;
public:
	Spell(string nm, int pr, int mlvl, int dmg, int manr);
	virtual ~Spell();
	string get_name();
	int get_price();
	int get_minlvl();
	int get_damage();
	int get_manareq();
	string get_type(); /*Types: Fire,Ice,Lighting*/
	void print_info();
};

class FireSpell: public Spell
{
    public:
        FireSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(string nm, int pr, int mlvl, int dmg, int manr), type("Fire"){}
        ~FireSpell();
};

class LightningSpell: public Spell
{
    public:
        LightningSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(string nm, int pr, int mlvl, int dmg, int manr), type("Lightning"){}
        ~LightningSpell();
};

class IceSpell: public Spell
{
    public:
        IceSpell(string nm, int pr, int mlvl, int dmg, int manr): Spell(string nm, int pr, int mlvl, int dmg, int manr), type("Ice"){}
        ~IceSpell();
};

#endif //SPELL
