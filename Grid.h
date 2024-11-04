#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Color.h" 

class Grid {
private:
    std::vector<std::vector<char>> grid;
    int rows, cols;

public:
    Grid(int r, int c);
    void inputGrid();
    char& operator()(int r, int c);
    int getRows() const;
    int getCols() const;
    void printGrid() const;
    void clearConsole() const;
};
#include "Grid.cpp"
#include"BFS.cpp"
#endif // GRID_H
