#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <utility>
using namespace std;

class Maze
{
    private:

        int row, col; // rows and cols or grid
        std::vector<std::vector<int>> grid; // grid
        int seed = 0;
        
    public:

        Maze(int rows, int cols); // constructor
        void maze_genterator(); // maze generator
        void print(std::ostream& out) const; // print function for the maze


};
