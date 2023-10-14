#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <ctime>

using namespace std;
class CaesarCipher{
private:
	string str, ans, fakeAns;
public:
	string GetWord();
	string Cipher(string str);
	void Input(string& str, const string ans);
	int Start();
};

