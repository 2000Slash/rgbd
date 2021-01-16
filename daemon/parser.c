#include "keyboard.h"
#include <stdlib.h>
#include <syslog.h>
#include <string.h>

enum command {
    cmd_exit = 0,
    cmd_refresh = 1,
    cmd_change_color = 2,
};

void parse(char *input) {
    syslog(LOG_INFO, "Parsing: '%s'", input);
    enum command cmd;
    static char color[] = "ffffff";
    char command_char = input[0];
    cmd = atoi(&command_char);
    syslog(LOG_INFO, "Got command %d", cmd);
    switch (cmd) {
    case cmd_exit:
        syslog(LOG_INFO, "Received exit");
        exit(EXIT_SUCCESS);
    case cmd_change_color:
        memcpy(color, &input[1], 6);
        // Fallthrough necessary
    case cmd_refresh:
        setColor(color);
        break;
    default:
        break;
    }
}
