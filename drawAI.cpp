#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

string getDrawing(int incorrectGuess)
{
    static const string figure[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n",
    };

    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    return figure[incorrectGuess % NUMBER_OF_FIGURES];
}

string getNextHangman()
{
    static string figure[] =  {
          "   ------------+    \n"
          "   |          /     \n"
          "   |         O      \n"
          "   |        /|\\    \n"
          "   |        / \\    \n"
          "   |        \n"
          " -----      \n" ,
          "   ------------+     \n"
          "   |           |     \n"
          "   |           O     \n"
          "   |          /|\\   \n"
          "   |          / \\   \n"
          "   |        \n"
          " -----      \n",
          "   ------------+      \n"
          "   |            \\    \n"
          "   |            O     \n"
          "   |           /|\\   \n"
          "   |           / \\   \n"
          "   |      \n"
          " -----    \n",
          "   ------------+     \n"
          "   |           |     \n"
          "   |           O     \n"
          "   |          /|\\   \n"
          "   |          / \\   \n"
          "   |        \n"
          " -----      \n",
    };
    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

string getNextStandingman()
{
    static string figure[] = {
          "     O     \n"
          "    /|\\   \n"
          "    | |    \n",
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n",
          "   __O__   \n"
          "     |     \n"
          "    / \\   \n",
          "    \\O/   \n"
          "     |     \n"
          "    / \\   \n",
          "   __O__   \n"
          "     |     \n"
          "    / \\   \n",
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "    O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "      O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
          "     O     \n"
          "    /|\\   \n"
          "    / \\   \n" ,
    };
    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    static int currentFigure = 0;
    return figure[(currentFigure++) % NUMBER_OF_FIGURES];
}

void clearScreen()
{
#ifdef __WIN32__
    system("cls");
#else
    for (int i = 0; i < 30; i++) cout << endl;
#endif
}
