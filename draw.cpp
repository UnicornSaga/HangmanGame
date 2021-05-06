#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif // _WIN32
}

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
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

void gameLoseAnim(string& genWord)
{
    vector<string> hanged = {
"   ------------\n"
"   |         /\n"
"   |        O\n"
"   |       /|\\\n"
"   |       / \\\n"
"   |         \n"
"   |         \n"
"   |         \n"
"   |         \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        ",
"   ------------\n"
"   |           \\\n"
"   |            O\n"
"   |           /|\\\n"
"   |           / \\\n"
"   |             \n"
"   |             \n"
"   |             \n"
"   |             \n"
"-------        ",
"   ------------\n"
"   |          |\n"
"   |          O\n"
"   |         /|\\\n"
"   |         / \\\n"
"   |           \n"
"   |           \n"
"   |           \n"
"   |           \n"
"-------        "
    };
    int n = 0;
    float start = clock() / CLOCKS_PER_SEC;
    float finish = clock() / CLOCKS_PER_SEC;
    while (finish - start < 5) {
        clearScreen();
        cout << "Game Over!!! You are hanged" << endl
            << "The correct word is " << genWord << endl;
        cout << hanged[n];
        n = (n + 1) % hanged.size();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        finish = clock() / CLOCKS_PER_SEC;
    }
    cout << endl;
}
