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
		if (str[i] > 'я') {
			str[i] = 'а';
		}
	}
	return str;
}

void CaesarCipher::Input(string& str, const string ans){
	while (str != ans) {
		cin >> str;
		cout << "Проверяем результаты..." << endl;
	}
}

int CaesarCipher::Start(){
	ans = GetWord();
	fakeAns = Cipher(ans);
	system("cls");
	cout << "Напишите слово, зашифрованное шифром Цезаря" << endl << "(слово смещено на 1 символ вправо)" <<
		endl << "У вас есть 100 секунд на размышление: " << fakeAns << endl;
	thread th(&CaesarCipher::Input, this, ref(str), ans);
	for (int i = 100; i > 0; --i) {
		this_thread::sleep_for(chrono::seconds(1));
		if (str == ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Правильно" << endl << endl;
			th.detach();
			system("pause");
			return i / 2;
		}
		else if (str != "" && str != ans) {
			this_thread::sleep_for(chrono::seconds(2));
			cout << "Неправильно, пробуй ещё раз, у тебя осталось " << i << " секунд" << endl;
			str = "";
		}
	}
	cout << "Время вышло, вы проиграли" << endl;
	th.detach();
	exit(1);
}
