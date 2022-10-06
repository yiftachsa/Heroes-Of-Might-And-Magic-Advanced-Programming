/*
 * creature.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <iostream>

using namespace std;

class Creature
{

public:

	Creature();
	//Creature(int cost, int powerAttack, int powerDefense);
	virtual ~Creature(){};
	virtual string getType()=0;
	void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount)=0;
	virtual int getDefense()=0;
	virtual int getAttack()=0;
	//void hurtHealth(int amount)=0;
	//void gainHealth(int amount)=0;
	/*virtual void drinkHealth()=0;
	virtual void drinkPoison()=0;
	virtual void drinkBeer()=0;
	*/


};




#endif /* CREATURE_H_ */
