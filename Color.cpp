#include "Color.h"

// Set console color
void Color::set(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Reset console color to default
void Color::reset() {
    set(7); // 7 is the default color for console text in Windows
}
