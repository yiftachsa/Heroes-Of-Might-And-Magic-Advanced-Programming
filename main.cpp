//============================================================================
// Name        : Ass5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>

#include "Warrior.h"
#include "Necromancer.h"
#include "Thief.h"

#include "dirent.h"
#include "sys/stat.h"
using namespace std;



int main(int argc, char* argv[]) {
	char* filePath=argv[0];
	//strcat(filePath, "/game");
	int roundNumber=-1;
	string activePlayer="";//###
	int heroTurnIndex=-1;
	int numOfWarriors=-1;
	int numOfTheifs=-1;
	int numOfNecromancers=-1;
	int totalNumOfPlayers=-1;
	Hero **Players;
	int *turnArray;
	int turnCounter=-1;
	if (argv[2]!=NULL)
	{
		/*new game*/
		//delete all previous data
		//check if a "game" folder exists in the running folder
		//if it does - then a previous game have been played - access the players list and get their name in order to delete them.
		//	delete the previous game heroe's folders.
		//	delete "game" folder
		//if no "game" folder exists
		//	no action
		//
		roundNumber=1;
		//istringstream(argv[2])>>numOfWarriors;
		numOfWarriors = atoi(argv[2]);
		//istringstream(argv[3])>>numOfTheifs;
		numOfTheifs = atoi(argv[3]);
		//istringstream(argv[4])>>numOfNecromancers;
		numOfNecromancers = atoi(argv[4]);
		if(numOfWarriors>3 || numOfTheifs >3 || numOfNecromancers>3)
		{
			cout<<"Can not create more then 3 heroes per type"<<endl;
			system("rm -r -f game");
			system("rm -r -f heroes");
			return 0;
		}
		totalNumOfPlayers = numOfNecromancers+numOfTheifs+numOfWarriors;
		Players = new Hero*[totalNumOfPlayers];
		int count=0;
		int i=0;
		while(i<numOfWarriors)
		{
			cout<<"Please insert warrior number "<<i+1<< " name:"<<endl;
			string newWarriorName;
			bool legalName = false;
			while (legalName == false){
				try{
					cin>>ws;
					getline(cin,newWarriorName);
					Players[count]=new Warrior(newWarriorName);//catch wrong name exception
					legalName = true;
				}catch (const char* illegal){
					cout<<"Please enter a legal hero name (Alphanumeric)\n";
				}
			}


			i++;
			count++;
		}
		i=0;
		while(i<numOfTheifs)
		{
			cout<<"Please insert thief number "<<i+1<< " name:"<<endl;
			string newThiefName;
			bool legalName = false;
			while (legalName == false){
				try{
					cin>>ws;
					getline(cin,newThiefName);
					Players[count]=new Thief(newThiefName);//catch wrong name exception
					legalName = true;
				}catch (const char* illegal){
					cout<<"Please enter a legal hero name (Alphanumeric)\n";
				}
			}
			i++;
			count++;
		}
		i=0;
		while(i<numOfNecromancers)
		{
			cout<<"Please insert necromancer number "<<i+1<< " name:"<<endl;
			string newNecromancerName;
			bool legalName = false;
			while (legalName == false){
				try{
					cin>>ws;
					getline(cin,newNecromancerName);
					Players[count]=new Necromancer(newNecromancerName);//catch wrong name exception
					legalName = true;
				}catch (const char* illegal){
					cout<<"Please enter a legal hero name (Alphanumeric)\n";
				}
			}
			i++;
			count++;
		}
		turnArray = new int[totalNumOfPlayers];

		int k=0;
		while (k<totalNumOfPlayers){
			int randomPlayerIndex = rand() % totalNumOfPlayers;
			int j;
			bool exists = false;
			for (j=0; j < k; j++){
				if (turnArray[j] == randomPlayerIndex){
					exists = true;
				}
			}
			if (exists == false){
				turnArray[k] = randomPlayerIndex;
				k++;
			}
		}
		turnCounter=0;
		heroTurnIndex = turnArray[turnCounter];
		activePlayer = Players[heroTurnIndex]->getName();
	}
	else
	{
		/*continue game*/
		string line;
		fstream GameDetails;
		GameDetails.open("game/GameData.txt",fstream::in);
		if (!GameDetails.is_open()){
			//THE FILE ISN'T OPEN
		}else{
			//while(!GameDetails.eof()){
			getline(GameDetails,line);
			string word;
			int spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			line = line.substr(spaceIndex+1,line.length());
			totalNumOfPlayers = atoi(word.c_str());
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			line = line.substr(spaceIndex+1,line.length());
			numOfWarriors = atoi(word.c_str());
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			line = line.substr(spaceIndex+1,line.length());
			numOfTheifs = atoi(word.c_str());
			word = line;
			numOfNecromancers = atoi(word.c_str());
			//}
			getline(GameDetails,line);
			Players = new Hero*[totalNumOfPlayers];
			turnArray=new int [totalNumOfPlayers];
			int count=0;
			int i=0;
			//updateHeroCreatureInventory("Warior",count, numOfWarriors, Players);
			//count=count+numOfWarriors;
			while(count<numOfWarriors)
			{
				i=0;
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				Players[count]=new Warrior(word);//catch wrong name exception
				string heroLine;
				fstream HeroDetails;
				string temp=Players[count]->getName();
				HeroDetails.open(("heroes//"+Players[count]->getName()+"/HeroData.txt").c_str(),fstream::in);
				if (!HeroDetails.is_open()){
					//THE FILE ISN'T OPEN
				}else{
					getline(HeroDetails,heroLine);
					getline(HeroDetails,heroLine);
					string heroWord;
					int spaceIndex = heroLine.find(" ", 0);
					heroWord = heroLine.substr(0, spaceIndex);
					heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
					Players[count]->setGoldAmount(atoi(heroWord.c_str()));
					getline(HeroDetails,heroLine);
					int creatureAmount=0;
					int newCreatureInventory[DISTINCTCREATURES];
					for (i=0;i<DISTINCTCREATURES;i++){
						newCreatureInventory[i]=0;
					}
					while (heroLine != "" && heroLine != "."){
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						creatureAmount=atoi(heroWord.c_str());
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						if (heroWord == "Black_Dragon" || heroWord == "Black_Dragon."){
							newCreatureInventory[4] = creatureAmount;
							if(heroWord == "Black_Dragon.")
							{
								heroLine="";
							}
						}else if(heroWord == "Wizard" || heroWord == "Wizard."){
							newCreatureInventory[3] = creatureAmount;
							if(heroWord == "Wizard.")
							{
								heroLine="";
							}
						}else if(heroWord == "Archer" || heroWord == "Archer."){
							newCreatureInventory[2] = creatureAmount;
							if(heroWord == "Archer.")
							{
								heroLine="";
							}
						}else if(heroWord == "Vampire" || heroWord == "Vampire."){
							newCreatureInventory[1] = creatureAmount;
							if(heroWord == "Vampire.")
							{
								heroLine="";
							}
						}else if(heroWord == "Zombie" || heroWord == "Zombie."){
							newCreatureInventory[0] = creatureAmount;
							if(heroWord == "Zombie.")
							{
								heroLine="";
							}
						}
					}
					Players[count]->setCreaturesInventory(newCreatureInventory);
				}
				count++;
				HeroDetails.close();
			}

			i=0;
			//////
			while(count<numOfTheifs+numOfWarriors)
			{
				i=0;
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				Players[count]=new Thief(word);//catch wrong name exception
				string heroLine;
				fstream HeroDetails;
				string temp=Players[count]->getName();
				HeroDetails.open(("heroes//"+Players[count]->getName()+"/HeroData.txt").c_str(),fstream::in);
				if (!HeroDetails.is_open()){
					//THE FILE ISN'T OPEN
				}else{
					getline(HeroDetails,heroLine);
					getline(HeroDetails,heroLine);
					string heroWord;
					int spaceIndex = heroLine.find(" ", 0);
					heroWord = heroLine.substr(0, spaceIndex);
					heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
					Players[count]->setGoldAmount(atoi(heroWord.c_str()));
					getline(HeroDetails,heroLine);
					int creatureAmount=0;
					int newCreatureInventory[DISTINCTCREATURES];
					for (i=0;i<DISTINCTCREATURES;i++){
						newCreatureInventory[i]=0;
					}
					while (heroLine != "" && heroLine != "."){
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						creatureAmount=atoi(heroWord.c_str());
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						if (heroWord == "Black_Dragon" || heroWord == "Black_Dragon."){
							newCreatureInventory[4] = creatureAmount;
							if(heroWord == "Black_Dragon.")
							{
								heroLine="";
							}
						}else if(heroWord == "Wizard" || heroWord == "Wizard."){
							newCreatureInventory[3] = creatureAmount;
							if(heroWord == "Wizard.")
							{
								heroLine="";
							}
						}else if(heroWord == "Archer" || heroWord == "Archer."){
							newCreatureInventory[2] = creatureAmount;
							if(heroWord == "Archer.")
							{
								heroLine="";
							}
						}else if(heroWord == "Vampire" || heroWord == "Vampire."){
							newCreatureInventory[1] = creatureAmount;
							if(heroWord == "Vampire.")
							{
								heroLine="";
							}
						}else if(heroWord == "Zombie" || heroWord == "Zombie."){
							newCreatureInventory[0] = creatureAmount;
							if(heroWord == "Zombie.")
							{
								heroLine="";
							}
						}
					}
					Players[count]->setCreaturesInventory(newCreatureInventory);
				}
				count++;
				HeroDetails.close();
			}

			//////
			/*while(i<numOfTheifs)
			{
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				Players[count]=new Thief(word);//catch wrong name exception
				i++;
				count++;
			}
			 */
			i=0;
			//////
			while(count<totalNumOfPlayers)
			{
				i=0;
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				Players[count]=new Necromancer(word);//catch wrong name exception
				string heroLine;
				fstream HeroDetails;
				string temp=Players[count]->getName();
				HeroDetails.open(("heroes//"+Players[count]->getName()+"/HeroData.txt").c_str(),fstream::in);
				if (!HeroDetails.is_open()){
					//THE FILE ISN'T OPEN
				}else{
					getline(HeroDetails,heroLine);
					getline(HeroDetails,heroLine);
					string heroWord;
					int spaceIndex = heroLine.find(" ", 0);
					heroWord = heroLine.substr(0, spaceIndex);
					heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
					Players[count]->setGoldAmount(atoi(heroWord.c_str()));
					getline(HeroDetails,heroLine);
					int creatureAmount=0;
					int newCreatureInventory[DISTINCTCREATURES];
					for (i=0;i<DISTINCTCREATURES;i++){
						newCreatureInventory[i]=0;
					}
					while (heroLine != "" && heroLine != "."){
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						creatureAmount=atoi(heroWord.c_str());
						spaceIndex = heroLine.find(" ", 0);
						heroWord = heroLine.substr(0, spaceIndex);
						heroLine = heroLine.substr(spaceIndex+1,heroLine.length());
						if (heroWord == "Black_Dragon" || heroWord == "Black_Dragon."){
							newCreatureInventory[4] = creatureAmount;
							if(heroWord == "Black_Dragon.")
							{
								heroLine="";
							}
						}else if(heroWord == "Wizard" || heroWord == "Wizard."){
							newCreatureInventory[3] = creatureAmount;
							if(heroWord == "Wizard.")
							{
								heroLine="";
							}
						}else if(heroWord == "Archer" || heroWord == "Archer."){
							newCreatureInventory[2] = creatureAmount;
							if(heroWord == "Archer.")
							{
								heroLine="";
							}
						}else if(heroWord == "Vampire" || heroWord == "Vampire."){
							newCreatureInventory[1] = creatureAmount;
							if(heroWord == "Vampire.")
							{
								heroLine="";
							}
						}else if(heroWord == "Zombie" || heroWord == "Zombie."){
							newCreatureInventory[0] = creatureAmount;
							if(heroWord == "Zombie.")
							{
								heroLine="";
							}
						}
					}
					Players[count]->setCreaturesInventory(newCreatureInventory);
				}
				count++;
				HeroDetails.close();
			}

			//////
			/*
			while(i<numOfNecromancers)
			{
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				Players[count]=new Necromancer(word);//catch wrong name exception
				i++;
				count++;
			}
			 */

			/*update turn array*/
			getline(GameDetails,line);
			for(i=0; i< totalNumOfPlayers; i++){
				int spaceIndex = line.find(" ", 0);
				word = line.substr(0, spaceIndex);
				line = line.substr(spaceIndex+1,line.length());
				turnArray[i] = atoi(word.c_str());
			}

			/*update hero turn*/
			getline(GameDetails,line);
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			heroTurnIndex = atoi(word.c_str());
			activePlayer = Players[heroTurnIndex]->getName();

			/*update if AlreaylreayTookTheMoney*/
			getline(GameDetails,line);
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			if(word == "1")
			{
				Players[heroTurnIndex]->setAlreayTookTheMoney(true);
			}
			else
			{
				Players[heroTurnIndex]->setAlreayTookTheMoney(false);
			}

			/*update if AlreayUsedSpecialSkill*/
			getline(GameDetails,line);
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			if(word == "1")
			{
				Players[heroTurnIndex]->setAlreayUsedSpecialSkill(true);
			}
			else
			{
				Players[heroTurnIndex]->setAlreayUsedSpecialSkill(false);
			}



			/*update number of round*/

			getline(GameDetails,line);
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			roundNumber = atoi(word.c_str());

			/*update counter rounds*/

			getline(GameDetails,line);
			spaceIndex = line.find(" ", 0);
			word = line.substr(0, spaceIndex);
			turnCounter = atoi(word.c_str());
		}

		GameDetails.close();
		//load list of players , player turn and turns array, round number from "game" folder
		//load heroes details from their folder
		//create heroes base on the details and heroes array

	}
	system("rm -r -f game");
	system("rm -r -f heroes");


	int ch1 = 0;
	while( ch1 != 7 ) {
		cout << "Welcome " << activePlayer << endl;
		cout << "What is your next step in the path to victory?" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Get daily gold" << endl;
		cout << "3. Buy creatures" << endl;
		cout << "4. Show details" << endl;
		cout << "5. Special skill" << endl;
		cout << "6. End of my turn" << endl;
		cout << "7. Exit" << endl;
		cin >> ch1 ;
		switch( ch1 )
		{
		case 1:
		{
			int ch2 = 0;
			cout<<"1. Show me my opponents"<<endl;
			cout<<"2. Attack hero"<<endl;
			cin>>ch2;
			switch( ch2 )
			{
			case 1:
			{
				//get details of all of the opponents
				string opponentDetails = "";
				int i;
				for (i=0; i<totalNumOfPlayers; i++){
					if (Players[i]->getName() != activePlayer){
						int k=0;
						bool notDead=false;
						for(k=0;k<totalNumOfPlayers;k++)
						{
							if(turnArray[k]==i)
							{
								notDead=true;
							}
						}
						if(notDead==true)
						{
							opponentDetails = opponentDetails + Players[i]->getNameAndType() +"\n";
						}

					}
				}
				opponentDetails = opponentDetails.substr(0,opponentDetails.length()-1);
				cout<<opponentDetails;
				cin.ignore();
				cin.ignore();
				break;
			}

			case 2:
			{
				if (roundNumber <= 3){
					cout<< "Can't attack before the forth round"<<endl;

				}else {
					bool opponentExists = false;
					int opponentIndex=-1;
					while (opponentExists == false){
						try{
							cout<<"Please insert your opponent name:"<<endl;
							string nameOfTheOpponent;
							cin>>ws;
							getline(cin,nameOfTheOpponent);
							int j;
							for (j=0; j < totalNumOfPlayers; j++){
								if (Players[j]->getName() == nameOfTheOpponent && nameOfTheOpponent != activePlayer){
									opponentExists = true;
									opponentIndex = j;
								}
							}
							if (opponentExists == false){
								throw "Hero doesn't exist";
							}
							bool notDead=false;
							int k=0;
							for(k=0;k<totalNumOfPlayers;k++)
							{
								if(turnArray[k]==opponentIndex)
								{
									notDead=true;
								}
							}
							if(notDead==false)
							{
								//###exception
								opponentExists = false;
								throw "Hero doesn't exist";
							}


						} catch (const char* notExistException){
							cout<<"Hero doesn't exist\n";
						}
						//throw bad name exception
						//catch
						//Print Something about the user being dumb
					}
					//here we have the opponent index

					int attackerTurn = 1; //first player attack turn
					while(!(Players[heroTurnIndex]->isDead()) && !(Players[opponentIndex]->isDead())) //while both alive
					{
						//print attacker getAllDetails
						if (attackerTurn == 1){
							Players[heroTurnIndex]->getDetails();
							cout << "\n";
							Players[opponentIndex]->getDetails();
							cout << Players[heroTurnIndex]->getName() << "'s turn:" << endl;
							bool opponentHasCreature = false;
							while (opponentHasCreature == false){
								try{
									string attackerCreature="";
									string opponentCreature="";
									cin>>attackerCreature;
									cin>>opponentCreature;
									if(attackerCreature == "Black_Dragon")
									{
										attackerCreature= "BlackDragon";
									}
									if(opponentCreature == "Black_Dragon")
									{
										opponentCreature= "BlackDragon";
									}

									Players[heroTurnIndex]->hasCreatureType(attackerCreature);
									Players[heroTurnIndex]->attack(*Players[opponentIndex], attackerCreature, opponentCreature);
									opponentHasCreature = true;
								} catch (const char* noCreature){
									cout << "Please enter a valid creature type\n";
								}
							}
							attackerTurn=2;
						}
						else
						{
							Players[opponentIndex]->getDetails();
							cout << "\n";
							Players[heroTurnIndex]->getDetails();
							cout << Players[opponentIndex]->getName() << "'s turn:" << endl;
							bool opponentHasCreature = false;
							while (opponentHasCreature == false){
								try{
									string attackerCreature="";
									string opponentCreature="";
									cin>>attackerCreature;
									cin>>opponentCreature;
									if(attackerCreature == "Black_Dragon")
									{
										attackerCreature= "BlackDragon";
									}
									if(opponentCreature == "Black_Dragon")
									{
										opponentCreature= "BlackDragon";
									}
									Players[opponentIndex]->attack(*Players[heroTurnIndex], attackerCreature, opponentCreature);
									opponentHasCreature=true;
								} catch (const char* noCreature){
									cout << "Please enter a valid creature type\n";
								}
							}
							attackerTurn=1;
						}
						//print opponent getAllDetails
						//attack first me then opponent until someone is dead!

					}
					if(Players[heroTurnIndex]->isDead() == true)//opponent won
					{
						int j,playerTurnIndex;
						for (j=0; j<totalNumOfPlayers; j++){
							if (turnArray[j] == heroTurnIndex){
								playerTurnIndex = j;
							}
						}
						turnArray[playerTurnIndex] =-1;
						//turnArray[heroTurnIndex] =-1;
						cout<<"You have been perished"<<endl;
						Players[opponentIndex]->gainGold(Players[heroTurnIndex]->getGoldAmount());
						//function
						bool foundNextPlayer=false;
						int previousTurn=turnCounter;
						while(foundNextPlayer==false)
						{
							turnCounter=(turnCounter+1)%totalNumOfPlayers;
							if(turnArray[turnCounter]!=-1)
							{
								foundNextPlayer=true;
							}
						}
						if(turnCounter<previousTurn)
						{
							roundNumber++;
						}
						heroTurnIndex = turnArray[turnCounter];
						activePlayer = Players[heroTurnIndex]->getName();

						bool onePlayeLeft=true;
						for(j=0;j<totalNumOfPlayers;j++)
						{
							if(turnArray[j]!=-1&&turnArray[j]!=opponentIndex)
							{
								onePlayeLeft=false;
							}
						}
						if(onePlayeLeft==true)
						{
							cout<<Players[opponentIndex]->getName()<<" is the winner!"<<endl;
							//close the program ###no save require?????
							int index=0;
							for(index=0;index<totalNumOfPlayers;index++)
							{
								delete Players[index];
							}
							delete [] Players;
							delete [] turnArray;
							return 0;
						}

						/*
						if(activePlayer == Players[opponentIndex]->getName())
						{
							cout<<Players[opponentIndex]->getName()<<" is the winner!"<<endl;
							int index=0;
							for(index=0;index<totalNumOfPlayers;index++)
							{
								delete Players[index];
							}
							delete [] Players;
							delete [] turnArray;
							return 0;
							//close the program ###no save require?????
						}
						 */
					}
					else// I won
					{
						Players[heroTurnIndex]->gainGold(Players[opponentIndex]->getGoldAmount());
						int j,opponentTurnIndex;
						for (j=0; j<totalNumOfPlayers; j++){
							if (turnArray[j] == opponentIndex){
								opponentTurnIndex = j;
							}
						}
						turnArray[opponentTurnIndex] =-1;
						cout<<"You have been victorious"<<endl;
						bool onePlayeLeft=true;
						for(j=0;j<totalNumOfPlayers;j++)
						{
							if(turnArray[j]!=-1&&turnArray[j]!=heroTurnIndex)
							{
								onePlayeLeft=false;
							}
						}
						if(onePlayeLeft==true)
						{
							cout<<activePlayer<<" is the winner!"<<endl;
							//close the program ###no save require?????
							int index=0;
							for(index=0;index<totalNumOfPlayers;index++)
							{
								delete Players[index];
							}
							delete [] Players;
							delete [] turnArray;
							return 0;
						}
						/*bool foundNextPlayer=false;
						int previousTurn=turnCounter;
						while(foundNextPlayer==false)
						{
							turnCounter=(turnCounter+1)%totalNumOfPlayers;
							if(turnArray[turnCounter]!=-1)
							{
								foundNextPlayer=true;
							}
						}
						if(turnCounter<previousTurn)
						{
							roundNumber++;
						}
						heroTurnIndex = turnArray[turnCounter];
						string activePlayerToChack="";
						activePlayerToChack = Players[heroTurnIndex]->getName();
						if(activePlayer == activePlayerToChack)
						{
							cout<<activePlayer<<" is the winner!"<<endl;
							//close the program ###no save require?????
							int index=0;
							for(index=0;index<totalNumOfPlayers;index++)
							{
								delete Players[index];
							}
							delete [] Players;
							delete [] turnArray;
							return 0;
						}
						else
						{
							activePlayer=activePlayerToChack;
						}
						 */


					}
					break;


				}

			}
			}
			break;
		}

		case 2:
		{
			/*update the dailyGold*/
			Players[heroTurnIndex]->getMoney();
			break;
		}

		case 3:
		{
			int ch3 = 0;

			cout<<"1. Buy Zombie."<<endl;
			cout<<"2. Buy Archer."<<endl;
			cout<<"3. Buy Vampire."<<endl;
			cout<<"4. Buy Wizard."<<endl;
			cout<<"5. Buy Black Dragon."<<endl;
			cin>>ch3;
			switch( ch3 )
			{
			case 1:
			{
				cout<<"Attack level: "<<Zombie::powerAttack<<", Defense level: "<<Zombie::powerDefense<<endl;
				int amountOfCreatures=0;
				try{
					cin>>amountOfCreatures;
					Players[heroTurnIndex]->buyCreature("Zombie",amountOfCreatures); //try catch
				}catch(const char* notEnoughMoney){
					cout<<"Not enough money"<<endl;
				}
				break;
			}

			case 2:
			{
				cout<<"Attack level: "<<Archer::powerAttack<<", Defense level: "<<Archer::powerDefense<<endl;
				int amountOfCreatures=0;
				try{
					cin>>amountOfCreatures;
					Players[heroTurnIndex]->buyCreature("Archer",amountOfCreatures); //try catch
				}catch(const char* notEnoughMoney){
					cout<<"Not enough money"<<endl;
				}
				break;

			}


			case 3:
			{
				cout<<"Attack level: "<<Vampire::powerAttack<<", Defense level: "<<Vampire::powerDefense<<endl;
				int amountOfCreatures=0;
				try{
					cin>>amountOfCreatures;
					Players[heroTurnIndex]->buyCreature("Vampire",amountOfCreatures); //try catch
				}catch(const char* notEnoughMoney){
					cout<<"Not enough money"<<endl;
				}
				break;
			}


			case 4:
			{
				cout<<"Attack level: "<<Wizard::powerAttack<<", Defense level: "<<Wizard::powerDefense<<endl;
				int amountOfCreatures=0;
				try{
					cin>>amountOfCreatures;
					Players[heroTurnIndex]->buyCreature("Wizard",amountOfCreatures); //try catch
				}catch(const char* notEnoughMoney){
					cout<<"Not enough money"<<endl;
				}
				break;
			}

			case 5:
			{
				cout<<"Attack level: "<<BlackDragon::powerAttack<<", Defense level: "<<BlackDragon::powerDefense<<endl;
				int amountOfCreatures=0;
				try{cin>>amountOfCreatures;
				Players[heroTurnIndex]->buyCreature("BlackDragon",amountOfCreatures); //try catch
				}catch(const char* notEnoughMoney){
					cout<<"Not enough money"<<endl;
				}
				break;
			}
			}
			break;
		}

		case 4: /*show details of the hero*/
		{
			cout << Players[heroTurnIndex]->getAllDetails();
			break;
		}

		case 5: /*special ability*/
		{
			if(Players[heroTurnIndex]->getAlreayUsedSpecialSkill()==false)
			{
				if(Players[heroTurnIndex]->getType()== "Thief")
				{
					bool canSteal=false;
					while(canSteal==false)
					{
						try{
							string playerToStealFrom="";
							cout<<"Please insert hero name:"<<endl;
							cin>>ws;
							getline(cin,playerToStealFrom);
							bool foundPlayer=false;
							int i=0;
							for(i=0;i<totalNumOfPlayers && foundPlayer == false;i++)
							{
								if(Players[i]->getName()==playerToStealFrom && Players[i]->getName()!=activePlayer)
								{
									foundPlayer=true;
								}
							}
							bool notDead=false;
							int k=0;
							for(k=0;k<totalNumOfPlayers;k++)
							{
								if(turnArray[k]==i-1)
								{
									notDead=true;
								}
							}
							if(foundPlayer == false || notDead==false)
							{
								//###exception
								throw "can't steal";
							}
							else
							{
								((Thief*)Players[heroTurnIndex])->specialSkill(*Players[i-1]);
								canSteal=true;
							}
						}catch(const char* cantSteal){
							cout<<"Can't steal from hero."<<endl;
						}
					}

				}
				else
				{
					Players[heroTurnIndex]->specialSkill();
				}
			}
			break;
		}

		case 6: /*End turn switch to the next Hero*/
		{
			Players[heroTurnIndex]->setAlreayUsedSpecialSkill(false);
			Players[heroTurnIndex]->setAlreayTookTheMoney(false);
			bool foundNextPlayer=false;
			int previousTurn=turnCounter;
			while(foundNextPlayer==false)
			{
				turnCounter=(turnCounter+1)%totalNumOfPlayers;
				if(turnArray[turnCounter]!=-1)
				{
					foundNextPlayer=true;
				}
			}
			if(turnCounter<previousTurn)
			{
				roundNumber++;
			}
			heroTurnIndex = turnArray[turnCounter];
			activePlayer = Players[heroTurnIndex]->getName();
			break;
		}

		case 7: /*exit save the game*/
		{
			//	int game = mkdir(filePath+"/game", S_IRWXU | S_IRWXG | S_IRWXO);
			string PlayersOrder="";
			string turnArrayOrder = "";
			int game = mkdir("game", ACCESSPERMS);
			int heroes=mkdir("heroes", ACCESSPERMS);
			int i=0;
			for(i=0;i<totalNumOfPlayers;i++)
			{
				string newFolder = "heroes/"+Players[i]->getName();
				mkdir(newFolder.c_str(), ACCESSPERMS);
				fstream HeroDetails;
				string fileName = newFolder+"/HeroData.txt";
				HeroDetails.open(fileName.c_str(),fstream::out);
				HeroDetails<<Players[i]->getAllDetails();
				HeroDetails.close();
				PlayersOrder = PlayersOrder + Players[i]->getName() + " ";
				char str[21];
				sprintf(str, "%d", turnArray[i]);
				turnArrayOrder = turnArrayOrder + str + " ";

			}
			PlayersOrder = PlayersOrder+"\n";
			turnArrayOrder = turnArrayOrder+"\n";
			fstream GameDetails;
			GameDetails.open("game/GameData.txt",fstream::out);
			GameDetails<<totalNumOfPlayers<< " "<< numOfWarriors << " " << numOfTheifs << " " << numOfNecromancers << endl;
			/*PLAYRS*/
			GameDetails<<PlayersOrder;
			/*ORDER TURNS*/
			GameDetails<<turnArrayOrder;
			/*TURN HERO NUMBER*/
			GameDetails<<heroTurnIndex << endl;
			/*TheMoney*/
			GameDetails<<Players[heroTurnIndex]->getAlreayTookTheMoney()<< endl;
			/*SpecialSkill*/
			GameDetails<<Players[heroTurnIndex]->getAlreayUsedSpecialSkill()<< endl;
			/*ROUND NUMBER*/
			GameDetails<<roundNumber<< endl;
			/*TURN COUNTER*/
			GameDetails<<turnCounter<< endl;

			GameDetails.close();

			int index=0;
			for(index=0;index<totalNumOfPlayers;index++)
			{
				delete Players[index];
			}
			delete [] Players;
			delete [] turnArray;
			break;
		}



		}

	}

	return 0;//EXIT_SUCCESS;
}
/*
void updateHeroCreatureInventory(string heroType, int count, int numOfHero, Hero** Players){

}
 */
