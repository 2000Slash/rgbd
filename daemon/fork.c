#include "fork.h"
#include <fcntl.h>


void create_daemon();
void post_fork();


// Setting up the daemon
void setup_daemon(){
    create_daemon();
    setsid();
    signal(SIGCHLD, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    create_daemon();
    post_fork();
}

// creates a daemon. The child process just exits.
void create_daemon() {
    pid_t pid = fork();
    if(pid < 0) {
        syslog(LOG_ERR, "Error while forking: %d", errno);
        exit(EXIT_FAILURE);
    } else if(pid > 0) {
        exit(EXIT_SUCCESS);
    }
}

// close file descriptors and chdir
void post_fork() {
    chdir("/");
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);
}
