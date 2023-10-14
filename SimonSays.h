#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>
#include <vector>
#include "setcur.h"

using namespace std;

//void setcur(int x, int y) {
//	COORD coord;
//	coord.X = x;
//	coord.Y = y;
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

class SimonSays{
private:
	char p[9] = { '1','2','3', '4','5','6', '7','8','9' };
	vector<int> v;
	vector<char> ans;
public:
	bool Start();
	void Random(int x);
};

