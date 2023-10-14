#include "Word.h"

void Word::SetWords(){
	ifstream in;
	int r;
	string str;
	for (int i = 0; i < AMOUNT; ++i) {
		in.open("third_task.txt");
		r = rand() % AMOUNT + 1;
		for (int j = 1; j <= r; ++j) {
			getline(in, str);
		}
		words[i] = str;
		r = rand() % AMOUNT;
		colours[i] = COLOURS[r];
		in.close();
	}
}

int Word::Start(){
	int ticket = 0;
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetWords();
	for (int i = 0; i < AMOUNT; ++i) {
		SetConsoleTextAttribute(hConsole, colours[i]);
		cout << words[i] << " ";
	}
	cout << endl;
	this_thread::sleep_for(chrono::seconds(4));
	SetConsoleTextAttribute(hConsole, 7);
	system("cls");
	cout << "��� ��� ���, ������ ������, ������ ����� 2 ������." << endl;
	string answer[AMOUNT];
	cin.ignore();
	cout << "������ � ��� ���� 120 ������ �� �� ����� ������������� ������������ ���������� ���� ������� �� ������ ��������� �� ���������� �����." << endl;
	for (int i = 0; i < AMOUNT; ++i) {
		getline(cin, answer[i]);
		if (answer[i] == words[i]) {
			ticket += 4;
		}
	}
	if (ticket) {
		cout << "����������, �� ��������� " << ticket << " �������" << endl;
	}
	else {
		cout << "�� �� ��������� �� ������ �����" << endl;
	}
	return ticket;
}
