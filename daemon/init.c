#include "fork.h"
#include "socket.h"
#include <sys/syslog.h>

int main() {
    openlog("rgbd", LOG_PID, LOG_USER);
    setup_daemon();
    // Now we are the daemon (two parents quit). Our location is / and we don't have any file descriptors open
    setup_socket();
    // A socket is now created

    while (1)
    {
        //TODO: Insert daemon code here.
        puts("Hello World");
        sleep (20);
        break;
    }

    puts("Goodbye cruel world");
    return 0;
}
