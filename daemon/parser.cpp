#include "parser.h"
#include <cstdlib>
#include <syslog.h>
#include "keyboard/KeyboardParser.h"

#define offset 2

enum Command {
    cmd_exit = 0,
    cmd_refresh = 1,
    cmd_setall_color = 2,
    cmd_set_key = 3,
    cmd_set_color = 4,
};

int parse(char *text) {
    syslog(LOG_INFO, "Received %s.", text);
    std::string inputText(text);
    if(inputText.length() == 0) {
        return -1;
    }

    enum Command cmd;
    char command_char = text[0];

    char attribute;
    std::string color;

    cmd = static_cast<Command>(atoi(&command_char));

    switch(cmd) {
        LedKeyboard::KeyValue keyColor;
        case cmd_exit:
            syslog(LOG_INFO, "Received exit");
            attribute = text[1];
            if (attribute == '1') {
                Keyboard::saveConfig();
            }
            exit(EXIT_SUCCESS);
        case cmd_refresh:
            syslog(LOG_INFO, "Refreshing");
            Keyboard::refresh();
            return 0;
        case cmd_setall_color:
            attribute = text[1];
            syslog(LOG_INFO, "Setting all color.");
            color = std::string(&text[offset]);
            if (Keyboard::setAllKeys(color) < 0) return -1;
            if(attribute == '1') {
                Keyboard::refresh();
            }
            return 0;
        case cmd_set_key:
            attribute = text[1];
            keyColor = KeyboardParser::parseCharColor(std::string(&text[2]));
            color = std::string(&text[offset]);
            syslog(LOG_INFO, "Setting key %d.", keyColor.key);
            if (Keyboard::setKeyColor(keyColor) < 0) return -1;
            if(attribute == '1') {
                Keyboard::refresh();
            }
            return 0;
        case cmd_set_color:
            attribute = text[1];
            LedKeyboard::Color color1;
            LedKeyboard::Color color2;
            KeyboardParser::splitColors(std::string(&text[2]), color1, color2);
            Keyboard::replaceColor(color1, color2);
            if(attribute == '1') {
                Keyboard::refresh();
            }
            return 0;
    }

    return -1;

}
