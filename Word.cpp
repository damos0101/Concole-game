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
	cout << "Гоу гоу гоу, быстро быстро, обнова через 2 минуты." << endl;
	string answer[AMOUNT];
	cin.ignore();
	cout << "Теперь у Вас есть 120 секунд на то чтобы воспроизвести максимальное количество слов которые Вы успели запомнить за отведенное время." << endl;
	for (int i = 0; i < AMOUNT; ++i) {
		getline(cin, answer[i]);
		if (answer[i] == words[i]) {
			ticket += 4;
		}
	}
	if (ticket) {
		cout << "Поздравляю, вы получаете " << ticket << " тикетов" << endl;
	}
	else {
		cout << "Вы не запомнили ни одного слова" << endl;
	}
	return ticket;
}
