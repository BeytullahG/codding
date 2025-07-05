// 2. Другой вариант main без аргументов, посимвольный ввод и вывод, цикл while, понятие EOF (ctrl+d в консоли)
// выводит элементы с четными индексами
#include <stdio.h>

int main(void) {
	int c;
	int is_odd = 1;
	while ((c = getchar()) != EOF) {
		if (is_odd) {
			putchar(c);
		}
		is_odd = !is_odd;
	}
	return 0;
}
