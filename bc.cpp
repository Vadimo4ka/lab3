#include <iostream>
#include <ctime>
using namespace std;

int main() {
	cout << "Hello, 0 - exit" << endl << endl;
	int a, b, ran[4], i, j, c[4], bull, cow; // a - число вводим, b - цифра числа a, c[4] - рандомное число, bull - кол-во быков, cow - кол-во коров
	bool f = 0;

	while (true) {
		i = 0;
		srand(time(NULL));
		// Рандомное число
		while (i < 4) {
			ran[i] = rand() % 10;
			for (j = 0; j < i; j++) {
				if (ran[i] == ran[j]) {
					f = 1;
					break;
				}
			}
			if (f == 0) {
				i++;
			}
			f = 0;
		}
		// начинаем игру
		int s = 0; // кол-во ходов
		while (true) {
			bull = 0;
			cow = 0;
			cout << s + 1 << " - ";
			s++;
			cin >> a;
			if (a == 0)
				break;
			for (i = 3; i >= 0; i--) {
				b = a % 10;
				c[i] = b;
				a = (a - b) / 10;
			}
			for (i = 0; i < 4; i++) {
				if (c[i] == ran[i]) {
					bull++;
				}
			}
			for (i = 0; i < 4; i++) {
				for (j = 0; j < 4; j++) {
					if (c[i] == ran[j]) {
						cow++;
					}
				}
			}
			cout << bull << "b " << cow - bull << "c" << endl << endl;
			if (bull == 4) {
				cout << "You win ";
				break;
			}
		}
		for (i = 0; i < 4; i++) {
			cout << ran[i];
		}
		cout << endl << "Else? 1-yes 0 - no" << endl;
		cin >> f;
		if (f == 0) {
			return 0;
		}
		f = 0;
	}
}
