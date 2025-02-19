#include "DFS.h"
#include <iostream>
#include <stack>

using namespace std;

DFS::DFS(Grid& g) : grid(g), visited(g.getRows(), vector<bool>(g.getCols(), false)) {}

void DFS::search(int startX, int startY) {
    if (grid(startX, startY) == '#') {
        cout << "Starting point is blocked.\n";
        return;
    }

    stack<pair<int, int>> s;
    s.push({startX, startY});
    visited[startX][startY] = true;

    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();

        grid(x, y) = 'V';
        grid.printGrid();
        this_thread::sleep_for(chrono::milliseconds(500));

        vector<int> dx = {1, -1, 0, 0};  // Down, Up, Right, Left
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < grid.getRows() && newY >= 0 && newY < grid.getCols() &&
                !visited[newX][newY] && grid(newX, newY) == '.') {
                s.push({newX, newY});
                grid(newX,newY)='p';
                visited[newX][newY] = true;
            }
        }
    }
}
