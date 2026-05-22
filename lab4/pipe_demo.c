#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    // First child -> ls
    if (fork() == 0) {

        dup2(fd[1], STDOUT_FILENO);

        close(fd[0]);
        close(fd[1]);

        execlp("ls", "ls", NULL);

        perror("execlp ls");
        return 1;
    }

    // Second child -> wc -l
    if (fork() == 0) {

        dup2(fd[0], STDIN_FILENO);

        close(fd[0]);
        close(fd[1]);

        execlp("wc", "wc", "-l", NULL);

        perror("execlp wc");
        return 1;
    }

    // Parent
    close(fd[0]);
    close(fd[1]);

    wait(NULL);
    wait(NULL);

    return 0;
}
