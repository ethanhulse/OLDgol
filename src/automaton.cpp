#include <iostream>
#include <string>
#include "../inc/automaton.h"

void Automaton::rgenerateGrid(bool grid0[GSIZE + 1][GSIZE + 1])
{
    for(int a = 0; a < GSIZE + 1; a++)
    {
        for(int b = 0; b < GSIZE + 1; b++)
        {
            int _r = std::experimental::randint(0,1);
            bool r;
            if(_r == 0){r = false;}
            else if(r == 1){r = true;}
            grid0[a][b] = r;

        }
    }
}

void Automaton::copyGrid(bool grid0[GSIZE + 1][GSIZE + 1], bool grid1[GSIZE + 1][GSIZE + 1])
{
    for(int a = 0; a < GSIZE; a++)
    {
        for(int b = 0; b < GSIZE; b++)
        {
            grid1[a][b] = grid0[a][b];
        }
    }
}

void Automaton::checkState(bool grid0[GSIZE + 1][GSIZE + 1])
{
    bool grid1[GSIZE + 1][GSIZE + 1] = {};
    copyGrid(grid0, grid1);

    //Permutates thru grid with (a,b)
    for(int a = 1; a < GSIZE; a++)
    {
        for(int b = 1; b < GSIZE; b++)
        {
            int alive = 0; //Number of surrounding cells that are alive
            for(int c = -1; c < 2; c++) //Permutates from [(-1,0),(0,0),(1,0)].
            {
                for(int d = -1; d < 2; d++) //Permutates from [(c,-1)(c,0)(c,1)] Covers all coordinates in a 3x3 matrix. IE 8 cardinal directions. [-1,0] is West, [1,1] is North East
                {
                    if(!(c == 0 && d == 0)) //Checks if cell at (c,d) is (0,0). if it is then it skips because that is current cell
                    {
                        if(grid1[a+c][b+d]) // Adds orthagonal pointer at grid2 to current cell coordinates, if that cell is alive then alive counter goes up. Basically adds 1 to int alive for every bit surrounding cell at (a,b) that is alive excluding that cell.
                        {
                            ++alive;
                        }
                    }
                }
            }
            if(alive < 2) //If live cells surrounding current cell is less than 2, current cell at grid1 dies
            {
                grid0[a][b] = false;
            }
            else if(alive == 3) //Else if live surrounding cells is 3, current cell at grid1 lives
            {
                grid0[a][b] = true;
            }
            else if(alive > 3) //Else if live cells surrounding cell is greater than 3, cell at dies
            {
                grid0[a][b] = false;
            }
        }
    }
}

void Automaton::clearGrid(bool grid0[GSIZE + 1][GSIZE + 1])
{
    for(int a = 0; a < GSIZE + 1; a++)
    {
        for(int b = 0; b < GSIZE + 1; b++)
        {
            grid0[a][b] = {false};
        }
    }
}
