#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>

void create_daemon();
void setup();
void post_fork();

int main() {
    setup();
    // Now we are the daemon (two parents quit). Our location is / and we don't have any file descriptors open
    while (1)
    {
        //TODO: Insert daemon code here.
        puts("Hello World");
        sleep (20);
        break;
    }

    puts("Goodbye cruel world");
    return EXIT_SUCCESS;
}

// Setting up the daemon
void setup() {
    create_daemon();
    setsid();
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    create_daemon();
}

// creates a daemon. The child process just exits.
void create_daemon() {
    pid_t pid = fork();
    if(pid < 0) {
        printf("Error while forking.");
        exit(EXIT_FAILURE);
    } else if(pid > 0) {
        exit(EXIT_SUCCESS);
    }
    printf("Daemon started with pid: %d.\n", getpid());
}

// close file descriptors and chdir
void post_fork() {
    umask(0);
    chdir("/");
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}
