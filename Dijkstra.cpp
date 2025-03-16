#include "Dijkstra.h"
#include <iostream>
#include <queue>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <limits>

using namespace std;

Dijkstra::Dijkstra(Grid& g)
    : grid(g),
      distance(g.getRows(), vector<int>(g.getCols(), numeric_limits<int>::max())),
      visited(g.getRows(), vector<bool>(g.getCols(), false)) {}

void Dijkstra::search(int startX, int startY, int endX, int endY) {
    if (grid(startX, startY) == '#' || grid(endX, endY) == '#') {
        cout << "Starting or ending point is blocked.\n";
        return;
    }

    // Min-heap priority queue storing pairs of {distance, {x, y}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    unordered_map<pair<int, int>, pair<int, int>, hash_pair> parent;  // Track the path for backtracking

    // Initialize the start position
    pq.push({0, {startX, startY}});
    distance[startX][startY] = 0;

    // Direction vectors for moving Down, Up, Right, Left
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    bool found = false;

    while (!pq.empty() && !found) {
        auto [dist, cell] = pq.top();
        pq.pop();
        int x = cell.first;
        int y = cell.second;

        if (visited[x][y]) continue;
        visited[x][y] = true;

        grid(x, y) = 'V';

        if (x == endX && y == endY) {  // Stop if the end is reached
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (newX >= 0 && newX < grid.getRows() && newY >= 0 && newY < grid.getCols() &&
                grid(newX, newY) == '.' && !visited[newX][newY]) {

                int newDist = dist + 1;  // Cost of moving to adjacent cells is 1

                if (newDist < distance[newX][newY]) {
                    distance[newX][newY] = newDist;
                    pq.push({newDist, {newX, newY}});
                    grid(newX,newY)='P';
                    parent[{newX, newY}] = {x, y};  // Track the parent node
                }
            }
            grid.printGrid(newX,newY);
        }
    }

    // Backtrack to mark the shortest path
    if (found) {
        pair<int, int> step = {endX, endY};
        while (step != make_pair(startX, startY)) {
            grid(step.first, step.second) = '!';  
            grid.printGrid(step.first,step.second);
            step = parent[step];
        }
        grid(startX, startY) = 'S';  // Start position
        grid(endX, endY) = 'E';      // End position
        grid.printGrid(grid.getRows()+1,grid.getCols()+1);
    } else {
        cout << "No path found from start to end.\n";
    }
}
