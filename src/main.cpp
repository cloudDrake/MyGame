#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(768, 768), "Game Name Pending");

    //Load/Create Level
    Board * level = new Board();
    level->loadLevel("./Levels/Overworld.txt");
    Player * player1 = new Player("Images/hero.png");
    // let's define a view
    sf::View view(sf::FloatRect(0, 0, 192, 192));

    //fps/update control variables.
    sf::Clock clock;
    sf::Time lastTime = clock.restart(); //System time
    double delta = 0.0; //Diff of lastTime and currentTime
    double ns = 1000000000.0/60.0; //unit of a nanosecond.

    //Main game loop
    while (window.isOpen())
    {
        sf::Event event;
        //event loop, keybindings.
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else
            //check if the event was a keypressed event.
            if (event.type == sf::Event::KeyPressed)
            {
                //determine what key was pressed and perform action.
                switch(event.key.code)
                {
                    case sf::Keyboard::W:
                      cout << "W Pressed." << endl;
                      player1->moveSprite(0,-16);
                    break;
                    case sf::Keyboard::A:
                      cout << "A Pressed." << endl;
                      player1->moveSprite(-16,0);
                    break;
                    case sf::Keyboard::S:
                      cout << "S Pressed." << endl;
                      player1->moveSprite(0,16);
                    break;
                    case sf::Keyboard::D:
                      cout << "D Pressed." << endl;
                      player1->moveSprite(16,0);
                    break;
                }
            }
        }
        //view.move(0, 1);
        // activate it
        window.setView(view);
        window.clear(); //sf::Color(200, 0, 0)
        level->draw(window);
        player1->draw(window);
        //window.draw();
        window.display();
    }

    return 0;
}
