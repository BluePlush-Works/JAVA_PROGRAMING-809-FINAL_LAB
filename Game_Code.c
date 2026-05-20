#include <iostream>
#include <random>
using namespace std;

//Calling the methods
void start_menu();
void build_map();
void draw_map();
void user_choice_map();
void random_enemy();
void draw_enemy_cat();
void draw_enemy_bat();
void draw_enemy_rat();

//Global Variables
char Map[12][10];
int Player_x; int Player_y;

//Main of the program
int main() {
  
	bool quit = false; bool game_over = false;
    int option;
    build_map();
    
    while(quit == false){
	    start_menu();
        
        cout << "Option: ";
        cin >> option;
        
        switch(option){
        	case 1:
				while(game_over == false){
					cout << "\n\n";
					draw_map();
					user_choice_map();
				}
                break;
            case 2:
            	cout << "\n\nComand Line Crawler takes the bases of a dungeon crawler and attempts to replicate it, coded all in C++, and made to run on the comand console.";
                break;
            case 3:
            	cout << "\n\nGoodbye!\n";
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
	for (int i = 0; i < 12; i++) //Y
	{
		for (int j = 0; j < 10; j++) //X
		{
			Map[i][j] = '   ';
		}
	}
    Map[0][0] = 'O';
    Player_x = 0;
    Player_y = 0;
}

void draw_map(){
	
    printf("-----------------------------------------\n");
    for (int i = 0; i < 12; i++) //Y
	{
		printf("|");
        for (int j = 0; j < 10; j++) //X
		{
			printf(" %c ", Map[i][j]);
			if (j < 10) printf("|");
		}
	
		printf("\n");
		
		if (i < 12) printf("-----------------------------------------\n");
	}
}

//Player Menu
void user_choice_map(){
	int player_choice; int x; int y;
	cout << "\n\nWhat would you like to do?\n";
    cout << "1 - Move Up.\n";
    cout << "2 - Move Left.\n";
    cout << "3 - Move Right.\n";
    cout << "4 - Move Down.\n\n";
    
    cout << "Option: ";
    cin >> player_choice;
    cout << "\n\n";
    
    switch(player_choice){
        	case 1: //Up
            	if(Player_y == 0){
					cout << "Cannot go up more.\n";
					cout << "Booting back up the map...\n";
				}else{
					Map[Player_y - 1][Player_x] = 'O';
					Map[y][x] = ' ';
					Player_y = y - 1
				}
                break;
            case 2: //Left
            	if(Player_x == 0){
					cout << "Cannot go down more.\n";
					cout << "Booting back up the map...\n";
				}else{
					Map[Player_y][Player_x - 1] = 'O';
					Map[y][x] = ' ';
					Player_x = x - 1;
				}
                break;
            case 3: //Right
            	if(Player_x == 9){
					cout << "Cannot go down more.\n";
					cout << "Booting back up the map...\n";
				}else{
					Map[Player_y][Player_x + 1] = 'O';
					Map[y][x] = ' ';
					Player_x = x + 1;
				}
                break;
            case 4: //Down
            	if(Player_y == 11){
					cout << "Cannot go down more.\n";
					cout << "Booting back up the map...\n";
				}else{
					Map[Player_y + 1][Player_x] = 'O';
					Map[y][x] = ' ';
					Player_y = y + 1;
				}
                break;
            default:
            	cout << "Error. Invalid Choice.\n";
                cout << "Booting back up the map...\n";
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
