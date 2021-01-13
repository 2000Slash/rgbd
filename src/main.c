#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <sys/un.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int sock = socket(AF_UNIX, SOCK_STREAM, 0);
    char *path = "/tmp/rgbd.sock";
    struct sockaddr_un server;
    server.sun_family = AF_UNIX;
    strcpy(server.sun_path, path);
    int i = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if(i < 0) {
        printf("Fehler: %d", errno);
    }
    write(sock, argv[1], 7);
    close(sock);
    close(i);
}
