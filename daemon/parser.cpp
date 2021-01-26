#include "parser.h"
#include <cstdlib>
#include <syslog.h>
#include "keyboard/KeyboardParser.h"

#define offset 2

enum Command {
    cmd_exit = 0,
    cmd_refresh = 1,
    cmd_setall_color = 2,
};

int parse(char *text) {
    syslog(LOG_INFO, "Received %s.", text);
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
        case cmd_refresh:
            syslog(LOG_INFO, "Refreshing");
            Keyboard::refresh();
            return 0;
        case cmd_setall_color:
            char attribute;
            attribute = text[1];
            syslog(LOG_INFO, "Setting all color. Attribute: %c", attribute);
            std::string color(&text[offset]);
            if (Keyboard::setAllKeys(color) < 0) return -1;
            if(attribute == '1') {
                Keyboard::refresh();
            }
            return 0;
    }

    return -1;

}
