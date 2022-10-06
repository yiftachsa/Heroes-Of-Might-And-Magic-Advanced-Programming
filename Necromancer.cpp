/*
 * Necromancer.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Necromancer.h"

Necromancer::Necromancer(string name):Hero(name) {
	// TODO Auto-generated constructor stub

}

Necromancer::~Necromancer() {
	// TODO Auto-generated destructor stub
}

string Necromancer::getType()
{
	return "Necromancer";
}


void Necromancer::specialSkill()
{
	if(this->getAlreayUsedSpecialSkill()==false)
	{
		this->setAlreayUsedSpecialSkill(true);
		int* newCreatureInventory = this->getCreaturesInventory();
		newCreatureInventory[0]++;
		this->setCreaturesInventory(newCreatureInventory);
		cout<<"Zombie added successfully"<<endl;
	}
}

