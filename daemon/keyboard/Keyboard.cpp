#include "Keyboard.h"

int setAllKeys(LedKeyboard &kbd, std::string arg2);
bool parseColor(std::string val, LedKeyboard::Color &color);

LedKeyboard kbd;
LedKeyboard::KeyValueArray keyColors;

int Keyboard::refresh() {
    if (! kbd.open()) return 1;
    if (!kbd.setKeys(keyColors)) return 1;
    if (!kbd.commit()) return 1;
    return 0;
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


int Keyboard::setAllKeys(std::string colorString) {
    LedKeyboard::Color color;
    if (! parseColor(colorString, color)) return 1;
    for (uint8_t i = 0; i < keyGroupLogo.size(); i++) keyColors.push_back({keyGroupLogo[i], color});
    for (uint8_t i = 0; i < keyGroupIndicators.size(); i++) keyColors.push_back({keyGroupIndicators[i], color});
    for (uint8_t i = 0; i < keyGroupMultimedia.size(); i++) keyColors.push_back({keyGroupMultimedia[i], color});
    for (uint8_t i = 0; i < keyGroupGKeys.size(); i++) keyColors.push_back({keyGroupGKeys[i], color});
    for (uint8_t i = 0; i < keyGroupFKeys.size(); i++) keyColors.push_back({keyGroupFKeys[i], color});
    for (uint8_t i = 0; i < keyGroupFunctions.size(); i++) keyColors.push_back({keyGroupFunctions[i], color});
    for (uint8_t i = 0; i < keyGroupArrows.size(); i++) keyColors.push_back({keyGroupArrows[i], color});
    for (uint8_t i = 0; i < keyGroupNumeric.size(); i++) keyColors.push_back({keyGroupNumeric[i], color});
    for (uint8_t i = 0; i < keyGroupModifiers.size(); i++) keyColors.push_back({keyGroupModifiers[i], color});
    for (uint8_t i = 0; i < keyGroupKeys.size(); i++) keyColors.push_back({keyGroupKeys[i], color});
    refresh();
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
