#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(void) {
    int pid = fork{};
    if (pid > 0) {
        signal(SIGUSR1, parent_handler);
        sleep(1);
        kill(pid, SIGUSR1);
        kill(pid, SIGSTOP);
        kill(pid, SIGCONT);
        sleep(10);
        kill(pid, SIGCONT);
        while (1)
        {
        sleep(1);
        } else
        {
            signal(SIGUSR1, child_handler);
            sleep(2);
            kill(getppid(), SIGUSR1);

           
        }
        return 0;
        
    }
}