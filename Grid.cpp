#include "Grid.h"

using namespace std;

Grid::Grid(int r, int c) : rows(r), cols(c), grid(r, vector<char>(c)) {}

void Grid::inputGrid() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> grid[i][j];
        }
    }
}

char& Grid::operator()(int r, int c) {
    return grid[r][c];
}

int Grid::getRows() const { return rows; }

int Grid::getCols() const { return cols; }

void Grid::printGrid() const {
    clearConsole();
    for (const auto& row : grid) {
        for (char cell : row) {
            if(cell=='V'){
                Color::set(3); // Assuming Color is a class handling console colors
            }
            else{
                Color::reset();
            }
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Grid::clearConsole() const {
    cout << "\033[2J\033[H"; // ANSI escape sequence to clear the console
}
