#include "parser.h"
#include <cstdlib>
#include <syslog.h>
#include "keyboard/KeyboardParser.h"

enum Command {
    cmd_exit = 0,
    cmd_refresh = 1,
    cmd_setall_color = 2,
};

int parse(char *text) {
    std::string inputText(text);
    if(inputText.length() == 0) {
        return -1;
    }

    enum Command cmd;
    char command_char = text[0];
    cmd = static_cast<Command>(atoi(&command_char));

    switch(cmd) {
        case cmd_exit:
            syslog(LOG_INFO, "Received exit");
            exit(EXIT_SUCCESS);
        case cmd_setall_color:
            syslog(LOG_INFO, "Setting all color");
            std::string color(&text[1]);
            return KeyboardParser::setAllKeys(color);
    }

    return -1;

}
