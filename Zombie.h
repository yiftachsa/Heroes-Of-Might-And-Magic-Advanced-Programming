/*
 * Zombie.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef ZOMBIE_H_
#define ZOMBIE_H_

#include "Creature.h"


class Zombie : public Creature{
public:
	static const int powerAttack;
	static const int powerDefense;
	static const int cost;
	Zombie();
	virtual ~Zombie();
	virtual string getType();
//	virtual void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount);
	virtual int getDefense();
	virtual int getAttack();

};

#endif /* ZOMBIE_H_ */
