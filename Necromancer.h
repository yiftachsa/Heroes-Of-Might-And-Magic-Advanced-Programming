/*
 * Necromancer.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef NECROMANCER_H_
#define NECROMANCER_H_

#include "Hero.h"

class Necromancer : public Hero{
public:
	Necromancer(string name);
	virtual ~Necromancer();
	virtual string getType();
	virtual void specialSkill();
};

#endif /* NECROMANCER_H_ */
