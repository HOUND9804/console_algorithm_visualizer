#ifndef BFS_H
#define BFS_H

#include "Grid.h"
#include "MyQueue.h"
#include <vector>
#include <thread>
#include <chrono>

class BFS {
private:
    Grid& grid;
    std::vector<std::vector<bool>> visited;

public:
    BFS(Grid& g);
    void search(int startX, int startY);
};

#endif // BFS_H
