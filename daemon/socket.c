#include "socket.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/syslog.h>

#define BACKLOG 10


void setup_socket() {
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    if( sock < 0) {
        exit(EXIT_FAILURE);
    }

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    char *socket_path = "/home/nils/test.sock";
    strcpy(addr.sun_path, socket_path);
    if (bind(sock, (struct sockaddr*)&addr, sizeof(struct sockaddr_un)) < 0) {
        syslog(LOG_ERR, "Error on socket creation for the daemon: %d", errno);
        exit(EXIT_FAILURE);
    }
    syslog(LOG_INFO, "Socket spawned");
    listen(sock, BACKLOG);
    long save_fd = fcntl(sock, F_GETFL);
    save_fd |= O_NONBLOCK;
    fcntl(sock, F_SETFL, save_fd);
    // Use non blocking mode. This way we can check for new connections but also for new usb devices connected

    struct sockaddr client_addr;
    int client;
    int size;
    while(1) {
        client = accept(sock, &client_addr, &size);
        if (client > 0) {
            syslog(LOG_INFO, "Client connected.");
            exit(EXIT_SUCCESS);
        }
        syslog(LOG_INFO, "Doin smth else");
        sleep(1);
    }
}
