// 6. Отправка сигнала самому себе
#include <signal.h>
#include <stdio.h>

void sig_handler(int signo) {
	printf("handler\n");
}

int main(void) {
	signal(SIGINT, sig_handler);
	printf("begin\n");
	int status = raise(SIGINT);
	printf("end with %d\n", status);
	return 0;
}
