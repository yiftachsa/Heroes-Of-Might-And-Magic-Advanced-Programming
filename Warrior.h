/*
 * Warrior.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef WARRIOR_H_
#define WARRIOR_H_

#include "Hero.h"

class Warrior : public Hero{
public:
	Warrior(string name);
	virtual ~Warrior();
	virtual string getType();
	virtual void specialSkill();

};

#endif /* WARRIOR_H_ */
