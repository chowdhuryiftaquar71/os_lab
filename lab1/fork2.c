#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {

    pid_t pid = fork();

    if (pid == 0) {

        printf("I am the child. My PID is %d, Parent PID is %d\n",
               getpid(), getppid());

    } else if (pid > 0) {

        printf("I am the parent. My PID is %d, Child PID is %d\n",
               getpid(), pid);

    } else {

        perror("Fork failed");
    }

    return 0;
}
