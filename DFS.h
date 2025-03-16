#ifndef DFS_H
#define DFS_H
#include "Grid.h"
#include "MyStack.h"
#include <vector>
using namespace std;
class DFS{
    private:
    Grid& grid;
    vector<vector<bool>>visited;

    public:
    DFS(Grid& g);
    void search(int startX, int startY);
};
#include"DFS.cpp"
#endif 