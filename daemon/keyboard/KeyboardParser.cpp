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

void KeyboardParser::splitColors(std::string input, LedKeyboard::Color& color1, LedKeyboard::Color& color2) {
    std::string color1str = input.substr(0, 6);
    std::string color2str = input.substr(6, 6);
    utils::parseColor(color1str, color1);
    utils::parseColor(color2str, color2);
}
