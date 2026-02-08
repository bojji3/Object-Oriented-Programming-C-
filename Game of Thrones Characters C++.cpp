// =================================================
// Filename : Sandejo_Visaya_LE1.cpp
// Author(s) : Edmund Sandejo, Kristina Visaya
// Email : esandejo@adnu.edu.ph , kvisaya@gbox.adnu.edu.ph
// Exercise Number : 1
// Assignment Number : 
//Description : The program allows the user to input information about a character from Game of Thrones, then displays the output.
//Last modified: January 26, 2023
//=================================================

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME_LEN = 100;

struct Character {
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    char houseName[MAX_NAME_LEN];
    char actorName[MAX_NAME_LEN];
};

void ReadCharacter(Character *c) {
    cout << "Enter first name: ";
    cin.getline(c->firstName, MAX_NAME_LEN);
    cout << "Enter last name: ";
    cin.getline(c->lastName, MAX_NAME_LEN);
    cout << "Enter house name: ";
    cin.getline(c->houseName, MAX_NAME_LEN);
    cout << "Enter actor name: ";
    cin.getline(c->actorName, MAX_NAME_LEN);
}

void Print(Character c) {
    cout << "First name: " << c.firstName << endl;
    cout << "Last name: " << c.lastName << endl;
    cout << "House name: " << c.houseName << endl;
    cout << "Actor name: " << c.actorName << endl;
}
int main() {
    int numCharacters;
    cout << "Enter the number of characters:";
    
    cin >> numCharacters;
    cin.ignore(); // to consume the newline character from the previous input
    Character *characters = new Character[numCharacters];
    for (int i = 0; i < numCharacters; i++) {
        ReadCharacter(&characters[i]);
        Print(characters[i]);
    }
    delete[] characters;
    return 0;
}