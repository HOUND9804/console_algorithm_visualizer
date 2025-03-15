#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "Grid.h"
#include "My_Unordered_Map.h"
#include <vector>
#include <queue>
#include <utility>

class Dijkstra {
public:
    // Constructor
    Dijkstra(Grid& g);

    // Method to search for the shortest path from start to end
    void search(int startX, int startY, int endX, int endY);

private:
    Grid& grid;  // Reference to the grid object
    std::vector<std::vector<int>> distance;  // 2D vector to track the minimum distance to each cell
    std::vector<std::vector<bool>> visited;  // 2D vector to track visited cells

    // Hash function for pairs to use in unordered_map
    struct hash_pair {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            auto hash1 = std::hash<T1>{}(p.first);
            auto hash2 = std::hash<T2>{}(p.second);
            return hash1 ^ hash2;
        }
    };
};
#include"Dijkstra.cpp"
#endif // DIJKSTRA_H
