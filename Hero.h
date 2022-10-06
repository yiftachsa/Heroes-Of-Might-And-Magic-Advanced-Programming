/*
 * Hero.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef HERO_H_
#define HERO_H_

#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>
#include <string>
#include "Zombie.h"
#include "Vampire.h"
#include "Archer.h"
#include "Wizard.h"
#include "BlackDragon.h"
//#include <list>


#include "Creature.h"

#define MAXGOLDAMOUNT 2500
#define DISTINCTCREATURES 5

using namespace std;

class Hero {
private:
	 bool alreayTookTheMoney;
	 bool alreayUsedSpecialSkill;

	string name;
	double goldAmount; //##AmountOfGold
	// CreaturesInventory: (Zombies, Vampires, Archers, Wizard, BlackDragons)
	int creaturesInventory [DISTINCTCREATURES]; //###Maybe Should be KEYVALUEPAIR!!!
	void isLegalHeroName(string newName); //###Replace with EXCEPTION
	void enoughMoneyLeft(int CreatureCost);//###Replace with EXCEPTION

public:
	Hero();
	Hero(string name);
	Hero(const Hero& other);
	virtual ~Hero();

	void setAlreayUsedSpecialSkill(bool update);
	bool getAlreayUsedSpecialSkill();
	string getName(); //###
	double getGoldAmount(); //###
	int* getCreaturesInventory(); //###
	int getCreaturesInventoryIndex(string creatureName);

	void setName(string newName); //###
	void setGoldAmount(double newGoldAmount); //###
	void setCreaturesInventory(int* newCreturesInventory); //###

	void gainGold(double amount); //###
	void loseGold(double amount); //###

	virtual string getType()=0;

	void buyCreature(string name , int number);

	void getMoney();
	void setAlreayTookTheMoney(bool update);
	bool getAlreayTookTheMoney();

	string getNameAndType();
	void getDetails();
	string getAllDetails();
	void attack(Hero  &opponentHero, string attackWith, string target);
	void hasCreatureType(string creatureName);//###Replace with EXCEPTION
	Creature* getCreatureFromName(string creatureName);
	virtual void specialSkill()=0;
	void finish();
	bool isDead();
	string toString(int x);
};

#endif /* HERO_H_ */
