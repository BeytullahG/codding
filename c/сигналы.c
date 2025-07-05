#define _GNU_SOURCE // включает расширение gnu libc (SIGUTS1 в <SIGNAL.H> и setvbuf )
#include <stdio.h> // включает printf, fprintf, fscanf, FILE, NULL и т. д.
#include <stdlib.h> // exit, EXIT_SUCCESS, EXIT_FAILURE, strtol, _exit, malloc, free …
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>

#define SIG1  SIGUSR1
#define SIG2  SIGUSR2


static volatile int sig1_sent = 0;    
static int M;                           
static int N;                           

static pid_t pid2;                    
static FILE *shared_file;               

static void sig1_handler_p2(int signo)
{
    static int value = 1;
    for (int i = 0; i < N; ++i)
        fprintf(shared_file, "%d ", value++);
    fflush(shared_file);
}
static void sig2_handler_p2(int signo)
{
    fclose(shared_file);
    _exit(0);
}


static void alarm_handler_p1(int signo)
{
    if (sig1_sent < M) {
        kill(pid2, SIG1);
        ++sig1_sent;
        alarm(1);
    } else {
        kill(pid2, SIG2);
    }
}

static int parse_int(const char *s, const char *name)
{
    char *end;
    long v = strtol(s, &end, 10);
    if (*end || v <= 0 || v > INT_MAX) {
        fprintf(stderr, "Bad value for %s: %s\n", name, s);
        exit(EXIT_FAILURE);
    }
    return (int)v;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s  M  N\n"
                        "  M – сколько сигналов SIG1 послать\n"
                        "  N – сколько чисел писать на каждый сигнал\n", argv[0]);
        return EXIT_FAILURE;
    }
    M = parse_int(argv[1], "M");
    N = parse_int(argv[2], "N");

   
    shared_file = fopen("data.txt", "w+");
    if (!shared_file) { perror("fopen"); return EXIT_FAILURE; }
    setvbuf(shared_file, NULL, _IONBF, 0);          

    
    pid2 = fork();
    if (pid2 == -1) { perror("fork"); return EXIT_FAILURE; }

    if (pid2 == 0) {                            
        signal(SIG1, sig1_handler_p2);
        signal(SIG2, sig2_handler_p2);
        while (1) pause();                      
    } else {                                     
        signal(SIGALRM, alarm_handler_p1);
        alarm(1);                               

        waitpid(pid2, NULL, 0);                 

        rewind(shared_file);
        int x;
        printf("Данные из файла:\n");
        while (fscanf(shared_file, "%d", &x) == 1)
            printf("%d ", x);
        printf("\n");

        fclose(shared_file);
    }
    return EXIT_SUCCESS;
}