#include "Board.h"

Board::Board()
{

}

void Board::draw(sf::RenderWindow & window)
{
  for(int i = 0; i < m_levelRows; i++)
  {
    for(int j = 0; j < m_levelCols; j++)
    {
      m_board[i][j]->draw(window);
      //window.draw(m_board[i][j]->m_sprite);
    }
  }
}

void Board::update()
{

}

vector<string> Board::splitStr(string str, char delim)
{
  vector<string> tokens;
  string curToken = "";
  for(int i = 0; i < str.size(); i++)
  {
    if(str.at(i) == delim)
    {
      tokens.push_back(curToken);
      curToken = "";
    }
    else
    {
      curToken += str.at(i);
    }
  }
  tokens.push_back(curToken);
  return tokens;
}

Tile * Board::findTile(string fileName, int hPos, int wPos)
{
  vector<string> tokens = splitStr(fileName, '-');
  Tile * tile;
  if(tokens[0] == "Grass")
    return new Tile(fileName, hPos, wPos);
  else
    return new Tile("Black.png", hPos, wPos);

}

void Board::loadLevel(string fileName)
{
  string line;
  vector<string> tokens;
  ifstream levelFile(fileName.c_str());
  if(levelFile.is_open())
  {
    //Get Board Dimensions
    getline(levelFile, line);
    tokens = splitStr(line, ' ');

    //Reserve Board size
    m_levelRows = atoi(tokens.at(0).c_str());
    m_levelCols = atoi(tokens.at(1).c_str());
    m_board.resize(m_levelCols, vector<Tile*>(m_levelRows, NULL));

    //Now fill the Board with the files Tiles
    for(int i = 0; i < m_levelRows; i++)
    {
      getline(levelFile, line);
      tokens.clear();
      tokens = splitStr(line, ' ');
      if(tokens.size() != m_levelCols)
      {
        cout << "ERROR COLS DOESN'T MATCH FILE!" << endl;
        return;
      }
      for(int j = 0; j < m_levelCols; j++)
      {
        //i * 16/j* 16 cuz each tile is 16pixels
        //m_board[i][j] =  findTile(tokens.at(i), i * 16, j * 16);
        m_board[i][j] = new Tile(tokens.at(i), i*16, j*16);
        cout << tokens.at(i) << "rowPos: " << i*16 + 1 << " col " << j * 16 + 1 << endl;
      }
    }

    levelFile.close();
  }
}
