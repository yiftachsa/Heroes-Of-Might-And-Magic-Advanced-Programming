/*
 * creature.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */
#include "Creature.h"





/*Creature::Creature(int gCost, int gPowerAttack, int gPowerDefense)
{
	this->cost=gCost;
	this->powerAttack=gPowerAttack;
	this->powerDefense=gPowerDefense;
}*/

Creature::Creature()
{
	/*this->cost=0;
	this->powerAttack=0;
	this->powerDefense=0;*/
}


void Creature::getDetails()
{
	cout<<"Attack level: "<<this->getAttack()<<", Defense level: "<<this->getDefense()<<endl;
}


