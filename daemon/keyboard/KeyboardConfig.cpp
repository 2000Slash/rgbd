#include "Keyboard.h"
#include <helpers/utils.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <iomanip>
#include <syslog.h>
#include <cstdlib>
#include <iostream>

std::ifstream inputStream;
char* homeDir = getenv("HOME");
char relativeConfig[] = "/.config/rgbd/config";
char configFileLocation[sizeof(homeDir)+sizeof(relativeConfig)];
void loadConfig(void);

void Keyboard::initConfig() {
    // check if config exists
    strcpy(configFileLocation, homeDir);
    strcat(configFileLocation, relativeConfig);
    inputStream = std::ifstream(configFileLocation);
    if( !inputStream.good() ) {
        Keyboard::saveConfig();
    } else {
        loadConfig();
    }
}

std::string colorToHex(LedKeyboard::Color color) {
    std::stringstream sstream;
    sstream << std::hex << std::setfill('0') << std::setw(2) << std::right << static_cast<int>(color.red);
    sstream << std::hex << std::setfill('0') << std::setw(2) << std::right << static_cast<int>(color.green);
    sstream << std::hex << std::setfill('0') << std::setw(2) << std::right << static_cast<int>(color.blue);
    return sstream.str();
}

void loadConfig() {
    std::string s;
    LedKeyboard::KeyValueArray array;
    while (inputStream >> s) {
        int index = s.find(";");
        std::string keyString = s.substr(0, index);
        std::string colorString = s.substr(index+1, 6);
        LedKeyboard::KeyValue keyColor;
        uint16_t key = std::stoi(keyString);
        LedKeyboard::Color color;
        utils::parseColor(colorString, color);
        keyColor.key = (LedKeyboard::Key)key;
        keyColor.color = color;
        array.push_back(keyColor);
    }
    Keyboard::setKeyColors(array);
}


void Keyboard::saveConfig() {
    std::ofstream configFile(configFileLocation);
    for (LedKeyboard::KeyValue &key: Keyboard::getKeyColors()) {
        configFile << std::to_string(static_cast<uint16_t>(key.key)) + ";";
        configFile << colorToHex(key.color) << std::endl;
    }
}
