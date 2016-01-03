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
    return new Tile(0, 0, hPos, wPos);
  else
    return new Tile(0, 0, hPos, wPos);

}
void Board::loadLevel(string fileName, bool isXML)
{

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
        int rowCol = atoi(tokens.at(j).c_str());
        m_board[i][j] = new Tile(rowCol / 10, rowCol % 10, i * m_tileSize, j * m_tileSize);
      }
    }

    levelFile.close();
  }
}
