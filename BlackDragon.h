/*
 * BlackDragon.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef BLACKDRAGON_H_
#define BLACKDRAGON_H_

#include "Creature.h"


class BlackDragon : public Creature{
public:
	static const int powerAttack;
	static const int powerDefense;
	static const int cost;
	BlackDragon();
	virtual ~BlackDragon();
	virtual string getType();
//	virtual void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount);
	virtual int getDefense();
	virtual int getAttack();


};

#endif /* BLACKDRAGON_H_ */
