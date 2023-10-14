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
		cout << "Ученый: Приветствуем подопытный " << r << endl <<
			"Вы приняли участие в эксперименте по сбору данных для программы увеличения мыслительных способностей. " << endl;
		cout << "Пожалуйста вспомните как Вас зовут. " << endl;
		cout << "Подопытный " << r << ": ";
		string name;
		getline(cin, name);
		c.SetName(name);
		cout << "Здравствуйте, " << c.GetName() << ", сейчас вы пройдете несколько тестов. За выдающиеся результаты Вам будет выдана награда." << endl <<
			"Подождите пока программа загрузит данные для тестировки. " << endl;
		for (int i = 1; i <= 4; ++i) {
			this_thread::sleep_for(chrono::seconds(1));
			cout << '.';
		}
		cout << endl;
		cout << "Программа успешно завершила загрузку. " << endl << 
			"Подготовьтесь к началу сеанса."
			 << endl;
		system("pause");
		system("cls");
	}
	if (p == Part::First) {
		cout << "Ученый: Сейчас на экране вы увидите набор букв. Ваша задача собрать слово из этого набора. " << endl << endl;
		this_thread::sleep_for(chrono::seconds(3));
		GuessTheWord gtw;
		gtw.Start(c);
		system("pause");
		system("cls");
		cout << "Ученый: Пожалуйста ответьте на пару вопросов." << endl;
		cout << "Как Вы себя чувствуете?" << endl << "1 - Я в порядке." << endl << "2 - Кто Вы такие, почему я здесь?" << endl << endl;
		char p = _getch();
		if (p == '1') {
			cout << c.GetName() << ": Я в порядке." << endl;
		}
		else if (p == '2') {
			cout << c.GetName() << ": Кто Вы такие, почему я здесь?" << endl << endl;
			cout << "Ученый: Пожалуйста, сохраняйте спокойствие, для чистоты эксперимента Вы должны держать себя в руках. " << endl << endl;
			cout << c.GetName() << ": Кто вы черт побери?" << endl << endl;
			cout << "Ученый: Вы приняли участие в нашей программе, пожалуйста, продолжите тестирование. " << endl << endl;
		}
		system("pause");
		system("cls");
		cout << "Ученый: Вы помните свое имя?" << endl << "1 - Да." <<  endl << "2 - Нет." << endl << endl;
		p = _getch();
		if (p == '1') {
			cout << c.GetName() << ": Да, меня зовут - " << c.GetName() << "." << endl;
		}
		else if (p == '2') {
			cout << c.GetName() << ": Нет" << endl << endl;
			cout << "Ученый: Проверка на совпадение личности." << endl;
			for (int i = 1; i <= 4; ++i) {
				this_thread::sleep_for(chrono::seconds(1));
				cout << '.';
			}
			cout << endl << endl;
			int f = rand() % 2 + 1;
			cout << "Ученый: Проверка завершена. Ваше имя: ";
			if (f == 1) {
				cout << c.GetName() << ".";
			}
			else {
				cout << "Карл.";
				c.SetName("Карл");
			}
			cout << endl;
			cout << "Спасибо за Ваши ответы, они будут учтены в конечном результате." << endl;
		}
		system("pause");
		system("cls");
	}
	if (p == Part::Second) {
		cout << "Ученый: Вашим вторым заданием будет запомнить из определенного количества слов максимально возможное количество," << endl <<
			"и в дальнейшем повторить их за отведенное время." << endl;
		cout << "У Вас есть 5 секунд на то, чтобы запомнить максимально возможное количество слов." << endl;
		Word w;
		system("pause");
		system("cls");
		int t = w.Start();
		system("pause");
		system("cls");
		if (t) {
			c.SetTickets(t + c.GetTickets());
			cout << "Благодарим Вас за помощь с этим заданием. Ответьте на вопросы которые сейчас появятся." << endl;
			cout << "Вы довольны тем что Вы участвуете в данном эксперименте?" << endl << 
				"1 - Да." << endl << "2 - Нет." << endl << "3 - *Слова сомнения*" << endl << endl;
			char f = _getch();
			if (f == '1') {
				cout << c.GetName() << ": Да, меня все устраивает." << endl;
			}
			else if (f == '2') {
				cout << c.GetName() << ": Нет, мне не очень нравится чувствовать себя подопытным кроликом." << endl;
				cout << "Ученый: Вы сами дали согласие и подписали все бумаги. " <<
					"Также Вы подписали договор о неразглашении, в котором было указано, что Вы на все согласны." << endl;
			}
			else if (f == '3') {
				cout << c.GetName() << ": Да, но я чувствую себя плохо, мне нужно время чтобы передохнуть." << endl;
				cout << "Ученый: У Вас есть 6 секунд для того чтобы продолжить участие в эксперименте." << endl;
				this_thread::sleep_for(chrono::seconds(6));
				cout << "Ученый: Время вышло. Вы готовы продолжить?" << endl <<
					"1 - Да." << endl << "2 - Нет." << endl;
				f = _getch();
				if (f == '1') {
					cout << c.GetName() << ": Да." << endl;
				}
				else if (f == '2') {
					cout << c.GetName() << ": Нет." << endl;
					cout << "Сожалеем но Вы не оправдали наших ожиданий, запускаю процесс устранения, прощайте " << c.GetName() << "." << endl;
					exit(1);
				}
			}
		}
		else {
			cout << "Сожалеем но Вы не оправдали наших ожиданий, запускаю процесс устранения, прощайте " << c.GetName() << "." << endl;
			exit(1);
		}
		system("pause");
		system("cls");
	}
	if (p == Part::Third) {
		cout << "Сейчас на Вашем экране появится слово зашифрованное в шифре Цезаря." << endl <<
			"Ваша задача расшифровать это слово за отведенное время. У Вас есть 100 секунд." << endl;
		system("pause");
		CaesarCipher cc;
		int ticket = cc.Start();
		c.SetTickets(c.GetTickets() + ticket);
		system("cls");
		cout << "Ученый: Благодарим Вас за помощь, ответьте еще на несколько вопросов перед тем как продолжить." << endl;
		cout << "Как Вы себя чувствуете?" << endl << 
			"1 - Нормально." << endl <<  "2 - Вы уже спрашивали." << endl;
		char f = _getch();
		cout << endl;
		if (f == '1') {
			cout << c.GetName() << ": Я в порядке." << endl;
		}
		if (f == '2') {
			cout << c.GetName() << ": Вы уже задавали этот вопрос." << endl;
			cout << "Ученый: Отвечайте на поставленный вопрос, система автоматически подстраивается под Ваши ответы." << endl;
			cout << c.GetName() << ": Хорошо, понял, я в порядке." << endl;
		}
		cout << "Ученый: Вы обсуждали тестирование с кем-то перед приходом сюда? " << endl <<
			"1 - Нет." << endl << "2 - Да." << endl;
		f = _getch();
		if (f == '1') {
			cout << c.GetName() << ": Нет." << endl;
		}
		if (f == '2') {
			cout << c.GetName() << ": Да, я контактировал с некоторыми людьми." << endl;
			cout << "Ученый: Назовите этих людей." << endl <<
				"1 - Семья." << endl << "2 - Другие." << endl;
			cout << endl;
			f = _getch();
			if (f == '1') {
				cout << c.GetName() << ": Это моя семья." << endl;
				cout << "Ученый: Извините но мы должны провести некоторые мери по сохранности конфиденциальности," << endl <<
					"поэтому Ваша семья подлежит устранению, надеемся на Ваше понимание." << endl;
				cout << "1 - Все равно." << endl << "2 - *Пожертвовать собой*" << endl;
				f = _getch();
				cout << endl;
				if (f == '1') {
					cout << c.GetName() << ": Мне насрать." << endl;
					cout << "Ученый: Группа зачистки отправлена по Вашему адресу." << endl;
				}
				if (f == '2') {
					cout << c.GetName() << ": Нет, подождите, они ни в чем не виновны, это моя ошибка, и я готов понести за нее наказание." << endl;
					cout << "Ученый: Сожалеем но Вы не оправдали наших ожиданий, запускаю процесс устранения, прощайте, " << c.GetName() << ".";
					exit(1);
				}
			}
			if (f == '2') {
				cout << c.GetName() << ": Да, были некоторые." << endl;
				cout << "Ученый: Назовите их имена." << endl;
				cout << c.GetName() << ": Я не помню, но я уверен что Вы уже знаете кто это и уже приняли все меры безопасности." << endl;
			}
		}
		system("pause");
		system("cls");
	}
	else if (p == Part::Fourth) {
		cout << "Ученый: Перед тем как приступить к выполнению последнего задания Вы должны провести калибровку, " << endl <<
			"для того чтобы программа корректно считывала данные в дальнейшем. " << endl;
		cout << "Пожалуйста приготовьтесь к началу калибровки." << endl;
		system("pause");
		cout << "Начинаю калибровку." << endl;
		this_thread::sleep_for(chrono::seconds(3));
		system("cls");
		KeyboardRacing kbracing;
		int ticket = kbracing.Start();
		if (!ticket) {
			cout << "Ученый: Калибровка провалена, увы Вы ни на что не годитесь, прощайте, " << c.GetName() << "." << endl;
			exit(1);
		}
		c.SetTickets(c.GetTickets() + ticket);
		cout << "Калибровка завершена, запускаю последнее тестирование." << endl;
		system("pause");
		system("cls");
	}
	else if (p == Part::Fivth) {
		cout << "Сейчас на Вашем экране появится последнее задание после которого вы завершите свою миссию в нашей лаборатории." << endl;
		cout << "Оно заключается в том, чтобы Вы нашли выход из лабиринта, который скоро появится на Вашем экране." << endl;
		system("pause");
		system("cls");
		Maze maze;
		maze.Start();
		cout << "Благодарим Вас за участие в нашей программе, на основе данных полученных в ходе тестирования мы сможем загрузить Ваше сознание в наше облачное хранилище," << endl <<
			"кодовое название которого «Цифровой рай». Мы надеемся, что Вы будете продолжать дальше работать на благо всего человечества." << endl;
		if (c.GetTickets() <= 50) {
			cout << "Мы не забудем Вашего участия в нашей программе." << endl;
		}
		else if (c.GetTickets() <= 75) {
			cout << "Считать что технологии все таки победят в нашей великой борьбе." << endl <<
				"Помните – будет не больно, не обидно, просто очень приятно. До свидания. " << endl;
		}
		else if (c.GetTickets() <= 100) {
			cout << "Понесем добро в отдаленные уголки вселенной… Еще раз благодарим Вас за участие в нашей программе. " << endl;
		}
		else if (c.GetTickets() <= 130) {
			cout << "Создатель не оставит Вас без своей милости. Всего Вам доброго. Ребята, пейте пиво и танцуйте! " << endl;
		}
		system("pause");
		system("cls");
	}
	else if (p == Part::Final) {
		for (int i = 1; i <= 4; ++i) {
			this_thread::sleep_for(chrono::seconds(1));
			cout << '.';
		}
		cout << endl << "Сожалеем, но для того чтобы покинуть наш комплекс Вам придется пройти еще одно финальное тестирование. " << endl;
		cout << "Когда Саймон молчит, его лучше не перебивать. Но так он сейчас говорит, то дерзайте... " << endl;
		system("pause");
		system("cls");
		SimonSays ss;
		if (ss.Start()) {
			cout << "Благодарим еще раз за Вашу помощь, приносим  извинения за предоставленные неудобства." << endl;
		}
		else {
			cout << "Сожалеем но Вы не оправдали наших ожиданий, запускаю процесс устранения, прощайте " << c.GetName() << endl;
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