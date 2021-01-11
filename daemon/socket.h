#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/un.h>

// fork.c is the file responsible for setting up the daemon. (forking and closing file descriptors for example)

void setup_socket();
