#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

string generateWord(); //sinh ra 1 từ random để ng chơi đoán
char inputChar(vector<char>&  checkGuess); //nhập input của người dùng và check với các điều kiện khác
void printHangman(int& point); //in hình giá treo mỗi khi đoán sai dựa trên số lần đoán sai (point = số lần đoán sai)
void welcomeHeadline(int& charCount); //in ra màn hình 1 welcome statement
void printGuessLetter(vector<char>& checkGuess); //in ra những từ đã được ng chơi đoán
void clearScreen();
void renderGame();


int main()
{
    bool continueGame = true;
    while (continueGame == true){
        renderGame();
        char playerDes;
        cout << "Do you want to play again?(Y|N): ";
        cin >> playerDes;
        playerDes = char(tolower(playerDes));
        if (playerDes == 'y'){
            continueGame = true;
            clearScreen();
        }
        else continueGame = false;
    }
}



void generateWord(string& word, string& hint)
{
    string genWord[2];
    ifstream file;
    file.open("Hangman_word.txt", ios::in);
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
}



char inputChar(vector<char>& checkGuess)
{
    string guess;
    int check = 0;
    do{
        cout << "Your guess: ";
        cin >> guess;
        if (guess.length() > 1){
            cout << "Please enter only 1 character. Try again." << endl;
        }
        else if (char(tolower(guess[0])) < 97 or char(tolower(guess[0])) > 122){
            cout << "This is not a character. Try again." << endl;
        }
        else{
            for (int i = 0; i < checkGuess.size(); i++){
                if (guess[0] == checkGuess[i]){
                    cout << "You have already guess this letter. Try again." << endl;
                    check++;
                    break;
                }
            }
        }
    } while(guess.length() > 1 or (char(tolower(guess[0])) < 97 or char(tolower(guess[0])) > 122));
    if (check == 0) checkGuess.push_back(char(tolower(guess[0])));
    return char(tolower(guess[0]));
}



void welcomeHeadline(int& charCount)
{
    cout << "WELCOME TO HANGMAN." << endl;
    cout << "YOU HAVE 6 TRIES TO GUESS THE WORD." << endl;
    cout << "IF YOU LOSE THEN YOU ARE DUMB AS FUCK." << endl;
    cout << "THIS WORD HAS " << charCount << " LETTER." << endl;
}



void printHangman(int& point)
{
    const string hangman[] = {
        "   -------------\n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\\n"
        "   |                \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\\n"
        "   |          /     \n"
        "   |     \n"
        " -----\n",

        "   -------------\n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\\n"
        "   |          / \\\n"
        "   |     \n"
        " -----\n"
    };
    cout << endl << "Number of wrong guesses: " << point << endl;
    cout << hangman[point - 1] << endl;
}



void printGuessLetter(vector<char>& checkGuess)
{
    cout << "Guesses letter: ";
    for (int j = 0; j < checkGuess.size(); j++){
        cout << checkGuess[j] << ", " ;
    }
    cout << endl;
}

void clearScreen()
{
    for (int i = 0; i < 30 ; i++) cout << endl;
}

void renderGame()
{
    int point = 0;
    string genWord, hint;
    generateWord(genWord, hint);
    int wordLen = genWord.length(); //lấy độ dài từ đc generate
    string str = string(wordLen, '-');
    vector<char> checkGuess;

    welcomeHeadline(wordLen);
    int insertHint = 0;
    while (point <= 7){
        if (str == genWord){
            cout << "Congrats, You have won!!!" << endl;
            cout << "The word is: " << genWord << endl;
            break;
        }
        if (point > 0){
            printHangman(point);
            printGuessLetter(checkGuess);
        }

        //Nếu ppoint lớn hơn 5 thì hỏi ng chơi có cần hint không
        bool checkHint = false;
        char tmp;
        if (point >= 5 and insertHint == 0){
            cout << "Do you want a hint?(Y|N): ";
            cin >> tmp;
            tmp = char(tolower(tmp));
            if (tmp == 'y'){
                checkHint = true;
                insertHint++;
            }
        }
        if (checkHint == true){
            cout << "Hint is: " << hint << endl;
        }

        cout << endl << str << endl;
        char guess = inputChar(checkGuess);
        if (genWord.find_first_of(guess) == string::npos){
            point++;
        }
        else{
            for (int i = 0; i < genWord.length(); i++){
                if (guess == genWord[i]){
                    str[i] = guess;
                    wordLen--;
                }
            }
        }
        clearScreen();
    }
        //Nếu đã đoán quá 7 lần mà vẫn chưa đoán hết các từ thì thua
    if (point > 7 and wordLen != 0){
        cout << "Sorry but you have lost cunt!!" << endl;
        cout << "The correct word is: " << genWord << endl;
    }
}
