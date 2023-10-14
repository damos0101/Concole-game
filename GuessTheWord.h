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

class Character;

class GuessTheWord{
private:
	string str, ans, fakeAns;
public:
	string GetWord();
	string RandomString(string str);
	void Input(string& str, const string ans);
	void Start(Character& c);
};

