#include "CaesarCipher.h"

string CaesarCipher::GetWord(){
	ifstream in("second_task.txt");
	int r = rand() % 9 + 1;
	string str;
	for (int i = 0; i <= r; ++i) {
		//str = "";
		getline(in, str);
	}
	return str;
}

string CaesarCipher::Cipher(string str){
	for (int i = 0; i < str.length(); ++i) {
		str[i]++;
		if (str[i] > '�') {
			str[i] = '�';
		}
	}
	return str;
}

void CaesarCipher::Input(string& str, const string ans){
	while (str != ans) {
		cin >> str;
		cout << "��������� ����������..." << endl;
	}
}

int CaesarCipher::Start(){
	ans = GetWord();
	fakeAns = Cipher(ans);
	system("cls");
	cout << "�������� �����, ������������� ������ ������" << endl << "(����� ������� �� 1 ������ ������)" <<
		endl << "� ��� ���� 100 ������ �� �����������: " << fakeAns << endl;
	thread th(&CaesarCipher::Input, this, ref(str), ans);
	for (int i = 100; i > 0; --i) {
		this_thread::sleep_for(chrono::seconds(1));
		if (str == ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "���������" << endl << endl;
			th.detach();
			system("pause");
			return i / 2;
		}
		else if (str != "" && str != ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "�����������, ������ ��� ���, � ���� �������� " << i << " ������" << endl;
			str = "";
		}
	}
	cout << "����� �����, �� ���������" << endl;
	th.detach();
	exit(1);
}
