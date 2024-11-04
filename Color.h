#ifndef COLOR_H
#define COLOR_H

#include <windows.h> // For Windows console color

class Color {
public:
    static void set(int color);
    static void reset();
};
#include "Color.cpp"
#endif // COLOR_H
