#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <conio.h>
#include <Windows.h>
#include <map>


#include "MMSystem.h"
#include "draw.h"
#include "utility.h"
#include "highscore.h"
#include "AI.h"
using namespace std;

string inputChar(vector<char>&  checkGuess, string& genWord); //nhập input của người dùng và check với các điều kiện khác
void welcomeHeadline(int& charCount); //in ra màn hình 1 welcome statement
void printGuessLetter(vector<char>& checkGuess); //in ra những từ đã được ng chơi đoán
void renderGame();


int main()
{
    Color(10);
    bool continueGame = true;
    string gameOption;
    cout << "Do you want to play Vs Computer or Normal Hangman?(AI || normal): ";
    cin >> gameOption;
    if (gameOption == "AI") {
        while (continueGame == true) {
            simpleAI();
            char playerDes;
            cout << "Do you want to play again?(Y|N): ";
            cin >> playerDes;
            if (playerDes == 'y') {
                continueGame = true;
                clearScreen();
            }
            else continueGame = false;
        }
    }
    else {
        while (continueGame == true) {
            renderGame();
            char playerDes;
            cout << "Do you want to play again?(Y|N): ";
            cin >> playerDes;
            playerDes = char(tolower(playerDes));
            if (playerDes == 'y') {
                continueGame = true;
                clearScreen();
            }
            else continueGame = false;
        }
    }
}



string inputChar(vector<char>& checkGuess, string& genWord)
{
    string guess;
    int check = 0;
    do{
        cout << "Your guess: ";
        cin >> guess;
        if (char(tolower(guess[0])) < 97 || char(tolower(guess[0])) > 122){
            cout << "This is not a character. Try again." << endl;
        }
        else{
            for (int i = 0; i < checkGuess.size(); i++){
                if (guess.length() == 1 && guess[0] == checkGuess[i]){
                    cout << "You have already guess this letter. Try again." << endl;
                    check++;
                    break;
                }
            }
        }
    } while((char(tolower(guess[0])) < 97 || char(tolower(guess[0])) > 122));
    if (check == 0) checkGuess.push_back(char(tolower(guess[0])));
    return guess;
}



void printGuessLetter(vector<char>& checkGuess)
{
    cout << "Guesses letter: ";
    for (int j = 0; j < checkGuess.size(); j++){
        cout << checkGuess[j] << ", " ;
    }
    cout << endl;
}


void renderGame()
{   
    player p;
    cout << "Please enter your name: ";
    cin >> p.name;
    int point = 0;
    int check = 0;
    int sec = 60;
    string genWord, hint;
    generateWord(genWord, hint);
    int wordLen = genWord.length(); //lấy độ dài từ đc generate
    string str = string(wordLen, '-');
    vector<char> checkGuess;
    std::chrono::time_point<std::chrono::system_clock> startTimer;
    startTimer = std::chrono::system_clock::now();
    __int64 secondsElapsed;

    welcomeHeadline(wordLen);

    bool insertHint = false;
    while (point <= 7){
        secondsElapsed = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - startTimer).count();
        displayClock(60 - secondsElapsed);
        if (secondsElapsed > 60) {
            clearScreen();
            cout << "Sorry but your time is up :(" << endl;
            cout << "Your time is: " << secondsElapsed << 's' << endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            gameLoseAnim(genWord);
            break;
        }
        if (str == genWord){
            check++;
            break;
        }
        if (point > 0){
            printHangman(point);
            printGuessLetter(checkGuess);
        }

        //Nếu point lớn hơn 5 thì hỏi ng chơi có cần hint không
        bool checkHint = false;
        char tmp;
        if (point >= 5 && insertHint == false){
            cout << "Do you want a hint?(Y|N): ";
            cin >> tmp;
            tmp = char(tolower(tmp));
            if (tmp == 'y'){
                checkHint = true;
                insertHint = true;
            }
        }
        if (checkHint == true){
            cout << "Hint is: " << hint << endl;
        }
        cout << endl << str << endl;
        string guess = inputChar(checkGuess, genWord);
        if (guess.length() == 1 && genWord.find_first_of(guess[0]) == string::npos){
            point++;
        }
        else if (guess == genWord){
            check++;
            break;
        }
        else if (guess.length() > 1 && guess != genWord){
            gameLoseAnim(genWord);
            break;
        }
        else{
            for (int i = 0; i < genWord.length(); i++){
                if (guess[0] == genWord[i]){
                    str[i] = guess[0];
                    wordLen--;
                }
            }
        }
        clearScreen();
    }

    if (point > 7 && wordLen != 0) {
        gameLoseAnim(genWord);
    }

    else if (check != 0){
        cout << "Congrats, You have won!!!" << endl;
        cout << "The word is: " << genWord << endl;
        cout << "Your time: " << secondsElapsed  << 's' << endl;
        p.time = secondsElapsed;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        clearScreen();
        cout << "Loading highscore..." << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        clearScreen();
        writeToScores(p);
    }
}

