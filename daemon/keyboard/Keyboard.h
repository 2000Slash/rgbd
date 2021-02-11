#ifndef __KEYBOARD_H_
#define __KEYBOARD_H_

#include <classes/Keyboard.h>
#include "Keyboard_C.h"

namespace Keyboard {
    // Sets the color of all keys in KeyArray to the color defined in the string
    int setAllKeys(std::string);
    // commits the current keyConfig to the keyboard
    int refresh();
    // Sets a specific key to a specific color
    int setKeyColor(LedKeyboard::KeyValue);
    // inits the config
    void initConfig();
    LedKeyboard::KeyValueArray getKeyColors();
    void setKeyColors(LedKeyboard::KeyValueArray array);
    void saveConfig();
    void replaceColor(LedKeyboard::Color, LedKeyboard::Color);

    typedef std::vector<LedKeyboard::Key> KeyArray;

    const KeyArray keyGroupLogo = { LedKeyboard::Key::logo, LedKeyboard::Key::logo2 };
    const KeyArray keyGroupIndicators = { LedKeyboard::Key::caps, LedKeyboard::Key::num, LedKeyboard::Key::scroll, LedKeyboard::Key::game, LedKeyboard::Key::backlight };
    const KeyArray keyGroupMultimedia = { LedKeyboard::Key::next, LedKeyboard::Key::prev, LedKeyboard::Key::stop, LedKeyboard::Key::play, LedKeyboard::Key::mute };
    const KeyArray keyGroupGKeys = { LedKeyboard::Key::g1, LedKeyboard::Key::g2, LedKeyboard::Key::g3, LedKeyboard::Key::g4, LedKeyboard::Key::g5, LedKeyboard::Key::g6, LedKeyboard::Key::g7, LedKeyboard::Key::g8, LedKeyboard::Key::g9 };
    const KeyArray keyGroupFKeys = {
    LedKeyboard::Key::f1, LedKeyboard::Key::f2, LedKeyboard::Key::f3, LedKeyboard::Key::f4, LedKeyboard::Key::f5, LedKeyboard::Key::f6,
    LedKeyboard::Key::f7, LedKeyboard::Key::f8, LedKeyboard::Key::f9, LedKeyboard::Key::f10, LedKeyboard::Key::f11, LedKeyboard::Key::f12
};
    const KeyArray keyGroupModifiers = {
    LedKeyboard::Key::shift_left, LedKeyboard::Key::ctrl_left, LedKeyboard::Key::win_left, LedKeyboard::Key::alt_left,
    LedKeyboard::Key::alt_right, LedKeyboard::Key::win_right, LedKeyboard::Key::ctrl_right, LedKeyboard::Key::shift_right, LedKeyboard::Key::menu };
    const KeyArray keyGroupFunctions = {
    LedKeyboard::Key::esc, LedKeyboard::Key::print_screen, LedKeyboard::Key::scroll_lock, LedKeyboard::Key::pause_break,
    LedKeyboard::Key::insert, LedKeyboard::Key::del, LedKeyboard::Key::home, LedKeyboard::Key::end, LedKeyboard::Key::page_up, LedKeyboard::Key::page_down
};
    const KeyArray keyGroupArrows = { LedKeyboard::Key::arrow_top, LedKeyboard::Key::arrow_left, LedKeyboard::Key::arrow_bottom, LedKeyboard::Key::arrow_right };
    const KeyArray keyGroupNumeric = {
    LedKeyboard::Key::num_1, LedKeyboard::Key::num_2, LedKeyboard::Key::num_3, LedKeyboard::Key::num_4, LedKeyboard::Key::num_5,
    LedKeyboard::Key::num_6, LedKeyboard::Key::num_7, LedKeyboard::Key::num_8, LedKeyboard::Key::num_9, LedKeyboard::Key::num_0,
    LedKeyboard::Key::num_dot, LedKeyboard::Key::num_enter, LedKeyboard::Key::num_plus, LedKeyboard::Key::num_minus,
    LedKeyboard::Key::num_asterisk, LedKeyboard::Key::num_slash, LedKeyboard::Key::num_lock
};
    const KeyArray keyGroupKeys = {
    LedKeyboard::Key::a, LedKeyboard::Key::b, LedKeyboard::Key::c, LedKeyboard::Key::d, LedKeyboard::Key::e, LedKeyboard::Key::f, LedKeyboard::Key::g, LedKeyboard::Key::h, LedKeyboard::Key::i, LedKeyboard::Key::j, LedKeyboard::Key::k, LedKeyboard::Key::l, LedKeyboard::Key::m,
    LedKeyboard::Key::n, LedKeyboard::Key::o, LedKeyboard::Key::p, LedKeyboard::Key::q, LedKeyboard::Key::r, LedKeyboard::Key::s, LedKeyboard::Key::t, LedKeyboard::Key::u, LedKeyboard::Key::v, LedKeyboard::Key::w, LedKeyboard::Key::x, LedKeyboard::Key::y, LedKeyboard::Key::z,
    LedKeyboard::Key::n1, LedKeyboard::Key::n2, LedKeyboard::Key::n3, LedKeyboard::Key::n4, LedKeyboard::Key::n5, LedKeyboard::Key::n6, LedKeyboard::Key::n7, LedKeyboard::Key::n8, LedKeyboard::Key::n9, LedKeyboard::Key::n0,
    LedKeyboard::Key::enter, LedKeyboard::Key::backspace, LedKeyboard::Key::tab, LedKeyboard::Key::space, LedKeyboard::Key::minus, LedKeyboard::Key::equal,
    LedKeyboard::Key::open_bracket, LedKeyboard::Key::close_bracket, LedKeyboard::Key::backslash, LedKeyboard::Key::dollar, LedKeyboard::Key::semicolon, LedKeyboard::Key::quote, LedKeyboard::Key::tilde,
    LedKeyboard::Key::comma, LedKeyboard::Key::period, LedKeyboard::Key::slash, LedKeyboard::Key::caps_lock, LedKeyboard::Key::intl_backslash
};
}

#endif // __KEYBOARD_H_
