#include "KeyboardRacing.h"

int KeyboardRacing::Start() {
	cout << "На экран будут выводиться латинские символы. Ваша задача просто повторять их." << endl;
	system("pause");
	system("cls");
	int tickets = 0;
	int tries = 3;
	for (int sleep_time = 1000; sleep_time >= 100; sleep_time -= 50) {
		char letter = 65 + rand() % 26;
		cout << "< " << letter << " >" << endl;
		Sleep(sleep_time);
		system("cls");
		cout << " < Введите букву >" << endl;
		int ch = _getch();
		if (ch == letter || ch == tolower(letter)) {
			cout << "Верный ответ!" << endl;
			tickets++;
			Sleep(700);
			system("cls");
		}
		else {
			cout << "Ответ неверный! Не спешите!" << endl;
			cout << "Попыток сталось: " << --tries << endl;
			Sleep(700);
			system("cls");
			if (!tries) return 0;
		}
	}
	return tickets;
}