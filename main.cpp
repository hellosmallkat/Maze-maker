#include "maze.h"
#include <iostream>
#include <fstream>


/*

<seed>  the seed value for the random number generator
<N>     number of rows in the grid N > 0
<M>     number of cols in the grid M > 0
<fname> file name for the output



*/
int main(int argc, char* argv[])
{
    
    int random_seed = std::stoi(argv[1]);

    Maze myMaze(std::stoi(argv[2]), std::stoi(argv[3])); // inputing rows and cols
    std::srand(random_seed);
    //Maze myMaze(row, cols);
    myMaze.maze_genterator();
    std::ofstream outputFile(argv[4]);

    
   myMaze.print(outputFile);

    outputFile.close();
    return 0;


}
