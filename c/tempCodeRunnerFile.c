// 12. Взаимодействие двух процессов через SIGUSR1/SIGUSR2 и общий файл
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

static volatile int sent = 0;      // сколько SIGUSR1 уже ушло
static int M = 5;                  // можно переопределить аргументами
static int N = 3;
static pid_t child_pid;
static FILE *filep;

/* ---------- Обработчики у ребёнка ---------- */
void sigusr1_child(int signo) {              // приходит из родителя
    static int value = 1;                    // чтобы числа шли подряд
    for (int i = 0; i < N; ++i)
        fprintf(filep, "%d ", value++);
    fflush(filep);
}

void sigusr2_child(int signo) {              // финальный сигнал
    fclose(filep);
    _exit(0);
}

/* ---------- Обработчик у родителя ---------- */
void sigalrm_parent(int signo) {
    if (sent < M) {
        kill(child_pid, SIGUSR1);
        ++sent;
        alarm(1);                           // перезапускаем таймер на 1 с
    } else {
        kill(child_pid, SIGUSR2);           // хватит
    }
}

int main(int argc, char *argv[]) {
    if (argc == 3) {            // позволяю задать M и N с командной строки
        M = atoi(argv[1]);
        N = atoi(argv[2]);
    }

    /* 1. Открываем общий файл до fork() */
    filep = fopen("data.txt", "w+");
    if (!filep) { perror("fopen"); return 1; }
    setvbuf(filep, NULL, _IONBF, 0);        // безбуферно

    /* 2. fork() */
    child_pid = fork();
    if (child_pid == -1) { perror("fork"); return 1; }

    if (child_pid == 0) {   /* ---------------- Дочерний процесс ---------------- */
        /* навешиваем обработчики */
        signal(SIGUSR1, sigusr1_child);
        signal(SIGUSR2, sigusr2_child);
        /* спим вечно, реагируем только на сигналы */
        while (1) pause();
    }
    else {                  /* ---------------- Родительский процесс ----------- */
        /* обработчик таймера */
        signal(SIGALRM, sigalrm_parent);
        alarm(1);                       // первый таймер

        /* ждём ребёнка */
        waitpid(child_pid, NULL, 0);

        /* 3. Читаем и выводим содержимое файла */
        rewind(filep);
        int x;
        printf("Данные из файла:\n");
        while (fscanf(filep, "%d", &x) == 1)
            printf("%d ", x);
        printf("\n");

        fclose(filep);
    }
    return 0;
}
