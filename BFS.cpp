#include "BFS.h"
#include <iostream>

BFS::BFS(Grid& g) : grid(g), visited(g.getRows(), std::vector<bool>(g.getCols(), false)) {}

void BFS::search(int startX, int startY) {
    using namespace std;

    if (grid(startX, startY) == '#') {
        cout << "Starting point is blocked.\n";
        return;
    }

    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        grid(x, y) = 'V';
        grid.printGrid();
        this_thread::sleep_for(chrono::milliseconds(500));

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < grid.getRows() && newY >= 0 && newY < grid.getCols() &&
                !visited[newX][newY] && grid(newX, newY) == '.') {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}
