#include "KeyboardRacing.h"

int KeyboardRacing::Start() {
	cout << "�� ����� ����� ���������� ��������� �������. ���� ������ ������ ��������� ��." << endl;
	system("pause");
	system("cls");
	int tickets = 0;
	int tries = 3;
	for (int sleep_time = 1000; sleep_time >= 100; sleep_time -= 50) {
		char letter = 65 + rand() % 26;
		cout << "< " << letter << " >" << endl;
		Sleep(sleep_time);
		system("cls");
		cout << " < ������� ����� >" << endl;
		int ch = _getch();
		if (ch == letter || ch == tolower(letter)) {
			cout << "������ �����!" << endl;
			tickets++;
			Sleep(700);
			system("cls");
		}
		else {
			cout << "����� ��������! �� �������!" << endl;
			cout << "������� �������: " << --tries << endl;
			Sleep(700);
			system("cls");
			if (!tries) return 0;
		}
	}
	return tickets;
}