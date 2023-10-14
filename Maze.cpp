#include "Maze.h"

Maze::Maze() {
	height = 21;
	width = 21;

	maze = new int* [height];
	for (int i = 0; i < height; i++) {
		maze[i] = new int[width];
	}
	mazemake();
}

Maze::Maze(int h, int w) {
    height = h;
    width = w;

    maze = new int* [height];
    for (int i = 0; i < height; i++) {
        maze[i] = new int[width];
    }
    mazemake();
}

Maze::~Maze() {
    for (int i = 0; i < height; i++) {
        delete[] maze[i];
    }
    delete[] maze;
}

bool Maze::deadend(int x, int y) {
	int a = 0;

	if (x != 1) {
		if (maze[y][x - 2] == PASS)
			a += 1;
	}
	else a += 1;

	if (y != 1) {
		if (maze[y - 2][x] == PASS)
			a += 1;
	}
	else a += 1;

	if (x != width - 2) {
		if (maze[y][x + 2] == PASS)
			a += 1;
	}
	else a += 1;

	if (y != height - 2) {
		if (maze[y + 2][x] == PASS)
			a += 1;
	}
	else a += 1;

	if (a == 4)
		return 1;
	else
		return 0;
}

void Maze::visual() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			switch (maze[i][j]) {
			case WALL: cout << "0 "; break;
			case PASS: cout << "  "; break;
			case CHARACTER: cout << "* "; break;
			case EXIT: cout << "# "; break;
			}
		}
		cout << endl;
	}
	cout << endl;
}

void Maze::mazemake() {
	int x, y, c, a;
	bool b;

	for (int i = 0; i < height; i++) { // Массив заполняется землей-ноликами
		for (int j = 0; j < width; j++) {
			maze[i][j] = WALL;
		}
	}

	x = 3; y = 3; a = 0; // Точка приземления крота и счетчик
	while (a < 10000) { // Да, простите, костыль, иначе есть как, но лень
		maze[y][x] = PASS; a++;
		while (1) { // Бесконечный цикл, который прерывается только тупиком
			c = rand() % 4; // Напоминаю, что крот прорывает
			switch (c) {  // по две клетки в одном направлении за прыжок
			case 0: if (y != 1)
				if (maze[y - 2][x] == WALL) { // Вверх
					maze[y - 1][x] = PASS;
					maze[y - 2][x] = PASS;
					y -= 2;
				}
			case 1: if (y != height - 2)
				if (maze[y + 2][x] == WALL) { // Вниз
					maze[y + 1][x] = PASS;
					maze[y + 2][x] = PASS;
					y += 2;
				}
			case 2: if (x != 1)
				if (maze[y][x - 2] == WALL) { // Налево
					maze[y][x - 1] = PASS;
					maze[y][x - 2] = PASS;
					x -= 2;
				}
			case 3: if (x != width - 2)
				if (maze[y][x + 2] == WALL) { // Направо
					maze[y][x + 1] = PASS;
					maze[y][x + 2] = PASS;
					x += 2;
				}
			}
			if (deadend(x, y))
				break;
		}

		if (deadend(x, y)) // Вытаскиваем крота из тупика
			do {
				x = 2 * (rand() % ((width - 1) / 2)) + 1;
				y = 2 * (rand() % ((height - 1) / 2)) + 1;
			} while (maze[y][x] != PASS);
	} // На этом и все.
}

void Maze::setSpawnAndDestination() {
	int corner = 1 + (rand() % 4);
	if (corner == 1) {
		current_x = current_y = 1;
		destination_x = width - 2;
		destination_y = height - 2;
	}
	else if (corner == 2) {
		current_x = width - 2;
		current_y = 1;
		destination_x = 1;
		destination_y = height - 2;
	}
	else if (corner == 3) {
		current_x = width - 2;
		current_y = height - 2;
		destination_x = destination_y = 1;
	}
	else {
		current_x = 1;
		current_y = height - 2;
		destination_x = width - 2;
		destination_y = 1;
	}
}

void Maze::Start() {
	setSpawnAndDestination();
	maze[current_y][current_x] = CHARACTER;
	maze[destination_y][destination_x] = EXIT;
	visual();
	setcur(0, 0);

	int key;
	while (maze[destination_y][destination_x] != CHARACTER) {
		if (_kbhit()) {
			key = _getch();
			if (key == 224) {
				do {
					key = _getch();
				} while (key == 224);
				switch (key) {
				case 72:
					if (maze[current_y - 1][current_x] != WALL) {
						maze[current_y][current_x] = PASS;
						maze[--current_y][current_x] = CHARACTER;
					}
					break;
				case 75:
					if (maze[current_y][current_x - 1] != WALL) {
						maze[current_y][current_x] = PASS;
						maze[current_y][--current_x] = CHARACTER;
					}
					break;
				case 77:
					if (maze[current_y][current_x + 1] != WALL) {
						maze[current_y][current_x] = PASS;
						maze[current_y][++current_x] = CHARACTER;
					}
					break;
				case 80:
					if (maze[current_y + 1][current_x] != WALL) {
						maze[current_y][current_x] = PASS;
						maze[++current_y][current_x] = CHARACTER;
					}
					break;
				}
			}
			visual();
			setcur(0, 0);
		}
	}
	system("cls");
}
