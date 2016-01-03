#include <SFML/Graphics.hpp>
#include "Board.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(768, 768), "Game Name Pending");

    //Load/Create Level
    Board * level = new Board();
    level->loadLevel("./Levels/Test.txt");
    // let's define a view
    sf::View view(sf::FloatRect(0, 0, 192, 192));


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //view.move(0, 1);
        // activate it
        window.setView(view);
        window.clear(); //sf::Color(200, 0, 0)
        level->draw(window);
        //window.draw();
        window.display();
    }

    return 0;
}
