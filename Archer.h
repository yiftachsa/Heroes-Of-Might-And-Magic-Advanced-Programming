/*
 * Archer.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Creature.h"

class Archer : public Creature{
public:
	static const int powerAttack;
	static const int powerDefense;
	static const int cost;
	Archer();
	virtual ~Archer();
	virtual string getType();
//	virtual void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount);
	virtual int getDefense();
	virtual int getAttack();


};

#endif /* ARCHER_H_ */
