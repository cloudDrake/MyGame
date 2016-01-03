#include "Tile.h"

Tile::Tile(int tileRow, int tileCol, int hPos, int wPos)
{
  //cout << tileNum << " ";

  //cout << row << " " << col << endl;
  if (m_texture.loadFromFile(m_spritesheet))
  {
    m_sprite.setTexture(m_texture);
    int spriteXPos = tileRow * m_tileSize + tileRow + 1;
    int spriteYPos = tileCol * m_tileSize + tileCol + 1;
    m_sprite.setTextureRect(sf::IntRect(spriteYPos, spriteXPos, m_tileSize, m_tileSize));
    m_sprite.setPosition(wPos, hPos);
  }

}

void Tile::draw(sf::RenderWindow & window)
{
  window.draw(m_sprite);
}
void Tile::loadSprite()
{

}
