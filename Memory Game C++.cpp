// =================================================
// Filename : Visaya_PA1.cpp
// Author(s) : Kristina Visaya
// Email : kvisaya@gbox.adnu.edu.ph
// Exercise Number : 
// Assignment Number : 1
//Description : The program allows the user to play the memory card game.
//Last modified: February 16, 2023
//=================================================
#include <windows.h>
#include<iostream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>
#include <bitset>

using namespace std;

//Class
class MemoryGameFinal
{
protected:

	//Declare global variables
	int points = 0, point = 0;
	string firstName;
	char difficuty;
	int column, row, row1Value, column1Value, row2Value, column2Value, matrix[10][10];
	int menu;
	bool again = true;
	bool matrix2[10][10];
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

public:

	// Display the cards
	void display()
	{
		// Easy grid setup
		cout << "    1 2 3 4 5 6 7 8 9 10" << endl;
		cout << "  ";

		for (int i = 0; i <= 20; i++) {
			cout << "-";
		}
		cout << endl;

		//More setup
		for (int row = 0; row < 10; row++) {
			cout << row + 1 << " | ";

			for (int column = 0; column < 10; column++) {
				// Print the value or '*' depending on wether the card
				// is exposed.
				if (matrix2[row][column]) {
					cout << matrix[row][column];
				}
				else {
					cout << '*';
				}
				cout << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}

	void start()
	{
		// The first few lines are only printed once.
		SetConsoleTextAttribute(color, 9);
		cout << "Welcome to Memory - The Card Game" << endl << endl;

		// Select game
		SetConsoleTextAttribute(color, 7);
		cout << "Please enter your first name" << endl;
		cin >> firstName;

		//Main Menu
		while (again) {
			cout << "Welcome, " << firstName << "!" << endl;
			cout << endl << endl;
			cout << "Game Menu" << endl;
			cout << " ********************" << endl;
			cout << "Select 1 for a New Game and 2 to Exit Game" << endl;
			cout << "1. New Game" << endl;
			cout << "2. Exit Game" << endl;
			cout << " ********************" << endl;
			cin >> menu;

			//Option to exit game and reasks the user to play again
			if (menu == 2) {
				cout << endl;
				cout << "Would you like to play Memory - The Card Game again?" << endl;
				cout << "Type '1' to play again and '0' to leave" << endl;
				cin >> again;
				cout << endl;
			}
			// Option to start game and difficulty selection
			else if (menu == 1) {
				// Game grid selection
				cout << endl << "Difficulty level selection" << endl;
				cout << "*******************************" << endl;
				cout << "For an Easy Game type 'e' ( 4x4 grid )" << endl;
				cout << "For an Intermediate Game type 'i' ( 6x6 grid )" << endl;
				cout << "*******************************" << endl;

				cin >> difficuty;

				//Switch statement which determines the grid setup for
				//the chosen game
				switch (difficuty) {
					//Case easy
				case 'e':
					srand((unsigned int)time(NULL));
					//Dictates number of columns and rows
					for (int row = 0; row < 10; row++) {
						for (int column = 0; column < 10; column++) {
							//Initialize a random matrix
							matrix[row][column] = rand() % 20 + 1;
							matrix2[row][column] = false;
						}
						cout << endl;
					}
					cout << "Easy Game" << endl;
					cout << "Points: " << points << endl;

					// display the board
					display();

					//Initalize the  game function after setup
					Loop();

					//End of case easy
					break;
				}
			}
		}
	}

	// game function
	void Loop()
	{
		while (points != 100) {
			//Prompt
			cout << firstName << ", please enter a row value for first card: "
				<< endl;
			cin >> row1Value;

			cout << firstName <<
				", please enter a column value for first card: " << endl;
			cin >> column1Value;

			cout << firstName <<
				", please enter a row value for second card: " << endl;
			cin >> row2Value;

			cout << firstName <<
				", please enter a column value for second card: " << endl;
			cin >> column2Value;
			cout << endl;

			//Decrease the number value as the rows and columns go down
			row1Value--;
			column1Value--;
			row2Value--;
			column2Value--;

			// Temporarily expose the cards
			matrix2[row1Value][column1Value] = true;
			matrix2[row2Value][column2Value] = true;

			// display the board
			display();

			// Initializes the function for matching results
			Match();
		}

		// When you get here, points == 100
		system("cls");
		cout << "Thank you for completing my game " << firstName
			<< "!" << endl << endl;
	}

	//Match in  game function
	void Match()
	{
		//Check condition
		if (matrix[row1Value][column1Value] == matrix[row2Value][column2Value]) {	//If there is a match
			// Leave them exposed
			points = points + 2;
			SetConsoleTextAttribute(color, 4);
			cout << "Congratulations!" << endl;
			cout << "Your Two Cards Match!" << endl << endl;
			SetConsoleTextAttribute(color, 7);
			cout << "Points: " << points << endl << endl;	//update points
		}
		else {
			SetConsoleTextAttribute(color, 4);
			cout << "Oh No!" << endl;
			cout << "Your Two Cards Do Not Match!" << endl << endl;
			SetConsoleTextAttribute(color, 7);
			cout << "Points: " << points << endl << endl;	//update points

			// Cover them up again
			matrix2[row1Value][column1Value] = false;
			matrix2[row2Value][column2Value] = false;
		}
	}
};

// Executable code for the whole program
int main()
{

	MemoryGameFinal Game;
	Game.start();

}