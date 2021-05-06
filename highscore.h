#include <fstream>
#include <map>
#include <vector>
#include <type_traits>
#include <iostream>
#include <map>
#include <iomanip>
#pragma once
using namespace std;

struct player
{
	string name;
	float time;
	int score;

	player(){};
	player(string _name, float _time, int _score) {
		name = _name;
		time = _time;
		score = _score;
	}
	// sắp xếp theo score giảm dần
	// nếu score bằng nhau thì xếp time tăng dần
	bool operator > (const player& p) const
	{
		return (score > p.score) || ((score == p.score) && (time < p.time));
	}
};

void writeToScores(const player p);
