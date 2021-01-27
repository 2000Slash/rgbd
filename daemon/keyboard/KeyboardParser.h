#ifndef __KEYBOARDPARSER_H_
#define __KEYBOARDPARSER_H_

#include "Keyboard.h"
#include <string>

namespace KeyboardParser {
        // Parses a key and a color seperated by a semicolon. For example "a;ff0000" returns a KeyValue of key a and a color of ff0000
        LedKeyboard::KeyValue parseCharColor(std::string);
}


#endif // __KEYBOARDPARSER_H_
