#include <iostream>
#include <string>

using namespace std;


string AddSpace(string space, int countSpace);
string RemoveSpace(string space, int countSpace);
void SkipLine(int countSkips);
int LoadMenu();
int LoadSettings();
int LoadCredits();
int GameStart();
int countPages = 2;
int nowPage = 1;
int lastPage = 0;
char setActive = 0;
int difficult = 1;
string space = "                              ";
enum place {
	Menu,
	Game,
	Settings,
	Tutorial,
	Credits,
	Exit
};
place nowPlace = Menu;



//точечный шрифт размер 8х12  Teminal размер буфера экрана 80 300 размер окна 80 25 положение 322 174

int main(int argc, char** argv) {

	while(true){

		switch(nowPlace){
			case Menu :
				LoadMenu();
				system("cls");
			break;

			case Game :
				GameStart();
				return 0;
			break;

			case Settings :
				LoadSettings();
				system("cls");
			break;

			case Credits :
				LoadCredits();
				system("cls");
			break;

			case Exit :
				return 0;
			break;
		}
	}

	return 0;
}

int LoadMenu(){
	SkipLine(6);
	cout << AddSpace(space,1) << "Welkom to the --Talk_to_Live--" << endl;
	cout << space <<"________________________________" << endl;
	cout << endl;
	cout << space << "1. New Game" << endl;
	cout << space << "2. Load last game (doesn't work)" << endl;
	cout << space << "3. Settings" << endl;
	cout << space << "4. Tutorial" << endl;
	cout << space << "5. Credits" << endl;
	cout << space << "6. Exit game" << endl;
	SkipLine(2);
	cout << AddSpace(space, 1) << "Select action: ";
		cin >> setActive;

		switch(setActive){
			case '1':
				nowPlace = Game;
				return 0;
			break;

			case '2':
				//загрузить старую игру
			break;

			case '3':
				nowPlace = Settings;
				return 0;
			break;

			case '4':
				//открыть инструкцию по игре
			break;

			case '5':
				nowPlace = Credits;
				return 0;
			break;

			case '6':
				system("cls");
				SkipLine(10);
				cout << AddSpace(space, 6) << "See you next time !";
				SkipLine(2);
				cout << AddSpace (space, 14) << ":)";
				cin >> setActive;
				nowPlace = Exit;
				return 0;
			break;
			
			default : 
			return 0;
			break;
		}
}

int LoadCredits(){

	

	switch(nowPage){
			case 1:
					system("cls");
					SkipLine(7);
					cout << AddSpace(space,8) << "Game made by ???";
					SkipLine(10);
					cout << space << "1. back page" << endl;
					cout << space << "2. next page" << endl;
					cout << space << "3. close" << endl;
					cout << endl;
			break;

			case 2:
				
					system("cls");
					SkipLine(7);
					cout << AddSpace(space,10) << "Used Assets: ";
					cout << endl;
					cout << AddSpace(space, 13) << "no one";
					SkipLine(10);
					cout << space << "1. back page" << endl;
					cout << space << "2. next page" << endl;
					cout << space << "3. close" << endl;
					
					cout << endl;
				
			break;
		}
	cout << endl;
	cout << space << "Action(now page " << nowPage <<"/"<< countPages<<"): ";

		cin >> setActive;


		switch(setActive){
			case '3' :
				nowPlace = Menu;
				nowPage = 1;
				return 0;
			break;

			case '2':
				nowPage++;
				if(nowPage > countPages){
					nowPage = countPages;
				}

			break;

			case '1':
				nowPage--;
				if(nowPage == 0){
					nowPage = 1;
				}
			break;
			
			default : 
			return 0;
			break;
		}

	 

}

int LoadSettings(){
	SkipLine(7);
	cout << AddSpace(space,10) << "--Settings--" << endl;
	cout << space <<"________________________________" << endl;
	cout << endl;
	cout << space << "1. Ease" << endl;
	cout << space << "2. Normal" << endl;
	cout << space << "3. Hard" << endl;
	cout << space << "4. Close Settings" << endl;
	SkipLine(2);
	cout << AddSpace(space, 1) << "Select difficalt (now set " << difficult << "): ";

		cin >> setActive;
		system("cls");
		SkipLine(10);
		switch(setActive){

			case '1':
				difficult = 1;
				cout << AddSpace(space,9) << "Ease selected !";

			break;
			
			case '2':
				difficult = 2;
				cout << AddSpace(space,7) << "NORMAL selected !!";
			break;
			
			case '3':
				difficult = 3;
				cout << AddSpace(space,8) << "HARD SELECTED !!!";

			break;
			
			case '4':
				nowPlace = Menu;
				return 0;
			break;
			default : 
			return 0;
			break;

		}
		cin >> setActive;
		nowPlace = Menu;
		return 0;
}

void SkipLine(int countSkips){
	for(int i = 0; i < countSkips; i++){
		cout << endl;
 	}
 }

string AddSpace(string space, int countSpace){
	string newSpace = space;
	for(int i = 0; i < countSpace; i++){
		newSpace = newSpace + " ";
	}
	return newSpace;
}

string RemoveSpace(string space, int countSpace){
	string newSpace = space;
	for(int i = 0; i < countSpace; i++){
		newSpace.erase(newSpace.size()-1);
	}
	return newSpace;
}