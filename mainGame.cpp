#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int StoryText();
string AddSpace(string space, int countSpace);
string RemoveSpace(string space, int countSpace);
void SkipLine(int countSkips);
void WriteText(string text);
void LoadMap();
void SetMap();
int ActionsList();
void PlayerMove(char side);
bool TryToFight();

int randNum = rand();// 0 32767
enum GameAction {
	History,
	Game,
	Fight
};
GameAction nowGameAction = History;

enum SetActionList{
	Main,
	Move,
	FightUI,
};
SetActionList nowAction = Main;

extern string space;
extern char setActive;
	
int GameStart() {
	srand(static_cast<unsigned int>(time(0)));
	while(true){
		switch(nowGameAction){
			
			case History : 
				StoryText();
				system("cls");
			break;
			
			case Game : 
				system("cls");
				
				cout << randNum;
				LoadMap();
				ActionsList();
			break;
			
			case Fight :
				system("cls");
				cout << randNum;
				LoadMap();
				ActionsList();
			break;
		}
	}
}
bool TryToFight(){
	randNum = rand();
	if(randNum >= 25000){
	nowGameAction = Fight;
	nowAction = FightUI;
	return 1;
	}
	return 0;
}

int ActionsList(){
	SkipLine(3);
	switch(nowAction){
		
		case Main :
			cout << RemoveSpace(space, 15)<< "1. move" << RemoveSpace(space,10) << "2. inventory" << RemoveSpace(space,10)<< "3. stats";
			SkipLine(2);
			cout << RemoveSpace(space,18)<< "4. locate inf" << RemoveSpace(space,12) << "5. map inf" << RemoveSpace(space,8)<< "6. menu";
			SkipLine(4);
						
			cout << AddSpace(space,10) << "Select action: ";
			cin >> setActive;
			
			switch(setActive){
				case '1' : 
					nowAction = Move;
					return 0;
				break;
				
				case '2' : 
					
				break;
				
				case '3' : 
					
				break;
				
				case '4' : 
					
				break;
				
				case '5' : 
					
				break;
				
				case '6' : 
					
				break;
			}
		break;
		
		case Move : 
			cout << RemoveSpace(space, 15)<< "w. move up" << RemoveSpace(space,15) << "s. move down" << RemoveSpace(space,15) << "d. move right";
			SkipLine(2);
			cout << RemoveSpace(space,15)<< "a. move left" << RemoveSpace(space,15)  << "e. use" << RemoveSpace(space,15) << "q. cancel";
			SkipLine(4);
			
			cout << AddSpace(space,10) << "Select action: ";
			cin >> setActive;
			PlayerMove(setActive);
			return 0;
		break;
		case FightUI :
			cout << RemoveSpace(space, 15)<< "1. skills" << RemoveSpace(space,15) << "2. inventory" << RemoveSpace(space,15) << "3. explore enemy";
			SkipLine(2);
			cout << RemoveSpace(space,15)<< "4. " << RemoveSpace(space,15)  << "5. stats" << RemoveSpace(space,15) << "6. menu";
			SkipLine(4);
			
			cout << AddSpace(space,10) << "Select action: ";
			cin >> setActive;
			return 0;
		break;
	} 
}

int StoryText(){
	 WriteText("This strory about man ");
	 WriteText("Man how coudnt do anything ");
	 WriteText("But now he doesnt remember how is he ");
	 WriteText("New day new life new story for new man ");
	 WriteText("Welkom to the Talk_to_Live (talk or dead) ");
	nowGameAction = Game;
	return 0;
}

void WriteText(string text){
	system("cls");
	SkipLine(7);
	cout << space << text;
	cin >> setActive;
}