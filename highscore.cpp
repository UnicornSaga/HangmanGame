#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>

#include "draw.h"
using namespace std;

struct player
{
	string name;
	float time;

	player(){};
	player(string _name, float _time) {
		name = _name;
		time = _time;
	}
	// sắp xếp theo score giảm dần
	// nếu score bằng nhau thì xếp time tăng dần
	bool operator < (const player& p) const
	{
		return time < p.time;
	}
};

void writeToScores(const player p) {
	ifstream file("highscore.txt");
	if (!file.is_open()) {
		cout << "Open file HighScore error" << endl;
	}

	vector <player> vt;
	while (!file.eof()) {
		string name;
		file >> name;
		if (name.empty())
			break;

		float time;
		file >> time;


		vt.push_back({ name, time});
	}
	file.close();

	ofstream high("highscore.txt");
	vt.push_back({ p.name, p.time});

	sort(vt.begin(), vt.end());

	while (vt.size() > 10) {
		vt.erase(vt.end() - 1);
	}
	cout << "Highscore: " << endl << endl;
	for (int i = 0; i < vt.size(); i++) {
		cout << vt[i].name << " " << vt[i].time << endl;
	}
	cout << endl;

	for (int i = 0; i < vt.size(); i++) {
		if (i == vt.size() - 1)
			high << vt[i].name << ' ' << vt[i].time;
		else
			high << vt[i].name << ' ' << vt[i].time << endl;
	}
	high.close();
}