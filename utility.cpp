#include <iostream>
#include <iomanip>
#include <fstream>
#include "draw.h"
using namespace std;

void generateWord(string& word, string& hint)
{
    string difficulty;
    string theme;
    cout << "Please choose your difficulty (easy, medium, hard): ";
    do {
        cin >> difficulty;
        if (difficulty != "easy" && difficulty != "medium" && difficulty != "hard") cout << "Please re-enter the difficulty (easy, medium, hard): ";
    } while (difficulty != "easy" && difficulty != "medium" && difficulty != "hard");
    clearScreen();
    cout << "Choose a theme: " << endl
        << "1. Animals" << endl << "2. Vehicles" << endl << "3. Jobs" << endl << "4. Military" << endl;
    cout << "Choose (1,2,3,4): ";
    do {
        cin >> theme;
        if (theme != "1" && theme != "2" && theme != "3" && theme != "4") cout << "Please re-enter your theme (1, 2, 3, 4): ";
    } while (theme != "1" && theme != "2" && theme != "3" && theme != "4");
    clearScreen();
    ifstream file;
    string fileName = difficulty + theme + ".txt";
    file.open(fileName);
    if (!file) cout << "ERROR!! UNABLE TO OPEN WORD LIST." << endl;
    else{
        int n;
        file >> n;
        srand(time(0));
        int index = rand() % n;
        string data;
        getline(file, data);
        for (int i = 0; i < index; i++){
            getline(file, word, ',');
            file.ignore();
            getline(file, hint, ';');
            getline(file, data);
        }
        file.close();
    }
}

void welcomeHeadline(int& charCount)
{
    cout << "WELCOME TO HANGMAN." << endl;
    cout << "YOU HAVE 6 TRIES AND 1 MINUTE TO GUESS THE WORD." << endl;
    cout << "IF YOU LOSE THEN YOU ARE DUMB AS FUCK." << endl;
    cout << "THIS WORD HAS " << charCount << " LETTER." << endl;

}

void displayClock(int sec)
{
    clearScreen();

    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    cout << setfill(' ') << setw(29);
    cout << setw(40) << "| " << sec << " secs | " << endl;
    cout << setfill(' ') << setw(55) << " --------------------------\n";
}