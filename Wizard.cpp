/*
 * Wizard.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Wizard.h"

const int Wizard::powerAttack=8;
const int Wizard::powerDefense=2;
const int Wizard::cost=150;

Wizard::Wizard():Creature() {
	// TODO Auto-generated constructor stub

}

Wizard::~Wizard() {
	// TODO Auto-generated destructor stub
}
string Wizard::getType()
{
	return "Wizard";
}
int Wizard::getDefense()
{
	return this->powerDefense;
}

int Wizard::getAttack()
{
	return this->powerAttack;
}

int Wizard::fight(Creature &targetCreature, int attackersCount)
{
	int countKills = 0;
	int attackStrength = attackersCount * powerAttack;
	int defense;

	defense = targetCreature.getDefense();
	countKills = attackStrength/defense;


	return countKills;

}
/*
void Wizard::getDetails()
{
	cout<<"Attack level: "<<this->powerAttack<<", Defense level: "<<this->powerDefense<<endl;
}
*/

