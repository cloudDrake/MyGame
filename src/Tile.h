#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

using namespace std;

const string m_spritesheet = "./Images/overworldtiles.png";

class Tile
{
public:
  Tile(string fileName, int hPos, int wPos);
  void draw(sf::RenderWindow & window);
  void loadSprite();

private:
  bool m_isCollidable;
  sf::Texture m_texture;
  sf::Sprite m_sprite;
};
#endif /*TILE_H*/
