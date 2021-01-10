#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>

// fork.c is the file responsible for setting up the daemon. (forking and closing file descriptors for example)

void setup();
