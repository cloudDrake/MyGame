#include "Player.h"

Player::Player(string fileName)
{
  m_health = 100;
  m_spriteSheet = fileName;
  if (m_texture.loadFromFile(m_spriteSheet))
  {
    m_sprite.setTexture(m_texture);
    int spriteXPos = 0; //m_tileSize + tileRow + 1;
    int spriteYPos = 0; //tileCol * m_tileSize + tileCol + 1;
    m_sprite.setTextureRect(sf::IntRect(spriteYPos, spriteXPos, m_tileSize, m_tileSize));
    m_sprite.setPosition(16, 16);
  }
}

void Player::draw(sf::RenderWindow &window)
{
  window.draw(m_sprite);
}

void Player::moveSprite(int deltaX, int deltaY)
{
  m_sprite.move(deltaX, deltaY);
}

const sf::Sprite& Player::getSprite() const
{
  return m_sprite;
}

void Player::update()
{

}
