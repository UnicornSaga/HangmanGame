#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#pragma once
using namespace std;

void Color(int color);
void clearScreen();
void printHangman(int& point);
void gameLoseAnim(string& genWord);
