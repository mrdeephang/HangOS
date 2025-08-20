#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>

namespace Screen {
    void clear();
    void putChar(char c, int x, int y);
    void print(const char* str);
    void scroll();
}

#endif