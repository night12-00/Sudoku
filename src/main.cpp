#include "include.h"
#include "Sudoku.h"
#include "ListPlayer.h"
#include "Player.h"

int main()
{

  srand(time(0));

  int length = 1;
  string name;
  int score = 0;
  fstream file;
  Player *players;

  file.open("src/Ranking.txt", ios::out | ios::in);

  file >> length;
  cout << length;
  players = new Player[length];
  for (int i = 0; i < length; i++)
  {

    file >> name;
    file >> score;
    Player player(name, score);
    players[i] = player;
  }

  ListPlayer *listPlayer = new ListPlayer(players, length);

  Sudoku *initSudoku = new Sudoku(9, listPlayer);

  return 0;
}
