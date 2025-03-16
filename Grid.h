#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Color.h" 
#include "Thread"
class Grid {
private:
    std::vector<std::vector<char>> grid;
    int rows, cols;
    Color paint;

public:
    Grid(int r, int c);
    void inputGrid();
    char& operator()(int r, int c);
    int getRows() const;
    int getCols() const;
    void printGrid(int x,int y) const;
    void clearConsole() const;
};
#include "Grid.cpp"
#include"BFS.cpp"
#endif // GRID_H
