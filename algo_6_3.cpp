#include <iostream>
#include <string>
using namespace std;

bool inRange(int, int);

const char board[5][5] = {{ 'N', 'N', 'N', 'N', 'S'},
                        { 'N', 'E', 'E', 'E', 'N'},
                        { 'N', 'E', 'Y', 'E', 'N'},
                        { 'N', 'E', 'E', 'E', 'N'},
                        { 'N', 'N', 'N', 'N', 'N'}};

const int dx[8] = {-1, -1, -1,  1, 1, 1,  0, 0};
const int dy[8] = {-1,  0,  1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string& word)
{
  if(!inRange(y, x)) { return false; }

  if(board[y][x] != word[0]) { return false; }

  if(word.size() == 1) { return true; }

  for(int direction = 0; direction < 8; ++direction) {
    int nextY = y + dy[direction];
    int nextX = x + dx[direction];
    if(hasWord(nextY, nextX, word.substr(1))) {
      return true;
    }
  }

  return false;
}