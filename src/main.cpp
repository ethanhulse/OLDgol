#include "automaton.cpp"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(){

    Automaton _auto;

    bool thegrid[GSIZE+1][GSIZE+1];

    _auto.rgenerateGrid(thegrid);
    _auto.Run(thegrid);

    do{
        std::cout << "Press any key to continue...";
    }while( std::cin.get() != '\n');

    return 0;
}
