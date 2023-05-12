#include "include.h"
#include "Sudoku.h"

int main()
{
  // get time for random
  srand(time(0));
  Sudoku *init = new Sudoku(9);
  delete[] init;
  return 0;
}
