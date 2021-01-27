#include "fork.h"
#include "socket.h"
#include <sys/syslog.h>
#include "parser.h"
#include "keyboard/Keyboard_C.h"

#define readSize 100

int main() {
    openlog("rgbd", LOG_PID, LOG_USER);
    setup_daemon();
    // Now we are the daemon (two parents quit). Our location is / and we don't have any file descriptors open
    int sock = setup_socket();
    // A socket is now created
    if(init_keyboard() < 0) {
        syslog(LOG_ERR, "Keyboard handle could not be created.");
        exit(EXIT_FAILURE);
    }
    struct sockaddr client_addr;
    int client;
    int size;
    char input[readSize];
    while(1) {
        client = accept(sock, &client_addr, &size);
        if (client > 0) {
            syslog(LOG_INFO, "Client connected.");
            FILE *in = fdopen(client, "r");
            char* str = fgets(input, readSize, in);
            if (str == NULL) {
                syslog(LOG_ERR, "No text could be read on the socket.");
            } else {
                if (parse(input) < 0) {
                    syslog(LOG_ERR, "Something went wrong while parsing. Errno: %d", errno);
                };
            }
        }
    }

    puts("Daemon closing");
    return 0;
}
