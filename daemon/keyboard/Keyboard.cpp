#include "Keyboard.h"
#include <syslog.h>
#include <algorithm>

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

LedKeyboard::KeyValueArray Keyboard::getKeyColors() {
    return keyColors;
}

void Keyboard::setKeyColors(LedKeyboard::KeyValueArray array) {
    keyColors = array;
}

int init_keyboard() {
    std::string serial;
    uint16_t vendorID = 0x0;
    uint16_t productID = 0x0;

    if (!kbd.open(vendorID, productID, serial)) {
        return -1;
    }

    // initialize keyColors array
    LedKeyboard::Color color = {255, 255, 255};
    for (uint8_t i = 0; i < Keyboard::keyGroupLogo.size(); i++) keyColors.push_back({Keyboard::keyGroupLogo[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupIndicators.size(); i++) keyColors.push_back({Keyboard::keyGroupIndicators[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupMultimedia.size(); i++) keyColors.push_back({Keyboard::keyGroupMultimedia[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupGKeys.size(); i++) keyColors.push_back({Keyboard::keyGroupGKeys[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupFKeys.size(); i++) keyColors.push_back({Keyboard::keyGroupFKeys[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupFunctions.size(); i++) keyColors.push_back({Keyboard::keyGroupFunctions[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupArrows.size(); i++) keyColors.push_back({Keyboard::keyGroupArrows[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupNumeric.size(); i++) keyColors.push_back({Keyboard::keyGroupNumeric[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupModifiers.size(); i++) keyColors.push_back({Keyboard::keyGroupModifiers[i], color});
    for (uint8_t i = 0; i < Keyboard::keyGroupKeys.size(); i++) keyColors.push_back({Keyboard::keyGroupKeys[i], color});

    Keyboard::initConfig();
    Keyboard::refresh();
    return 0;
}

// Either finds the key in KeyColors or returns the last value. Similar to Vector::find
LedKeyboard::KeyValue* findKeyValue(LedKeyboard::Key key) {
    for(auto& value: keyColors) {
        if(value.key == key) {
            return &value;
        }
    }
    return nullptr;
}


int Keyboard::setKeyColor(LedKeyboard::KeyValue keyColor) {
    LedKeyboard::KeyValue* key = findKeyValue(keyColor.key);
    if(key == nullptr) {
        syslog(LOG_ERR, "Key could not be found");
        return -1;
    }
    key->color = keyColor.color;
    syslog(LOG_INFO, "Key %d found: %d, %d, %d", key->key, key->color.red, key->color.green, key->color.blue);
    return 0;
}


int Keyboard::setAllKeys(std::string colorString) {
    keyColors.clear();
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
