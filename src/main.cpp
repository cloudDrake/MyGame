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
    //TODO: Determine proper speed for player1.
    int playerSpeed = 4;
    // let's define the views.
    sf::View view(sf::FloatRect(0, 0, Tile::m_tileSize*120, Tile::m_tileSize*120));
    view.zoom(0.1f);
    //sf::View view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    sf::View minimap(sf::FloatRect(0, 0, Tile::m_tileSize*12, Tile::m_tileSize*12));
    //view.move(dx, dy) to move the view.

    //set the viewports for the views.
    view.setViewport(sf::FloatRect(0.0f, 0.0f, 1, 1));
    minimap.setViewport(sf::FloatRect(0.75f, 0.75f, 0.25f, 0.25f));

    //Main game loop
    while (window.isOpen())
    {
        sf::Event event;
        //event loop, keybindings.
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                || (event.type == sf::Event::KeyPressed
                    && event.key.code == sf::Keyboard::Escape))
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
                      //TODO: Check boundary
                      player1->moveSprite(0,-playerSpeed);
                    break;
                    case sf::Keyboard::A:
                      cout << "A Pressed." << endl;
                      //TODO: Check boundary
                      player1->moveSprite(-playerSpeed,0);
                    break;
                    case sf::Keyboard::S:
                      cout << "S Pressed." << endl;
                      //TODO: Check boundary
                      player1->moveSprite(0,playerSpeed);
                    break;
                    case sf::Keyboard::D:
                      cout << "D Pressed." << endl;
                      //TODO: Check boundary
                      player1->moveSprite(playerSpeed,0);
                    break;
                }
            }
            else
            if (event.type == sf::Event::MouseButtonPressed) {
              //TODO: Add mouse events.
              switch(event.mouseButton.button)
              {
                case sf::Mouse::Left:
                  cout << "Left Mouse X: " << event.mouseButton.x << endl;
                  cout << "Left Mouse Y: " << event.mouseButton.y << endl;
                break;
                case sf::Mouse::Right:
                  cout << "Right Mouse X: " << event.mouseButton.x << endl;
                  cout << "Right Mouse Y: " << event.mouseButton.y << endl;
                break;
              }
            }
        }
        //view.move(0, 1);

        //Keep view centered on the player.
        //Handle view movement for X axis.
        int newViewCenterX = player1->getSprite().getPosition().x;
        int newViewCenterY = player1->getSprite().getPosition().y;

        if(newViewCenterX < (view.getSize().x/2))
          newViewCenterX = view.getSize().x/2;
        else
        if (newViewCenterX > (window.getSize().x - view.getSize().x/2))
        {
          newViewCenterX = window.getSize().x - view.getSize().x/2;
        }

        //Handle view movement for Y axis.
        if(newViewCenterY < (view.getSize().y/2))
          newViewCenterY = view.getSize().y/2;
        else
        if (newViewCenterY > (window.getSize().y - view.getSize().y/2))
        {
          newViewCenterY = window.getSize().y - view.getSize().y/2;
        }

        //Set the view centered on the player.
        view.setCenter(newViewCenterX, newViewCenterY);

        // activate the game view.
        window.setView(view);

        window.clear(); //sf::Color(200, 0, 0)

        //Draw to the game view.
        level->draw(window);
        player1->draw(window);

        //Draw to minimap
        window.setView(minimap);
        level->draw(window);
        player1->draw(window);
        //window.draw();
        window.display();
    }

    return 0;
}
