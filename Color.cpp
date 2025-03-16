#include "Color.h"

void Color::set(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}


void Color::reset() {
    set(7); 
}
