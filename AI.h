#pragma once
#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "utilAI.h"
#include "guesserAI.h"
#include "drawAI.h"

using namespace std;

#define MAX_GUESSES 7

int getUserWordLength();
void initialize(int& wordLength, string& secretWord, int& incorrectGuess, set<char>& previousGuesses, bool& stop);
string getUserAnswer(char guess);
bool isGoodMask(char guess, const string& mask, const string& secretWord);
void updateSecretWord(const string& mask, string& secretWord);
void update(char guess, const string& mask, int& incorrectGuess, set<char>& previousGuesses, string& secretWord, bool& stop);
void render(int incorrectGuess, const set<char>& previousGuesses, const string& secretWord);
void playAnimation(bool isLosing, const string& word);
void simpleAI();