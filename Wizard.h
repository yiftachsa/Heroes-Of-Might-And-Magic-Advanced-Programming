/*
 * Wizard.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef WIZARD_H_
#define WIZARD_H_

#include "Creature.h"


class Wizard : public Creature{
public:
	static const int powerAttack;
	static const int powerDefense;
	static const int cost;
	Wizard();
	virtual ~Wizard();
	virtual string getType();
//	virtual void getDetails();
	virtual int fight(Creature &targetCreature, int attackersCount);
	virtual int getDefense();
	virtual int getAttack();

};

#endif /* WIZARD_H_ */
