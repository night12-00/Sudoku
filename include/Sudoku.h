#pragma once
#include "include.h"
#include "Square.h"

class Sudoku
{
private:
    int N;               // 9x9
    int K;               // Number hiden
    int level = 1;       // Default level Game
    Square **grid;       // grid square
    int pointerX = 0;    // Default pointer X = 0;
    int pointerY = 0;    // Default pointer Y = 0;
    string status;       // Checking status: playing, pause
    string **solution;   // grid Solution
    string **highLights; // arr for highligh

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
    void fillDiagonal();  // Fill the diagonal of SRN x SRN matrices
    void fillRemaining(); // Fill remaining blocks
    void removeKDigits(); // Remove Randomly K digits to make game
    void generalSudokuPuzzle();
    void mainGame();
    void printGrid();
};