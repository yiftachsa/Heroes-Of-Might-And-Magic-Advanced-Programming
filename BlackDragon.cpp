/*
 * BlackDragon.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "BlackDragon.h"

const int BlackDragon::powerAttack=9;
const int BlackDragon::powerDefense=10;
const int BlackDragon::cost=200;



BlackDragon::BlackDragon():Creature() {
	// TODO Auto-generated constructor stub

}

BlackDragon::~BlackDragon() {
	// TODO Auto-generated destructor stub
}

string BlackDragon::getType()
{
	return "BlackDragon";
}

int BlackDragon::fight(Creature &targetCreature, int attackersCount)
{
	int countKills = 0;
	int attackStrength = attackersCount * powerAttack;
	int defense;
	if (targetCreature.getType() == "Wizard")
	{
		defense = targetCreature.getDefense();
		countKills = attackStrength/(defense*2);
	}
	else
	{
		defense = targetCreature.getDefense();
		countKills = attackStrength/defense;
	}

	return countKills;

}
/*
void BlackDragon::getDetails()
{
	cout<<"Attack level: "<<this->powerAttack<<", Defense level: "<<this->powerDefense<<endl;
}
*/
int BlackDragon::getDefense()
{
	return this->powerDefense;
}

int BlackDragon::getAttack()
{
	return this->powerAttack;
}
