/*
 * Thief.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Thief.h"

Thief::Thief(string name):Hero(name) {
	// TODO Auto-generated constructor stub

}

Thief::~Thief() {
	// TODO Auto-generated destructor stub
}

string Thief::getType()
{
	return "Thief";
}

void Thief::specialSkill()
{

}



void Thief::specialSkill(Hero &heroToSteal)
{
	if(this->getAlreayUsedSpecialSkill()==false)
	{
		this->setAlreayUsedSpecialSkill(true);
		//opponent less then 70
		if(heroToSteal.getGoldAmount()<70)
		{
			//thief more then 2500
			if(this->getGoldAmount()+heroToSteal.getGoldAmount()>MAXGOLDAMOUNT)
			{
				heroToSteal.loseGold(-(MAXGOLDAMOUNT-this->getGoldAmount()));
				this->setGoldAmount(MAXGOLDAMOUNT);
			}
			//opponent broke
			else
			{
				this->gainGold(heroToSteal.getGoldAmount());
				heroToSteal.setGoldAmount(0);
			}

		}
		else
		{
			//thief more then 2500
			if(this->getGoldAmount()+heroToSteal.getGoldAmount()>MAXGOLDAMOUNT)
			{
				heroToSteal.loseGold(-(MAXGOLDAMOUNT-this->getGoldAmount()));
				this->setGoldAmount(MAXGOLDAMOUNT);
			}
			else
			{
				heroToSteal.loseGold(-70);
				this->gainGold(70);
			}

		}

	}
}
