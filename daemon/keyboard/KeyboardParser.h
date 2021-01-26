#ifndef __KEYBOARDPARSER_H_
#define __KEYBOARDPARSER_H_

#include "Keyboard.h"
#include <string>

namespace KeyboardParser {
        LedKeyboard::KeyValueArray parse(std::string);
}


#endif // __KEYBOARDPARSER_H_
