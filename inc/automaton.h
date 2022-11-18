#ifndef AUTOMATON_H
#define AUTOMATON_H

#include <experimental/random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

const int GSIZE = 50;
const float CSIZE = 1.0f;

enum Seed
{
    FIB, RAND1
};

class Automaton
{
    
    
    public:
        Automaton();
        ~Automaton();
        

    //Logic
    void rgenerateGrid(bool _grid0[GSIZE + 1][GSIZE + 1]);
    void checkState(bool grid0[GSIZE + 1][GSIZE + 1]); 
    void copyGrid(bool grid0[GSIZE + 1][GSIZE + 1], bool grid1[GSIZE + 1][GSIZE + 1]);

    //Graphics
    void drawGrid(sf::RenderTarget& t, bool grid0[GSIZE + 1][GSIZE + 1]);
    void clearGrid(bool grid0[GSIZE + 1][GSIZE + 1]);
    //void SetCellSize(float cell_size);

    //System
    void Run(bool grid0[GSIZE + 1][GSIZE + 1]);

    private:
        float cell_size = CSIZE;
};

#endif