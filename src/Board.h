#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

#include "../lib/tinyxml/tinyxml.h"
#include "Tile.h"

using namespace std;



class Board
{
public:
  Board();
  void draw(sf::RenderWindow & window);
  void update();
  void loadLevel(string fileName, bool isXML);
  void loadLevel(string fileName);
private:
  vector<string> splitStr(string str, char delim);
  vector< vector<Tile*> > m_board;
  Tile * findTile(string fileName, int curRow, int curCol);
  int m_levelRows;
  int m_levelCols;
};
#endif
