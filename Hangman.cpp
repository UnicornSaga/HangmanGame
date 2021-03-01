#include <iostream>
#include <vector>
#include <string>
using namespace std;

string generateWord(); //sinh ra 1 từ random để ng chơi đoán
char inputChar(vector<char>&  checkGuess); //nhập input của người dùng và check với các điều kiện khác
void printHangman(int& point); //in hình giá treo mỗi khi đoán sai dựa trên số lần đoán sai (point = số lần đoán sai)
void welcomeHeadline(int& charCount); //in ra màn hình 1 welcome statement
void printGuessLetter(vector<char>& checkGuess); //in ra những từ đã được ng chơi đoán
void clearScreen();
void renderGame(string& str, const string genWord, vector<char>& checkGuess, int& checkWord, int& point);


int main()
{
    int point = 0;
    string genWord = generateWord();
    int checkWord = genWord.length(); //lấy độ dài từ đc generate
    string str = "";
    vector<char> checkGuess;

    for (int i = 0; i < checkWord; i++) str = str + '-';

    welcomeHeadline(checkWord);
    while (point <= 7){
        if (str == genWord){
            cout << "Congrats, You have won!!!" << endl;
            break;
        }
        if (point > 0){
            printHangman(point);
            printGuessLetter(checkGuess);
        }
        renderGame(str, genWord, checkGuess, checkWord, point);
    }
    //Nếu đã đoán quá 7 lần mà vẫn chưa đoán hết các từ thì thua
    if (point > 7 and checkWord != 0){
        cout << "Sorry but you have lost cunt!!" << endl;
        cout << "The correct word is: " << genWord << endl;
    }
}



string generateWord()
{
    string word_list[] = {
	"angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"};
    srand(time(0));
    int word_num = sizeof(word_list) / sizeof(string);
    int index = rand() % word_num;
    return word_list[index];
}



char inputChar(vector<char>& checkGuess)
{
    string guess;
    int check = 0;
    do{
        cout << "Your guess: ";
        cin >> guess;
        if (guess.length() > 1) cout << "Please enter only 1 character. Try again." << endl;
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
    } while(guess.length() != 1);
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

void renderGame(string& str, const string genWord, vector<char>& checkGuess, int& checkWord, int& point)
{
    cout << endl << str << endl;
    char guess = inputChar(checkGuess);
    int check = 0;
    for (int i = 0; i < genWord.length(); i++){
        if (guess == genWord[i]){
            str[i] = guess;
            check++;
            checkWord--;
        }
    }
    if (check == 0){
        point++;
    }
    clearScreen();
}
