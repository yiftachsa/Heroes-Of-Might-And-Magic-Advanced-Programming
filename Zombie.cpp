/*
 * Zombie.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Zombie.h"

using namespace std;

const int Zombie::powerAttack=2;
const int Zombie::powerDefense=5;
const int Zombie::cost=50;



Zombie::Zombie():Creature() {
	// TODO Auto-generated constructor stub

}

Zombie::~Zombie() {
	// TODO Auto-generated destructor stub
}

string Zombie::getType()
{
	return "Zombie";
}

int Zombie::fight(Creature &targetCreature, int attackersCount)
{
	int countKills = 0;
	int attackStrength = attackersCount * powerAttack;
	int defense;
	/*if (targetCreature.getType() == "Zombie"){
		defense = targetCreature.getDefense();
		countKills = attackStrength/defense;
	}else if(targetCreature.getType() == "Archer"){


	}
	*/
	if (targetCreature.getType() == "Archer")
	{
		defense = targetCreature.getDefense();
		countKills = (attackStrength*2)/defense;
	}
	else
	{
		defense = targetCreature.getDefense();
		countKills = attackStrength/defense;
	}

	return countKills;
}

/*
void Zombie::getDetails()
{
	cout<<"Attack level: "<<this->powerAttack<<", Defense level: "<<this->powerDefense<<endl;
}
*/


int Zombie::getDefense()
{
	return this->powerDefense;
}

int Zombie::getAttack()
{
	return this->powerAttack;
}
