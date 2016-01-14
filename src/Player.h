#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

class Player
{
public:
  Player(string fileName);
  void loadSprite(string fileName);
  void update();
  void moveSprite(int, int);
  void draw(sf::RenderWindow &window);
  string m_spriteSheet; // = "Images/hero.png";
  static const int m_tileSize = 16;
private:
  int m_health;

  sf::Texture m_texture;
  sf::Sprite m_sprite;

};
#endif //PLAYER_H
