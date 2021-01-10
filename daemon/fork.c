#include "fork.h"

void create_daemon();
void setup();
void post_fork();


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
}

// close file descriptors and chdir
void post_fork() {
    umask(0);
    chdir("/");
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}
