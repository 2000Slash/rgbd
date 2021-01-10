#include "fork.h"

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
    return 0;
}
