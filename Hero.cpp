/*
 * Hero.cpp
 *
 *  Created on: Jan 2, 2019
 *      Author: merav
 */

#include "Hero.h"



using namespace std;


string Hero::toString(int x){
	stringstream s;
	s<<x;
	return s.str();
}

Hero::Hero(string gName) {
	// TODO Auto-generated constructor stub
	this->isLegalHeroName(gName); //###Should be try\catch
	this->name=gName;
	this->goldAmount=750;
	int i;
	for(i=0;i<DISTINCTCREATURES;i++)
	{
		this->creaturesInventory[i]=0;
	}
	alreayTookTheMoney=false;
	alreayUsedSpecialSkill=false;


}

Hero::Hero()//###???
{
	this->name="NULL"; //###???
	this->goldAmount=750;
	int i;
	for(i=0;i<DISTINCTCREATURES;i++)
	{
		this->creaturesInventory[i]=0;
	}
	alreayTookTheMoney=false;
	alreayUsedSpecialSkill=false;

}


Hero::~Hero() {
	// TODO Auto-generated destructor stub
}

Hero::Hero(const Hero& other){
	this->name = other.name; //###Deep copy?
	this->goldAmount = other.goldAmount;
	int i;
	for(i=0;i<DISTINCTCREATURES;i++)
	{
		this->creaturesInventory[i] = other.creaturesInventory[i];
	}
	alreayTookTheMoney=false;
	alreayUsedSpecialSkill=false;

}

void Hero::setAlreayUsedSpecialSkill(bool update)
{
	this->alreayUsedSpecialSkill=update;
}

bool Hero::getAlreayUsedSpecialSkill()
{
	return this->alreayUsedSpecialSkill;
}


string Hero::getName(){
	string copyName = this->name;
	return copyName;
}

double Hero::getGoldAmount(){
	return this->goldAmount;
}

int* Hero::getCreaturesInventory(){
	/*int* newCreaturesInventory = new int[DISTINCTCREATURES];
	int i;
	for(i=0;i<DISTINCTCREATURES;i++)
	{
		newCreaturesInventory[i] = this->creaturesInventory[i];
	}*/
	return this->creaturesInventory;
}

void Hero::setName(string newName){ //###should catch\throw WrongNameException instead of returning a bool value
	this->isLegalHeroName(newName);
	this->name = newName;
}
void Hero::setGoldAmount(double newGoldAmount){
	if(newGoldAmount <= MAXGOLDAMOUNT && newGoldAmount >= 0){
		this->goldAmount = newGoldAmount;
	}
}
void Hero::setCreaturesInventory(int* newCreaturesInventory){
	if (newCreaturesInventory != NULL){
		int i;
		for(i=0;i<DISTINCTCREATURES;i++)
		{
			this->creaturesInventory[i] = newCreaturesInventory[i];
		}
	}
}

void Hero::isLegalHeroName(string newName){
	if (newName.length()>31){
		throw "Illegal Name";
	}
	int i=0;
	while (i<(int)newName.length()){
		if (!isalnum(newName[i])){
			throw "Illegal Name";
		}
		i++;
	}
	//###should throw WrongNameException instead of returning a bool value
}



void Hero::gainGold(double amount){
	if (amount >=0){
		if ((this->goldAmount + amount) <= MAXGOLDAMOUNT){
			this->goldAmount = this->goldAmount + amount;
		} else {
			this->goldAmount = MAXGOLDAMOUNT;
		}
	} else {
		//negative amount was entered - use the "loseGold(int amount)" to accomplish
	}
}

void Hero::loseGold(double amount){
	if (amount <=0){
		if ((this->goldAmount + amount) >= 0){
			this->goldAmount = this->goldAmount + amount;
		} else {
			this->goldAmount = 0;
		}
	} else {
		//positive amount was entered - use the "gainGold(int amount)" to accomplish
	}
}


void Hero::buyCreature(string typeOfCreature , int numberOfCreatures) //###Should try\catch
{
	if(typeOfCreature == "Zombie")
	{
		int totalCost = Zombie::cost * numberOfCreatures;
		enoughMoneyLeft(totalCost); //when implementing exceptions just call "enoughMoneyLeft(totalCost)"
		this->loseGold(-totalCost);
		this->creaturesInventory[0]=this->creaturesInventory[0]+numberOfCreatures;


	}
	else if(typeOfCreature == "Vampire")
	{
		int totalCost = Vampire::cost * numberOfCreatures;
		enoughMoneyLeft(totalCost); //when implementing exceptions just call "enoughMoneyLeft(totalCost)"
		this->loseGold(-totalCost);
		this->creaturesInventory[1]=this->creaturesInventory[1]+numberOfCreatures;


	}
	else if(typeOfCreature == "Archer")
	{
		int totalCost = Archer::cost * numberOfCreatures;
		enoughMoneyLeft(totalCost); //when implementing exceptions just call "enoughMoneyLeft(totalCost)"
		this->loseGold(-totalCost);
		this->creaturesInventory[2]=this->creaturesInventory[2]+numberOfCreatures;


	}
	else if(typeOfCreature == "Wizard")
	{
		int totalCost = Wizard::cost * numberOfCreatures;
		enoughMoneyLeft(totalCost); //when implementing exceptions just call "enoughMoneyLeft(totalCost)"
		this->loseGold(-totalCost);
		this->creaturesInventory[3]=this->creaturesInventory[3]+numberOfCreatures;


	}
	else if(typeOfCreature == "BlackDragon")
	{
		int totalCost = BlackDragon::cost * numberOfCreatures;
		enoughMoneyLeft(totalCost); //when implementing exceptions just call "enoughMoneyLeft(totalCost)"
		this->loseGold(-totalCost);
		this->creaturesInventory[4]=this->creaturesInventory[4]+numberOfCreatures;


	}

}

void Hero::enoughMoneyLeft(int CreatureCost){//###Replace with EXCEPTION

	if (this->goldAmount - CreatureCost < 0){
		throw "Not enough money";
	}

}


void Hero::setAlreayTookTheMoney(bool update){
	this->alreayTookTheMoney = update;
}

bool Hero::getAlreayTookTheMoney()
{
	return this->alreayTookTheMoney;
}



void Hero::getMoney()
{
	if(this->alreayTookTheMoney==false)
	{
		this->gainGold(100);
		alreayTookTheMoney=true;
	}
}

string Hero::getNameAndType()
{
	return this->name + " " + this->getType();
}

void Hero::getDetails()
{

	bool noCreatures = true;
	cout<<this->name<<" "<<this->getType()<<":"<<endl;
	int i=0;
	string creaturesPrint="";
	for(i=DISTINCTCREATURES-1;i>-1;i--)
	{
		if(this->creaturesInventory[i]!=0)
		{
			int iCreatureCount = this->creaturesInventory[i];
			string sCreatureCount = toString(iCreatureCount);
			creaturesPrint = creaturesPrint + sCreatureCount;
			if(i==4)
			{
				creaturesPrint= creaturesPrint +" Black_Dragon ";
				noCreatures = false;
			}

			else if(i==3)
			{
				creaturesPrint= creaturesPrint +" Wizard ";
				noCreatures = false;
			}

			else if(i==2)
			{
				creaturesPrint= creaturesPrint +" Archer ";
				noCreatures = false;
			}

			else if(i==1)
			{
				creaturesPrint= creaturesPrint +" Vampire ";
				noCreatures = false;
			}

			else if(i==0)
			{
				creaturesPrint= creaturesPrint +" Zombie ";
				noCreatures = false;
			}
		}
	}
	if (noCreatures == false){
		creaturesPrint=creaturesPrint.substr(0,creaturesPrint.length()-1);
		creaturesPrint=creaturesPrint+".";
		cout<<creaturesPrint<<endl;

	}

}

string Hero::getAllDetails() //name type numOfGold typeCreaturs
{
	bool noCreatures = true;
	string sGetAllDetails = "";
	sGetAllDetails = this->name+" "+this->getType()+":\n";
	sGetAllDetails =sGetAllDetails +toString(this->goldAmount)+" gold\n";
	int i=0;
	string creaturesPrint="";
	for(i=DISTINCTCREATURES-1;i>-1;i--)
	{
		if(this->creaturesInventory[i]!=0)
		{
			int iCreatureCount = this->creaturesInventory[i];
			string sCreatureCount = toString(iCreatureCount);
			creaturesPrint = creaturesPrint + sCreatureCount;
			if(i==4)
			{
				creaturesPrint= creaturesPrint +" Black_Dragon ";
				noCreatures = false;
			}

			else if(i==3)
			{
				creaturesPrint= creaturesPrint +" Wizard ";
				noCreatures = false;
			}

			else if(i==2)
			{
				creaturesPrint= creaturesPrint +" Archer ";
				noCreatures = false;
			}

			else if(i==1)
			{
				creaturesPrint= creaturesPrint +" Vampire ";
				noCreatures = false;
			}

			else if(i==0)
			{
				creaturesPrint= creaturesPrint +" Zombie ";
				noCreatures = false;
			}
		}
	}
	if (noCreatures == false){
		creaturesPrint=creaturesPrint.substr(0,creaturesPrint.length()-1);
		creaturesPrint=creaturesPrint+".";
		sGetAllDetails =sGetAllDetails +creaturesPrint+"\n";

	}
	return sGetAllDetails;
}

void Hero::attack(Hero  &opponentHero, string attackWith, string target)
{
	//need to check if opponentHero has the targetType in his Army
	//if not throw exception - in main catch and receive another targetType
	opponentHero.hasCreatureType(target);

	//AttackCreature
	Creature* attackCreature;
	attackCreature = getCreatureFromName(attackWith);
	int attackCreatureIndex;
	attackCreatureIndex = getCreaturesInventoryIndex(attackWith);
	int attackersCount;
	attackersCount = this->creaturesInventory[attackCreatureIndex];

	//TargetCreature
	Creature* targetCreature;
	targetCreature = getCreatureFromName(target);
	int TargetCreatureIndex;
	TargetCreatureIndex = getCreaturesInventoryIndex(target);

	//FIGHT!!!
	int countKills;
	countKills = attackCreature->fight(*targetCreature, attackersCount);


	if (opponentHero.creaturesInventory[TargetCreatureIndex] - countKills  < 0){
		opponentHero.creaturesInventory[TargetCreatureIndex] = 0;
	}else{
		opponentHero.creaturesInventory[TargetCreatureIndex] = opponentHero.creaturesInventory[TargetCreatureIndex] - countKills;
	}

	delete attackCreature;//?
	delete targetCreature;//?

	//attackWith->fight(target,opponentHero)

}

void Hero::finish()
{
	this->alreayTookTheMoney=false;
	this->alreayUsedSpecialSkill=false;
}
/*
void Hero::specialSkill(){
	this->alreayUsedSpecialSkill=true;


}
 */

bool Hero::isDead()
{
	int i=0;
	for(i=0;i<DISTINCTCREATURES;i++)
	{
		if(this->creaturesInventory[i]!=0)
		{
			return false;
		}

	}
	return true;
}
void Hero::hasCreatureType(string creatureName)
{
	bool creatureExists = false;
	if(creatureName=="Zombie")
	{
		creatureExists = this->creaturesInventory[0]!=0;
	}
	else if(creatureName=="Vampire")
	{
		creatureExists = this->creaturesInventory[1]!=0;
	}
	else if(creatureName=="Archer")
	{
		creatureExists = this->creaturesInventory[2]!=0;
	}
	else if(creatureName=="Wizard")
	{
		creatureExists = this->creaturesInventory[3]!=0;
	}
	else if(creatureName=="BlackDragon")
	{
		creatureExists = this->creaturesInventory[4]!=0;
	}
	if (creatureExists == false){
		throw "doesn't have the creature";
	}
}

Creature* Hero::getCreatureFromName(string creatureName)
{
	if(creatureName=="Zombie")
	{
		Creature* newCreature=new Zombie();
		return newCreature;
	}
	else if(creatureName=="Vampire")
	{
		Creature* newCreature=new Vampire();
		return newCreature;
	}
	else if(creatureName=="Archer")
	{
		Creature* newCreature=new Archer();
		return newCreature;
	}
	else if(creatureName=="Wizard")
	{
		Creature* newCreature=new Wizard();
		return newCreature;
	}
	else
	{
		Creature* newCreature=new BlackDragon();
		return newCreature;
	}

}

int Hero::getCreaturesInventoryIndex(string creatureName){
	if(creatureName=="Zombie")
	{
		return 0;
	}
	else if(creatureName=="Vampire")
	{
		return 1;
	}
	else if(creatureName=="Archer")
	{
		return 2;
	}
	else if(creatureName=="Wizard")
	{
		return 3;
	}
	else
	{
		return 4;
	}

}



