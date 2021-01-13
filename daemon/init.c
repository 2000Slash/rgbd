#include "fork.h"
#include "socket.h"
#include <sys/syslog.h>
#include "keyboard.h"

int main() {
    openlog("rgbd", LOG_PID, LOG_USER);
    setup_daemon();
    // Now we are the daemon (two parents quit). Our location is / and we don't have any file descriptors open
    int sock = setup_socket();
    // A socket is now created

    struct sockaddr client_addr;
    int client;
    int size;
    char color[10];
    while(1) {
        client = accept(sock, &client_addr, &size);
        if (client > 0) {
            syslog(LOG_INFO, "Client connected.");
            FILE *in = fdopen(client, "r");
            fgets(color, 10, in);
            syslog(LOG_INFO, "Received color: %s", color);
            setColor(color);
        }
    }

    puts("Daemon closing");
    return 0;
}
