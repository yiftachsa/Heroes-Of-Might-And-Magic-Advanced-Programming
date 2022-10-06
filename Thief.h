/*
 * Thief.h
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#ifndef THIEF_H_
#define THIEF_H_

#include "Hero.h"

class Thief : public Hero{
public:
	Thief(string name);
	virtual ~Thief();
	virtual string getType();
	void specialSkill(Hero &heroToSteal);
	virtual void specialSkill();


};

#endif /* THIEF_H_ */
