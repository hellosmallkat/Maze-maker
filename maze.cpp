#include "maze.h"
Maze::Maze(int rows, int cols)
{
    row = rows; // rows
    col = cols; // cols
    
    grid.resize(rows,std::vector<int>(cols,15)); // create a grid 


}

void Maze::maze_genterator()
{
    
    std::vector<std::pair<int,int>> correnadtes; // holds the cords of the grid 
    grid[0][0] = 7;// visted

    correnadtes.push_back(make_pair(0,0)); // push back the cords of the grid
    while (!correnadtes.empty()) // runs while there are still unvisted cells
    {
        std::pair<int,int> current = correnadtes.back(); // gets the last element in the vector
      
        int x = current.first; // x cord
        int y = current.second; // y cord
        
        correnadtes.pop_back(); // pops the last element in the vector
        std::vector<char> neighbors; // hold neighbors of the current cell

        if(x - 1 >= 0 && grid[x-1][y] == 15) // north neighbor
        {
            neighbors.push_back('N'); // assgins north
           
        }
        if (x + 1 < row && grid[x+1][y] == 15) // south neighbor
        {
            neighbors.push_back('S'); // assgins south
        }
         if (y + 1 < col && grid[x][y+1] == 15) // east neighbor
        {
            neighbors.push_back('E'); // assgins east
        }
       if (y - 1 >= 0 && grid[x][y-1] == 15) // west neighbor
        {
            neighbors.push_back('W'); // assgins west
        }
       
      if (neighbors.size() > 0) // while there are still neighbors
       {
        correnadtes.push_back(make_pair(x,y)); // pushs cuurent 
           
       
            int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size()); // random index

            if (neighbors[idx] == 'N') // if north
            {
        
                grid[x][y] -= 8;  // removes north wall
                 grid[x-1][y] -= 4; // removes south wall
                 correnadtes.push_back(make_pair(x - 1,y)); // pushs not current    


             }
            if (neighbors[idx] == 'S') // if south
             {
                  grid[x][y] -= 4; // removes south wall
                 grid[x+1][y] -= 8; // removes north wall
                 correnadtes.push_back(make_pair(x + 1,y)); // pushs not current
             }
            if (neighbors[idx] == 'E') // if east
            {
                grid[x][y] -= 2; // removes east wall
                grid[x][y+1] -= 1; // removes west wall
                correnadtes.push_back(make_pair(x,y + 1)); // pushs not current
            }
            if (neighbors[idx] == 'W') // if west
            {
                grid[x][y] -= 1; // removes west wall
                grid[x][y-1] -= 2; // removes east wall
                correnadtes.push_back(make_pair(x,y- 1)); // pushs not current

            }
            
           
       

       }
        
    }
    grid[row - 1][col - 1] -= 4; // fixes final cell
   

}

 void Maze::print(std::ostream& out) const { // print function
        for (int i = 0; i < row; i++) { // loops through the grid
            for (int j = 0; j < col; j++) {
                out << grid[i][j] << " "; // inputs the grid into the file
            }
            out << std::endl;
        }
    }
