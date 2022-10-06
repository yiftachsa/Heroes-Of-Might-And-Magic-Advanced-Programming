/*
 * Archer.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Archer.h"

using namespace std;

const int Archer::powerAttack=5;
const int Archer::powerDefense=4;
const int Archer::cost=90;


Archer::Archer():Creature() {
	// TODO Auto-generated constructor stub

}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

string Archer::getType()
{
	return "Archer";
}
int Archer::getDefense()
{
	return this->powerDefense;
}

int Archer::getAttack()
{
	return this->powerAttack;
}

int Archer::fight(Creature &targetCreature, int attackersCount)
{
	int countKills = 0;
	int attackStrength = attackersCount * powerAttack;
	int defense;

	if (targetCreature.getType() == "BlackDragon")
	{
		defense = targetCreature.getDefense();
		countKills = (attackStrength*1.2)/defense;
	}
	else
	{
		defense = targetCreature.getDefense();
		countKills = attackStrength/defense;
	}

	return countKills;


}
/*
void Archer::getDetails()
{
	cout<<"Attack level: "<<this->powerAttack<<", Defense level: "<<this->powerDefense<<endl;
}
*/

