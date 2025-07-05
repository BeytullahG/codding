#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

static const char *FILE_NAME = "output.bin";
static void die(const char *msg) { perror(msg); _exit(EXIT_FAILURE); }

/* пустой обработчик, нужен только чтобы sigsuspend() вернулся */
static void ping(int signo) { (void)signo; }

/* безопасная запись */
static void safewrite(int fd, const void *buf, size_t len)
{
    const unsigned char *p = buf;
    while (len) {
        ssize_t n = write(fd, p, len);
        if (n < 0) { if (errno == EINTR) continue; die("write"); }
        p += (size_t)n; len -= (size_t)n;
    }
}

/* --------- CHILD --------- */
static void child_loop(long M, long N, char fill, int fd)
{
    char *buf = malloc((size_t)N);
    if (!buf) die("malloc");
    memset(buf, fill, (size_t)N);

    sigset_t m, empty;
    sigemptyset(&m); sigaddset(&m, SIGUSR1);
    sigprocmask(SIG_BLOCK, &m, NULL);   /* заблокировали SIGUSR1 */
    sigemptyset(&empty);

    struct sigaction sa = { .sa_handler = ping, .sa_flags = 0 };
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);      /* …но сказали, что делаем при нём */

    for (long i = 0; i < M; ++i) {
        sigsuspend(&empty);             /* ждём пинка родителя     */
        safewrite(fd, buf, (size_t)N);  /* пишем                   */
        kill(getppid(), SIGUSR1);       /* квитируем               */
    }
    free(buf);
    _exit(EXIT_SUCCESS);
}

/* --------- MAIN --------- */
int main(int argc, char *argv[])
{
    if (argc != 3) { fprintf(stderr,"usage: %s M N\n",argv[0]); return 1; }
    long M = strtol(argv[1],NULL,10), N = strtol(argv[2],NULL,10);
    if (M<=0||N<=0) { fprintf(stderr,"M,N must be >0\n"); return 1; }

    int fd = open(FILE_NAME,O_CREAT|O_TRUNC|O_RDWR,0644);
    if (fd == -1) die("open");

    sigset_t mask; sigemptyset(&mask); sigaddset(&mask,SIGUSR1);
    sigprocmask(SIG_BLOCK,&mask,NULL);      /* блокируем в родителе */

    pid_t a=fork(); if (!a) child_loop(M,N,'A',fd);
    pid_t b=fork(); if (!b) child_loop(M,N,'B',fd);

    int signo;
    for (long i=0;i<M;i++) {
        kill(a,SIGUSR1);  sigwait(&mask,&signo);  /* A пишет */
        kill(b,SIGUSR1);  sigwait(&mask,&signo);  /* B пишет */
    }

    int st; waitpid(a,&st,0); waitpid(b,&st,0);

    lseek(fd,0,SEEK_SET);
    char buf[64]; ssize_t n;
    puts("\n---- FILE ----");
    while((n=read(fd,buf,sizeof(buf)))>0) fwrite(buf,1,(size_t)n,stdout);
    puts("\n--------------");
    return 0;
}
