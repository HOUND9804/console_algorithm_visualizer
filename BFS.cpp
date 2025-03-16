#include "BFS.h"
#include <iostream>
#include "MyQueue.h"  

BFS::BFS(Grid& g) : grid(g), visited(g.getRows(), std::vector<bool>(g.getCols(), false)) {}

void BFS::search(int startX, int startY) {
    using namespace std;

    if (grid(startX, startY) == '#') {
        cout << "Starting point is blocked.\n";
        return;
    }

    MyQueue<pair<int, int>> q;  // Change queue to MyQueue
    q.enqueue({startX, startY}); // Use MyQueue's enqueue method
    visited[startX][startY] = true;

    while (!q.isEmpty()) {  // Check if MyQueue is empty
        auto [x, y] = q.front();  // Use MyQueue's front method
        q.dequeue();  // Use MyQueue's dequeue method

        grid(x, y) = 'V';

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < grid.getRows() && newY >= 0 && newY < grid.getCols() &&
                !visited[newX][newY] && grid(newX, newY) == '.') {
                q.enqueue({newX, newY});  // Use MyQueue's enqueue method
                grid(newX, newY) = 'p';
                visited[newX][newY] = true;
            }
            grid.printGrid(newX,newY);
        }
    }
}
