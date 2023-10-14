#include <iostream>
#include <chrono>
#include <string>
#include <thread>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <conio.h>
#include "GuessTheWord.h"
#include "CaesarCipher.h"
#include "Word.h"
#include "Maze.h"
#include "Character.h"
#include "SimonSays.h"
#include "KeyboardRacing.h"
//#pragma comment(lib, "winmm.lib")

using namespace std;

enum Part {
	Intro, First, Second, Third, Fourth, Fivth, Final
};

//void ThemeMusic() {
//	PlaySound(TEXT("y2mate.com - ProtoU - Transparent Clusters.wav"), NULL, SND_FILENAME | SND_ASYNC);
//	Sleep(564000);
//}

void Display(string msg) {
	for (int i = 0; i < msg.length(); i++) {
		cout << msg[i];
		this_thread::sleep_for(chrono::milliseconds(50));
	}
}

void Dialog(Part p, Character& c) {
	if (p == Part::Intro) {
		int r = rand() % 100 + 1;
		cout << "������: ������������ ���������� " << r << endl <<
			"�� ������� ������� � ������������ �� ����� ������ ��� ��������� ���������� ������������ ������������. " << endl;
		cout << "���������� ��������� ��� ��� �����. " << endl;
		cout << "���������� " << r << ": ";
		string name;
		getline(cin, name);
		c.SetName(name);
		cout << "������������, " << c.GetName() << ", ������ �� �������� ��������� ������. �� ���������� ���������� ��� ����� ������ �������." << endl <<
			"��������� ���� ��������� �������� ������ ��� ����������. " << endl;
		for (int i = 1; i <= 4; ++i) {
			this_thread::sleep_for(chrono::seconds(1));
			cout << '.';
		}
		cout << endl;
		cout << "��������� ������� ��������� ��������. " << endl << 
			"������������� � ������ ������."
			 << endl;
		system("pause");
		system("cls");
	}
	if (p == Part::First) {
		cout << "������: ������ �� ������ �� ������� ����� ����. ���� ������ ������� ����� �� ����� ������. " << endl << endl;
		this_thread::sleep_for(chrono::seconds(3));
		GuessTheWord gtw;
		gtw.Start(c);
		system("pause");
		system("cls");
		cout << "������: ���������� �������� �� ���� ��������." << endl;
		cout << "��� �� ���� ����������?" << endl << "1 - � � �������." << endl << "2 - ��� �� �����, ������ � �����?" << endl << endl;
		char p = _getch();
		if (p == '1') {
			cout << c.GetName() << ": � � �������." << endl;
		}
		else if (p == '2') {
			cout << c.GetName() << ": ��� �� �����, ������ � �����?" << endl << endl;
			cout << "������: ����������, ���������� �����������, ��� ������� ������������ �� ������ ������� ���� � �����. " << endl << endl;
			cout << c.GetName() << ": ��� �� ���� ������?" << endl << endl;
			cout << "������: �� ������� ������� � ����� ���������, ����������, ���������� ������������. " << endl << endl;
		}
		system("pause");
		system("cls");
		cout << "������: �� ������� ���� ���?" << endl << "1 - ��." <<  endl << "2 - ���." << endl << endl;
		p = _getch();
		if (p == '1') {
			cout << c.GetName() << ": ��, ���� ����� - " << c.GetName() << "." << endl;
		}
		else if (p == '2') {
			cout << c.GetName() << ": ���" << endl << endl;
			cout << "������: �������� �� ���������� ��������." << endl;
			for (int i = 1; i <= 4; ++i) {
				this_thread::sleep_for(chrono::seconds(1));
				cout << '.';
			}
			cout << endl << endl;
			int f = rand() % 2 + 1;
			cout << "������: �������� ���������. ���� ���: ";
			if (f == 1) {
				cout << c.GetName() << ".";
			}
			else {
				cout << "����.";
				c.SetName("����");
			}
			cout << endl;
			cout << "������� �� ���� ������, ��� ����� ������ � �������� ����������." << endl;
		}
		system("pause");
		system("cls");
	}
	if (p == Part::Second) {
		cout << "������: ����� ������ �������� ����� ��������� �� ������������� ���������� ���� ����������� ��������� ����������," << endl <<
			"� � ���������� ��������� �� �� ���������� �����." << endl;
		cout << "� ��� ���� 5 ������ �� ��, ����� ��������� ����������� ��������� ���������� ����." << endl;
		Word w;
		system("pause");
		system("cls");
		int t = w.Start();
		system("pause");
		system("cls");
		if (t) {
			c.SetTickets(t + c.GetTickets());
			cout << "���������� ��� �� ������ � ���� ��������. �������� �� ������� ������� ������ ��������." << endl;
			cout << "�� �������� ��� ��� �� ���������� � ������ ������������?" << endl << 
				"1 - ��." << endl << "2 - ���." << endl << "3 - *����� ��������*" << endl << endl;
			char f = _getch();
			if (f == '1') {
				cout << c.GetName() << ": ��, ���� ��� ����������." << endl;
			}
			else if (f == '2') {
				cout << c.GetName() << ": ���, ��� �� ����� �������� ����������� ���� ���������� ��������." << endl;
				cout << "������: �� ���� ���� �������� � ��������� ��� ������. " <<
					"����� �� ��������� ������� � �������������, � ������� ���� �������, ��� �� �� ��� ��������." << endl;
			}
			else if (f == '3') {
				cout << c.GetName() << ": ��, �� � �������� ���� �����, ��� ����� ����� ����� �����������." << endl;
				cout << "������: � ��� ���� 6 ������ ��� ���� ����� ���������� ������� � ������������." << endl;
				this_thread::sleep_for(chrono::seconds(6));
				cout << "������: ����� �����. �� ������ ����������?" << endl <<
					"1 - ��." << endl << "2 - ���." << endl;
				f = _getch();
				if (f == '1') {
					cout << c.GetName() << ": ��." << endl;
				}
				else if (f == '2') {
					cout << c.GetName() << ": ���." << endl;
					cout << "�������� �� �� �� ��������� ����� ��������, �������� ������� ����������, �������� " << c.GetName() << "." << endl;
					exit(1);
				}
			}
		}
		else {
			cout << "�������� �� �� �� ��������� ����� ��������, �������� ������� ����������, �������� " << c.GetName() << "." << endl;
			exit(1);
		}
		system("pause");
		system("cls");
	}
	if (p == Part::Third) {
		cout << "������ �� ����� ������ �������� ����� ������������� � ����� ������." << endl <<
			"���� ������ ������������ ��� ����� �� ���������� �����. � ��� ���� 100 ������." << endl;
		system("pause");
		CaesarCipher cc;
		int ticket = cc.Start();
		c.SetTickets(c.GetTickets() + ticket);
		system("cls");
		cout << "������: ���������� ��� �� ������, �������� ��� �� ��������� �������� ����� ��� ��� ����������." << endl;
		cout << "��� �� ���� ����������?" << endl << 
			"1 - ���������." << endl <<  "2 - �� ��� ����������." << endl;
		char f = _getch();
		cout << endl;
		if (f == '1') {
			cout << c.GetName() << ": � � �������." << endl;
		}
		if (f == '2') {
			cout << c.GetName() << ": �� ��� �������� ���� ������." << endl;
			cout << "������: ��������� �� ������������ ������, ������� ������������� �������������� ��� ���� ������." << endl;
			cout << c.GetName() << ": ������, �����, � � �������." << endl;
		}
		cout << "������: �� ��������� ������������ � ���-�� ����� �������� ����? " << endl <<
			"1 - ���." << endl << "2 - ��." << endl;
		f = _getch();
		if (f == '1') {
			cout << c.GetName() << ": ���." << endl;
		}
		if (f == '2') {
			cout << c.GetName() << ": ��, � ������������� � ���������� ������." << endl;
			cout << "������: �������� ���� �����." << endl <<
				"1 - �����." << endl << "2 - ������." << endl;
			cout << endl;
			f = _getch();
			if (f == '1') {
				cout << c.GetName() << ": ��� ��� �����." << endl;
				cout << "������: �������� �� �� ������ �������� ��������� ���� �� ����������� ������������������," << endl <<
					"������� ���� ����� �������� ����������, �������� �� ���� ���������." << endl;
				cout << "1 - ��� �����." << endl << "2 - *������������ �����*" << endl;
				f = _getch();
				cout << endl;
				if (f == '1') {
					cout << c.GetName() << ": ��� �������." << endl;
					cout << "������: ������ �������� ���������� �� ������ ������." << endl;
				}
				if (f == '2') {
					cout << c.GetName() << ": ���, ���������, ��� �� � ��� �� �������, ��� ��� ������, � � ����� ������� �� ��� ���������." << endl;
					cout << "������: �������� �� �� �� ��������� ����� ��������, �������� ������� ����������, ��������, " << c.GetName() << ".";
					exit(1);
				}
			}
			if (f == '2') {
				cout << c.GetName() << ": ��, ���� ���������." << endl;
				cout << "������: �������� �� �����." << endl;
				cout << c.GetName() << ": � �� �����, �� � ������ ��� �� ��� ������ ��� ��� � ��� ������� ��� ���� ������������." << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else if (p == Part::Fourth) {
		cout << "������: ����� ��� ��� ���������� � ���������� ���������� ������� �� ������ �������� ����������, " << endl <<
			"��� ���� ����� ��������� ��������� ��������� ������ � ����������. " << endl;
		cout << "���������� ������������� � ������ ����������." << endl;
		system("pause");
		cout << "������� ����������." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
		KeyboardRacing kbracing;
		int ticket = kbracing.Start();
		if (!ticket) {
			cout << "������: ���������� ���������, ��� �� �� �� ��� �� ��������, ��������, " << c.GetName() << "." << endl;
			exit(1);
		}
		c.SetTickets(c.GetTickets() + ticket);
		cout << "���������� ���������, �������� ��������� ������������." << endl;
		system("pause");
		system("cls");
	}
	else if (p == Part::Fivth) {
		cout << "������ �� ����� ������ �������� ��������� ������� ����� �������� �� ��������� ���� ������ � ����� �����������." << endl;
		cout << "��� ����������� � ���, ����� �� ����� ����� �� ���������, ������� ����� �������� �� ����� ������." << endl;
		system("pause");
		system("cls");
		Maze maze;
		maze.Start();
		cout << "���������� ��� �� ������� � ����� ���������, �� ������ ������ ���������� � ���� ������������ �� ������ ��������� ���� �������� � ���� �������� ���������," << endl <<
			"������� �������� �������� ��������� ���. �� ��������, ��� �� ������ ���������� ������ �������� �� ����� ����� ������������." << endl;
		if (c.GetTickets() <= 50) {
			cout << "�� �� ������� ������ ������� � ����� ���������." << endl;
		}
		else if (c.GetTickets() <= 75) {
			cout << "������� ��� ���������� ��� ���� ������� � ����� ������� ������." << endl <<
				"������� � ����� �� ������, �� ������, ������ ����� �������. �� ��������. " << endl;
		}
		else if (c.GetTickets() <= 100) {
			cout << "������� ����� � ���������� ������ ��������� ��� ��� ���������� ��� �� ������� � ����� ���������. " << endl;
		}
		else if (c.GetTickets() <= 130) {
			cout << "��������� �� ������� ��� ��� ����� �������. ����� ��� �������. ������, ����� ���� � ��������! " << endl;
		}
		system("pause");
		system("cls");
	}
	else if (p == Part::Final) {
		for (int i = 1; i <= 4; ++i) {
			this_thread::sleep_for(chrono::seconds(1));
			cout << '.';
		}
		cout << endl << "��������, �� ��� ���� ����� �������� ��� �������� ��� �������� ������ ��� ���� ��������� ������������. " << endl;
		cout << "����� ������ ������, ��� ����� �� ����������. �� ��� �� ������ �������, �� ��������... " << endl;
		system("pause");
		system("cls");
		SimonSays ss;
		if (ss.Start()) {
			cout << "���������� ��� ��� �� ���� ������, ��������  ��������� �� ��������������� ����������." << endl;
		}
		else {
			cout << "�������� �� �� �� ��������� ����� ��������, �������� ������� ����������, �������� " << c.GetName() << endl;
		}
	}
}

int main() {
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//thread first(ThemeMusic);
	Character c;
	Dialog(Part::Intro, c);
	Dialog(Part::First, c);
	Dialog(Part::Second, c);
	Dialog(Part::Third, c);
	Dialog(Part::Fourth, c);
	Dialog(Part::Fivth, c);
	Dialog(Part::Final, c);
	//first.detach();
	return 0;
}