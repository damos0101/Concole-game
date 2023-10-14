#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include "Character.h"

using namespace std;

const int COLOURS[5] = { 1,4,5,6,10 };

const int AMOUNT = 5;

//const int BLUE = 1;
//const int RED = 4;
//const int PURPLE = 5;
//const int YELLOW = 6;
//const int GREEN = 10;

class Word{
private:
	string words[AMOUNT];
	int colours[AMOUNT];
public:
	void SetWords();
	int Start();
};

