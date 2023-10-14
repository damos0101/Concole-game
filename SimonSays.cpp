#include "SimonSays.h"

bool SimonSays::Start(){
	cout << "Правила испытания" << endl;
	cout << "На экране последовательно будут загораться цифры. Ваша задача каждый раз восстанавливать их последовательность." << endl;
	system("pause");
	system("cls");

	int count = 0;
	for (int i = 0; i < 5; ++i) {
		for (int f = 0; f < 9; ++f) {
			if (f % 3 == 0 && f != 0) {
				cout << endl;
			}
			cout << p[f] << " ";
		}
		int x = (rand() % 9);
		v.push_back(x);
		ans.push_back(p[x]);
		for (int j = 0; j < v.size(); ++j) {
			Random(v[j]);
		}
		for (int j = 0; j < v.size(); ++j) {
			char c = _getch();
			if (c == ans[j]) {
				++count;
			}
		}
		if (count == v.size()) {
			cout << "Молодец, ты не такой биомусор, как кажешься на первый взгляд!";
			this_thread::sleep_for(chrono::milliseconds(1000));
		}
		else {
			cout << "Печально, все таки придется записать Вас в перечень биоотходов.";
			this_thread::sleep_for(chrono::milliseconds(1000));
			return 0;
		}
		count = 0;
		system("cls");
	}
	return 1;
}

void SimonSays::Random(int x){
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	setcur((x % 3) * 2, x / 3);
	SetConsoleTextAttribute(hConsole, 4);
	cout << p[x];
	this_thread::sleep_for(chrono::milliseconds(500));
	SetConsoleTextAttribute(hConsole, 7);
	setcur((x % 3) * 2, x / 3);
	cout << p[x];
	this_thread::sleep_for(chrono::milliseconds(50));
	setcur(0, 3);
}
