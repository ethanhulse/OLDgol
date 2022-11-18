#include "../inc/automaton.h"

void Automaton::drawGrid(sf::RenderTarget& t, bool grid0[GSIZE + 1][GSIZE + 1])
{
    float z = this->cell_size;
    sf::Vector2f lw(z,z);
    for(int x = 0; x < GSIZE + 1; x++)
    {
        for(int y = 0; y < GSIZE+ 1; y++)
        {   
            sf::RectangleShape s(lw);
            switch(grid0[x][y])
            {
                case true:
                    s.setFillColor(sf::Color::White);
                    break;
                case false:
                    continue;
                    break;
            }

            sf::Vector2f xy((float)x * z, (float)y * z);
            s.setPosition(xy);
            t.draw(s);
        }
    }
}

void Automaton::Run(bool grid0[GSIZE + 1][GSIZE + 1])
{
    int n = 0;
    sf::RenderWindow w(sf::VideoMode(GSIZE, GSIZE), "gol", sf::Style::Close);
    w.setVerticalSyncEnabled(false);

    std::cout << "Hit 'R to start Conway's Game of Life.." << std::endl;
    sf::Clock LOOP;
    bool started = false;
    while(w.isOpen())
    {
        sf::Event e;
        while(w.pollEvent(e))
        {
            switch(e.type)
            {
                case sf::Event::Closed:
                    w.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(e.key.code)
                    {
                        case sf::Keyboard::Escape:
                            w.close();
                            break;
                        case sf::Keyboard::R:
                            w.clear();
                            sf::Clock clock;
                            if(started)
                            {
                                this->clearGrid(grid0);
                                this->checkState(grid0);
                                std::system("clear");
                            }
                            else{
                                this->rgenerateGrid(grid0);
                            }
                            this->drawGrid(w, grid0);
                            w.display();
                            sf::Time buildTime = clock.getElapsedTime();
                            float bt = buildTime.asMilliseconds();
                            std::cout << n << ":" << bt << std::endl;
                            started = true;
                            break;

                    }
                    break;
            }
        }
    }
}
