#include "Keyboard.h"

int setAllKeys(LedKeyboard &kbd, std::string arg2);
bool parseColor(std::string val, LedKeyboard::Color &color);

LedKeyboard kbd;

int Keyboard::setFullColor(std::string color) {
    return setAllKeys(kbd, color);
}

int init_keyboard() {
    std::string serial;
    uint16_t vendorID = 0x0;
    uint16_t productID = 0x0;

    if (!kbd.open(vendorID, productID, serial)) {
        return -1;
    }
    return 0;
}


int setAllKeys(LedKeyboard &kbd, std::string arg2) {
    LedKeyboard::Color color;
    if (! parseColor(arg2, color)) return 1;
    if (! kbd.open()) return 1;
    if(! kbd.setAllKeys(color)) return 1;
    if(! kbd.commit()) return 1;
    return 0;
}

bool parseColor(std::string val, LedKeyboard::Color &color) {
    if (val.length() == 2) val = val + "0000";  // For G610
    if (val.length() != 6) return false;
    color.red = std::stoul("0x"+val.substr(0,2), nullptr, 16);
    color.green = std::stoul("0x"+val.substr(2,2), nullptr, 16);
    color.blue = std::stoul("0x"+val.substr(4,2), nullptr, 16);
    return true;
}
