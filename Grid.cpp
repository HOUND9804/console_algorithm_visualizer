#include "Grid.h"
#include <cstdlib> 
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

void Grid::printGrid(int x,int y) const {
    clearConsole();
    cout<<"V represent visited cell \n";
    cout<<"p represent the pending cell to be visited\n";
    cout<<"The purple color represent the presently pointed cell\n \n";
    for (int i=0;i<rows;i++) {
        for (int j=0;j<cols;j++) {
           char cell=grid[i][j];
           if(cell=='V'){
            paint.set(3);
           }
           else if(i==x&&j==y){
            paint.set(5);
           }
           else if(cell=='p'){
            paint.set(4);
           }
           else{
            paint.reset();
           }
           cout<<cell<<" ";
        }
        cout << endl;
    }
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
}

void Grid::clearConsole() const {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear");
#endif
}

