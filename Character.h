#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include "Maze.h"
#include "GuessTheWord.h"
#include "CaesarCipher.h"
#include "Word.h"

using namespace std;

class Character{
private:
	string name;
	int tickets;
public:
	Character();
	void SetName(string name);
	string GetName();
	int GetTickets();
	void SetTickets(int tickets);
};

