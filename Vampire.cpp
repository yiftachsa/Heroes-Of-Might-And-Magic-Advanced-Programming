/*
 * Vampire.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Vampire.h"

const int Vampire::powerAttack=4;
const int Vampire::powerDefense=4;
const int Vampire::cost=80;

Vampire::Vampire():Creature() {
	// TODO Auto-generated constructor stub

}

Vampire::~Vampire() {
	// TODO Auto-generated destructor stub
}
string Vampire::getType()
{
	return "Vampire";
}

int Vampire::fight(Creature &targetCreature, int attackersCount)
{
	int countKills = 0;
	int attackStrength = attackersCount * powerAttack;
	int defense;

	defense = targetCreature.getDefense();
	countKills = (attackStrength)/defense;

	return countKills;


}

int Vampire::getDefense()
{
	return this->powerDefense;
}

int Vampire::getAttack()
{
	return this->powerAttack;
}

/*
void Vampire::getDetails()
{
	cout<<"Attack level: "<<this->powerAttack<<", Defense level: "<<this->powerDefense<<endl;
}
*/
