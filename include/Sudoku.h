#pragma once
#include "include.h"
#include "Square.h"

class Sudoku
{
private:
    int N;                  // 9x9
    int K;                  // Number hiden
    Square **grid;          // grid square
    int level = 1;          // Default level Game
    int pointerX = 0;       // Default pointer X = 0;
    int pointerY = 0;       // Default pointer Y = 0;
    int solutionGrid[9][9]; // grid Solution
    int highLights[9][9];   // arr for highligh

protected:
public:
    Sudoku();
    Sudoku(int N);
    ~Sudoku();
    void menu();
    void gotoMenu(char choice);
    void playSudoku();
    void helpSudoku(string located);
    void exitMenu();
    char gameLevel();
    void createGrid();

    // Check
    bool unUsedInBox(int rowStart, int colStart, int num);
    bool unUsedInRow(int row, int num);
    bool unUsedInCol(int col, int num);
    // Check if safe to put in cell
    bool CheckIfSafe(int row, int col, int num);
    // Fill
    void fillDiagonal();                  // Fill the diagonal of SRN x SRN matrices
    void fillBox(int row, int col);       // Fill Box
    bool fillRemaining(int row, int col); // Fill remaining blocks
    void removeKDigits();                 // Remove Randomly K digits to make game
    void mainGame(int value);
    void printSudoku(int num, bool isResult);

    // Keyboard
    void upKey();
    void downKey();
    void leftKey();
    void rightKey();
    void escKey();
    void pauseKey();
    void backSpaceKey();
};