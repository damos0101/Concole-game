#include "GuessTheWord.h"

string GuessTheWord::GetWord() {
	ifstream in("first_task.txt");
	int r = rand() % 11 + 1;
	string str;
	for (int i = 1; i <= r; ++i) {
		str = "";
		getline(in, str);
	}
	return str;
}

string GuessTheWord::RandomString(string str) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			swap(str[rand() % str.length()], str[rand() % str.length()]);
		}
	}
	return str;
}

void GuessTheWord::Input(string& str, const string ans) {
	while (str != ans) {
		cin >> str;
		cout << "��������� ����������..." << endl;
	}
}

void GuessTheWord::Start(Character& c) {
	ans = GetWord();
	fakeAns = RandomString(ans);
	cout << "�������� �����, ��������� �� ���� ����, � ��� ���� 40 ������ �� �����������: " << fakeAns << endl << endl;
	thread th(&GuessTheWord::Input, this, ref(str), ans);
	for (int i = 40; i > 0; --i) {
		this_thread::sleep_for(chrono::seconds(1));
		if (str == ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "���������, �� ��������� " << i << " ������� � ����������� ���������. " << endl << endl;
			c.SetTickets(c.GetTickets() + i);
			th.detach();
			return;
		}
		else if (str != "" && str != ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "�����������, ���������� ��� ���, � ��� �������� " << i << " ������." << endl << endl;
			str = "";
		}
	}
	cout << "�������� �� �� �� ��������� ����� ��������, �������� ������� ����������, �������� " << c.GetName() << "." << endl;
	th.detach();
	exit(1);
}