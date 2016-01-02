#include "Tile.h"

Tile::Tile(string tileNum, int hPos, int wPos)
{
  cout << tileNum << " ";
  int rowCol = atoi(tileNum.c_str());
  if (!m_texture.loadFromFile(m_spritesheet))
  {
      // error...
      cout << "Could not load: " << tileNum << endl;
  }

  m_sprite.setTexture(m_texture);
  m_sprite.setTextureRect(sf::IntRect(1,1,16,16));
  m_sprite.setPosition(wPos, hPos);
}

void Tile::draw(sf::RenderWindow & window)
{
  window.draw(m_sprite);
}
void Tile::loadSprite()
{

}
