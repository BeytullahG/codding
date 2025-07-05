// 1. Работа с аргументами командной строки, импорт модуля, условный оператор, форматированный вывод в консоль, возврат кода завершения
// выводит переданные аргументы
#include <stdio.h>

int main(int argc, char* argv[]) {
	if(argc > 1) {
		for (int i = 1; i < argc; ++i) {
			printf("Argument %d is: %s\n", i, argv[i]);
		}
		return 0;
	} else {
		printf("No arguments given\n");
		return -1;
	}
}
