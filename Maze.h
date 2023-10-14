#pragma once
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<windows.h>
#include "setcur.h"

const int WALL = 0;
const int PASS = 1;
const int CHARACTER = 2;
const int EXIT = 3;
using namespace std;

//void setcur(int x, int y);

class Maze {
private:
	int height;
	int width;
	int current_x;
	int current_y;
	int destination_x;
	int destination_y;
	int** maze;

public:
	Maze();
	Maze(int h, int w);
	~Maze();
	bool deadend(int x, int y);
	void visual();
	void mazemake();
	void setSpawnAndDestination();
	void Start();
};

