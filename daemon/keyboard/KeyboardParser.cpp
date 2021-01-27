#include "KeyboardParser.h"
#include <helpers/utils.h>
#include <syslog.h>

LedKeyboard::KeyValue KeyboardParser::parseCharColor(std::string input) {
    int index = input.find(";");
    if (index == input.npos)  {
        return LedKeyboard::KeyValue{};
    }
    std::string keyString = input.substr(0, index);
    std::string colorString = input.substr(index+1, 6);
    syslog(LOG_INFO, "Parsed key %s and Color \"%s\"", keyString.c_str(), colorString.c_str());
    LedKeyboard::Key key;
    LedKeyboard::Color color;
    utils::parseKey(keyString, key);
    utils::parseColor(colorString, color);
    LedKeyboard::KeyValue keyColor = {key, color};
    return keyColor;
}
