/*
 * Warrior.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Warrior.h"

using namespace std;


Warrior::Warrior(string name):Hero(name) {
	// TODO Auto-generated constructor stub

}

Warrior::~Warrior() {
	// TODO Auto-generated destructor stub
}

string Warrior::getType()
{
	return "Warrior";
}



void Warrior::specialSkill()
{
	if(this->getAlreayUsedSpecialSkill()==false)
	{
		this->setAlreayUsedSpecialSkill(true);
		this->gainGold(50);
		cout<<"Gold added successfully"<<endl;
	}
}
