#include <iostream>
#include <random>
using namespace std;

//Calling the methods
void start_menu();
void build_map();
void draw_map();
void random_enemy();
void draw_enemy_cat();
void draw_enemy_bat();
void draw_enemy_rat();

//Global Variables
char Map[12][10];

//Main of the program
int main() {
  
	bool quit = false;
    int option;
    
    while(quit == false){
	    start_menu();
        
        cout << "Option: ";
        cin >> option;
        cout << "\n\n";
        
        switch(option){
        	case 1:
            	quit = true;
                break;
            case 2:
            	cout << "Comand Line Crawler takes the bases of a dungeon crawler and attempts to replicate it, coded all in C++, and made to run on the comand console.";
                break;
            case 3:
            	cout << "Goodbye!\n";
                cout << "And Thank You for playing!";
                quit = true;
                break;
            default:
            	cout << "Error. Invalid Number Detected.\n";
                cout << "Restarting...\n";
        }
    }
}

//The game's Main Menu
void start_menu() {
	cout << "\n\n=====Comand Line Crawler=====\n\n";
	cout << "What would you like to do?\n";
    cout << "1 - Play\n";
	cout << "2 - About Game\n";
    cout << "3 - Quit\n\n";
}

//Map Related Methods
void build_map(){
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Map[i][j] = '   ';
		}
	}
}

void draw_map(){
	
    printf("-----------------------------------------\n");
    for (int i = 0; i < 11; i++)
	{
		printf("|");
        for (int j = 0; j < 9; j++)
		{
			printf(" %c ", Map[i][j]);
			if (j < 9) printf("|");
		}
	
		printf("\n");
		
		if (i < 12) printf("-----------------------------------------\n");
	}
}

//Randomise the Enemy Encountered
void random_enemy() {

	// Random Number Generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 2);
    int rng = distrib(gen);
	
	if(rng == 0){
		draw_enemy_cat();
	}else if(rng == 1){
		draw_enemy_bat();
	}else{
		draw_enemy_rat();
	}
}

//Enemy "Art"

//Cat
void draw_enemy_cat() {
	cout << "  /\\     /\\ \n";
	cout << " ----------- \n";
	cout << "|           |\n";
	cout << "|  |     |  |\n";
	cout << "|     ^     |\n";
	cout << "|           |\n";
	cout << "|     W     |\n";
	cout << " ----------- \n";
	cout << "|           |  _______\n";
	cout << "|           | |  __   |\n";
	cout << "|           | | |  |  |\n";
	cout << "| | |   | | |  -___|  |\n";
	cout << "| | |   | | |___   ___|\n";
	cout << "|  -     -  |   ___\n";
	cout << "|           |___\n";
	cout << "|  _     _  |\n";
	cout << "| | |   | | |\n";
	cout << " ----------- \n";
}

//Bat
void draw_enemy_bat() {
	cout << "----                                    ----\n";
    cout << "|   ------         ______         ------   |\n";
    cout << " ----     --------|      |--------     ---- \n";
    cout << "     -----        | |  | |        -----     \n";
    cout << "          --------| ____ |--------          \n";
    cout << "                  | \\/\\/ |\n";
    cout << "                  |      |\n";
    cout << "                  --------\n";
    cout << "                    |  |  \n";
    cout << "                   / \\/ \\  \n";
}

//Rat
void draw_enemy_rat() {
	cout << "    __         __    \n";
    cout << "   |  |       |  |   \n";
    cout << " ------------------- \n";
    cout << "|                   |\n";
    cout << "|   ___       ___   |\n";
    cout << "|  | | |     | | |  |\n";
    cout << "|  | | |     | | |  |\n";
    cout << "|   ---       ---   |\n";
    cout << "|        / \\        |        ----\n";
    cout << "|        ---        |    ----\n";
    cout << "|         |         |----\n";
    cout << "|   _     W     _   |\n";
    cout << "|  | |         | |  |\n";
    cout << " ------------------- \n";
}
