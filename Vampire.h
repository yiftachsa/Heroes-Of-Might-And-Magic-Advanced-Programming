/*
 * Vampire.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef VAMPIRE_H_
#define VAMPIRE_H_

#include "Creature.h"



class Vampire : public Creature{
public:
	static const int powerAttack;
	static const int powerDefense;
	static const int cost;
	Vampire();
	virtual ~Vampire();
	virtual string getType();
//	virtual void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount);
	virtual int getDefense();
	virtual int getAttack();

};

#endif /* VAMPIRE_H_ */
