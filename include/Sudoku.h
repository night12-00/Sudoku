#pragma once
#include "include.h"
#include "Square.h"

class Sudoku
{
private:
    int N;         // 9x9
    int K;         // Number hiden
    Square **grid; // grid square

    double finalProgress = 0;
    int incorrect = 5;
    int correct = 0;
    int level = 1;         // Default level Game
    int pointerX = 0;      // Default pointer X = 0;
    int pointerY = 0;      // Default pointer Y = 0;
    Square **solutionGrid; // grid Solution
    Square **highLights;   // arr for highligh

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
    void fillDiagonal();                // Fill the diagonal of SRN x SRN matrices
    void fillBox(int row, int col);     // Fill Box
    bool solveSudoku(int row, int col); // Fill remaining blocks
    void removeKDigits();               // Remove Randomly K digits to make game
    bool getCorrect();
    void mainGame(int value);
    void printSudoku(int num, bool isResult);
    void showProgressHardMode(double finalProgress);

    // Keyboard
    void upKey();
    void downKey();
    void leftKey();
    void rightKey();
    void escKey();
    void pauseKey();
    void backSpaceKey();
};