#include "Sudoku.h"

Sudoku::Sudoku(int N)
{
    this->N = N;
    menu();
}
Sudoku::~Sudoku()
{
    for (int i = 0; i < N; i++)
    {
        delete[] grid[i];
        delete[] solutionGrid[i];
        delete[] highLights[i];
    }

    delete[] grid;
    delete[] solutionGrid;
    delete[] highLights;
}

void Sudoku::menu()
{
    int choice;
    while (true)
    {
        clearSystem();
        cout << printColor("=========================================", 37) << endl;
        cout << setw(35) << right << printColor("SUDOKU", 36) << endl;
        cout << printColor("=========================================", 37) << endl;
        cout << endl;
        cout << printColor("[1] START GAME", 32) << endl;
        cout << printColor("[2] INSTRUCTIONS", 33) << endl;
        cout << printColor("[3] EXIT", 31) << endl;
        cout << endl;
        char select = getch();
        if (!(select < '1' || select > '3'))
        {
            choice = select;
            break;
        }
    }
    gotoMenu(choice);
}
void Sudoku::gotoMenu(char choice)
{
    if (choice == '1')
    {
        playSudoku(); // GO TO PLAY MENU
    }
    else if (choice == '2')
    {
        helpSudoku("main"); // GO TO INSTRUCTIONS MENU
    }

    else if (choice == '3')
    {
        exitMenu(); // GO TO EXIT MENU
    }
}
// PLAY SUDOKU
void Sudoku::playSudoku()
{
    // GAME LEVEL
    char setLevel = gameLevel();
    incorrect = 5;
    // CONDITION LEVEL
    if (setLevel == '4')
    {
        // GO TO MENU
        menu();
    }
    else
    {
        // GAME START
        level = (int)setLevel - 48; // Initialize Level

        // Random level

        if (level == 1)
        {
            this->K = 35;
        }
        else if (level == 2)
        {
            this->K = 40;
        }
        else if (level == 3)
        {
            this->K = 45;
        }

        pointerX = 0; // RESET POINTER
        pointerY = 0; // RESET POINTER

        createGrid();

        mainGame(0);
    }

    // PAUSE
    getch();

    // // GO TO MAIN MENU
    // menu();
}

void Sudoku::helpSudoku(string located)
{
    clearSystem();
    cout << printColor("=========================================", 37) << endl;
    cout << setw(35) << right << printColor("SUDOKU", 36) << endl;
    cout << printColor("=========================================", 37) << endl;
    cout << endl;
    cout << setw(38) << right << printColor("INSTRUCTIONS", 33) << endl;

    cout << printColor("  * The sudoku puzzle is consist of", 34) << endl;
    cout << printColor("  a 9x9 grid, you have to fill", 34) << endl;
    cout << printColor("  the empty squares using the", 34) << endl;
    cout << printColor("  numbers 1 to 9.", 34) << endl;
    cout << printColor("  * Use the 1-9 keys in your", 34) << endl;
    cout << printColor("  keybord to fill the sudoku", 34) << endl;
    cout << printColor("  puzzle.", 34) << endl;
    cout << printColor("  * To move arround the sudoku", 34) << endl;
    cout << printColor("  puzzle, use the WASD letter", 34) << endl;
    cout << printColor("  keys or the arrow keys. ", 34) << endl;
    cout << printColor("  * Use backspace or delete key to", 34) << endl;
    cout << printColor("  clear the number selected in", 34) << endl;
    cout << printColor("  the sudoku puzzle.", 34) << endl;
    cout << printColor("  * Once you finish the sudoku", 34) << endl;
    cout << printColor("  puzzle, it will prompt you that", 34) << endl;
    cout << printColor("  you finished it if not you can", 34) << endl;
    cout << printColor("  press P then you can choose", 34) << endl;
    cout << printColor("  \"Quit\" in the pause menu", 34) << endl;
    cout << printColor("  if your having a hard time.", 34) << endl;
    cout << endl;
    cout << printColor("(Press any key to go back!) ", 35) << endl;

    // PAUSE
    getch();
    // GO TO MAIN MENU
    if (located == "main")
    {
        menu();
    }
};
// EXIT SUDOKU
void Sudoku::exitMenu()
{
    clearSystem();
    cout << printColor("=========================================", 37) << endl;
    cout << setw(10) << right << "" << printColor("DO YOU WANT TO EXIT?", 31) << endl;
    cout << printColor("[1] YES", 32) << endl;
    cout << printColor("[2] NO", 33) << endl;
    cout << printColor("=========================================", 37) << endl;

    while (true)
    {
        char select = getch();
        if ((select == '1' || select == '2'))
        {
            cout << endl;
            if (select == '1')
            {
                exit(0);
            }
            else
            {
                menu();
            }
        }
    }
}

// SELECT LEVEL GAME
char Sudoku::gameLevel()
{
    char choice;

    // DISPLAY
    do
    {
        clearSystem();
        cout << printColor("=========================================", 37) << endl;
        cout << setw(35) << right << printColor("SUDOKU", 36) << endl;
        cout << printColor("=========================================", 37) << endl;

        cout << setw(10) << right << "" << printColor("SELECT A DIFFICULTY", 34) << endl;
        cout << printColor("[1] EASY", 32) << endl;
        cout << printColor("[2] MEDIUM", 33) << endl;
        cout << printColor("[3] HARD", 31) << endl;
        cout << printColor("[4] BACK", 35) << endl; // BACK TO MENU
        cout << endl;
        cout << printColor(" Press the number of your choice! ", 37) << endl;

        // GET USER CHOICE
        char select = getch();
        if (!(select < '1' || select > '4'))
        {
            choice = select;
            break;
        }
        else if ((int)select == 27)
        {
            choice = '4';
            break;
        }
    } while (true);

    return choice;
}
void Sudoku::createGrid()
{
    int sqrtN = sqrt(N);
    grid = new Square *[N];
    solutionGrid = new Square *[N];
    highLights = new Square *[N];
    // Create a row for every pointer
    for (int i = 0; i < N; i++)
    {

        // Note : Rows may not be contiguous
        grid[i] = new Square[N];
        solutionGrid[i] = new Square[N];
        highLights[i] = new Square[N];

        // Initialize all entries as false to indicate
        // that there are no edges initially
    }

    // Create 3 box on grid
    fillDiagonal();

    // Fill remaining grid with solveSudoku;
    solveSudoku(0, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            solutionGrid[i][j] = grid[i][j];
        }
    }
    // Remove K number
    removeKDigits();

    // Copy grid to solutionGrid and init color on highlights
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] != 0)
            {
                // default white color
                highLights[i][j] = 37;
            }
            else
            {
                highLights[i][j] = 30;
            }
        }
    }
}

// Check value
bool Sudoku::unUsedInBox(int rowStart, int colStart, int num)
{
    int sqrtN = sqrt(N);
    for (int i = 0; i < sqrtN; i++)
    {
        for (int j = 0; j < sqrtN; j++)
        {
            if (grid[rowStart + i][colStart + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool Sudoku::unUsedInRow(int row, int num)
{
    for (int j = 0; j < N; j++)
    {

        if (grid[row][j] == num)
        {
            return false;
        }
    }
    return true;
}
// check in the row for existence
bool Sudoku::unUsedInCol(int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }
    return true;
}
bool Sudoku::CheckIfSafe(int row, int col, int num)
{
    int sqrtN = sqrt(N);
    return (
        unUsedInRow(row, num) && unUsedInCol(col, num) && unUsedInBox(row - row % sqrtN, col - col % sqrtN, num));
}

// Fill the diagonal of SRN x SRN matrices
void Sudoku::fillDiagonal()
{
    int sqrtN = sqrt(N);

    for (int i = 0; i < N; i = i + sqrtN)
    {

        // for diagonal box, start coordinates->i==j
        fillBox(i, i);
    }
}
void Sudoku::fillBox(int row, int col)
{
    int sqrtN = sqrt(N);
    int num;
    for (int i = 0; i < sqrtN; i++)
    {
        for (int j = 0; j < sqrtN; j++)
        {
            do
            {
                num = RandomNumber(N);
            } while (!unUsedInBox(row, col, num));
            grid[row + i][col + j] = num;
        }
    }
}

// Fill remaining blocks
bool Sudoku::solveSudoku(int row, int col)
{
    int SRN = (int)sqrt(N);

    if (col >= N && row < N - 1)
    {
        row = row + 1;
        col = 0;
    }
    if (row >= N && col >= N)
    {
        return true;
    }
    if (row < SRN)
    {
        if (col < SRN)
        {
            col = SRN;
        }
    }
    else if (row < N - SRN)
    {
        if (col == (int)(row / SRN) * SRN)
        {
            col = col + SRN;
        }
    }
    else
    {
        if (col == N - SRN)
        {
            row = row + 1;
            col = 0;
            if (row >= N)
            {
                return true;
            }
        }
    }
    for (int num = 1; num <= N; num++)
    {
        if (CheckIfSafe(row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(row, col + 1))
            {
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}

// Remove Randomly K digits to make game
void Sudoku::removeKDigits()
{
    int count = K;
    while (count != 0)
    {
        int cellId = RandomNumber(N * N) - 1;
        // System.out.println(cellId);
        // extract coordinates i and j
        int i = (cellId / N);
        int j = cellId % 9 + 1;
        if (j != 0)
        {
            j = j - 1;
        }
        // System.out.println(i+" "+j);
        if (grid[i][j] != 0)
        {
            count--;
            grid[i][j] = 0;
        }
    }
}

bool Sudoku::getCorrect()
{
    correct = 0;
    // Kiểm tra tất cả các ô có giá trị khác 0 (tức là đã được điền đầy đủ)
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == solutionGrid[row][col])
            {
                ++correct;
            }
        }
    }

    return true;
}

void Sudoku::mainGame(int value)
{

    clearSystem();
    cout << printColor("=========================================", 37) << endl;
    cout << setw(35) << right << printColor("SUDOKU", 36) << endl;
    cout << printColor("=========================================", 37) << endl;
    cout << endl;

    if (value > 0 && value < 10)
    {
        grid[pointerX][pointerY] = value;
    }

    if (value != 0 && solutionGrid[pointerX][pointerY] == value)
    {
        highLights[pointerX][pointerY] = 32;
    }
    if (value != 0 && solutionGrid[pointerX][pointerY] != value)
    {
        --incorrect;
        if (incorrect > 0)
        {
            cout << setw(4) << "" << printColor("CAREFULL!!! You have " + to_string(incorrect) + " mistakes left", 31);
        }
        highLights[pointerX][pointerY] = 31;
    }

    getCorrect();
    if (incorrect <= 0)
    {
        cout << setw(15) << "" << printColor("YOU LOSE !!!", 31);
    }
    if (correct == N * N)
    {
        cout << setw(15) << "" << printColor("YOU WIN !!!", 32);
    }
    printSudoku(value, solutionGrid[pointerX][pointerY] == value);

    while (true)
    {
        int firstKey = getch();
        if (PLATFORM_NAME == "windows")
        {

            int key = firstKey;

            if (key == 112 || key == 27)
            {
                pauseKey();
            }
            else
            {
                if (incorrect > 0 && correct < N * N)
                {
                    // Get 1 - > 233
                    if (!(key <= 0 || key >= 224))
                    {

                        if (key == 8 || key == 83)
                        {
                            if (grid[pointerX][pointerY] !=
                                solutionGrid[pointerX][pointerY])
                            {
                                backSpaceKey();
                                mainGame(0);
                            }
                        }
                        else if (key == 75 || key == 68 || key == 97)
                        {
                            leftKey();
                            mainGame(0);
                        }
                        else if (key == 72 || key == 65 || key == 119)
                        {
                            upKey();
                            mainGame(0);
                        }
                        else if (key == 80 || key == 66 || key == 115)
                        {
                            downKey();
                            mainGame(0);
                        }
                        else if (key == 77 || key == 67 || key == 100)
                        {
                            rightKey();
                            mainGame(0);
                        }
                        else if (grid[pointerX][pointerY] !=
                                     solutionGrid[pointerX][pointerY] &&
                                 key - 48 > 0 && key - 48 < 10)
                        {
                            getCorrect();
                            mainGame(key - 48);
                        }
                    }
                }
            }
        }
        else
        {
            int key = firstKey;
            int second;
            if (firstKey == 27)
            {
                second = getch();
                if (second == 91)
                {
                    key = getch();
                }
                else
                {
                    key = firstKey;
                    if (key == 27)
                    {
                        pauseKey();
                    }
                }
            }
            if (key == 112)
            {
                pauseKey();
            }
            else
            {
                if (incorrect > 0 && correct < N * N)
                {
                    // Get 1 - > 233
                    if (!(key <= 0 || key >= 224))
                    {

                        if (key == 8 || key == 83)
                        {
                            if (grid[pointerX][pointerY] !=
                                solutionGrid[pointerX][pointerY])
                            {
                                backSpaceKey();
                                mainGame(0);
                            }
                        }
                        else if (key == 75 || key == 68 || key == 97)
                        {
                            leftKey();
                            mainGame(0);
                        }
                        else if (key == 72 || key == 65 || key == 119)
                        {
                            upKey();
                            mainGame(0);
                        }
                        else if (key == 80 || key == 66 || key == 115)
                        {
                            downKey();
                            mainGame(0);
                        }
                        else if (key == 77 || key == 67 || key == 100)
                        {
                            rightKey();
                            mainGame(0);
                        }
                        else if (grid[pointerX][pointerY] !=
                                     solutionGrid[pointerX][pointerY] &&
                                 key - 48 > 0 && key - 48 < 10)
                        {
                            getCorrect();
                            mainGame(key - 48);
                        }
                    }
                }
            }
        }
    }
}

void Sudoku::printSudoku(int num, bool isResult)
{
    int colorBorder = 35;
    int colorValueDefault = 37;
    int colorFalse = 31;
    int colorTrue = 32;
    int colorFocus = 34;
    finalProgress = round(((double(correct) / 81.0) * 100.0));

    cout << endl;
    cout << endl;
    cout << printColor("=========================================", colorBorder) << endl;

    for (int i = 0; i < N; i++)
    {
        int h = i + 1;
        for (int j = 0; j < N; j++)
        {
            int k = j + 1;

            string value = to_string(grid[i][j].getValue());

            if (grid[i][j] == 0)
            {
                value = " ";
                if (pointerX == i && pointerY == j && grid[pointerX][pointerY] == 0)
                {
                    value = "x";
                    highLights[i][j] = colorFocus;
                }

                if (num != 0 && pointerX == i && pointerY == j)
                {
                    value = to_string(num);
                    isResult ? highLights[i][j] = colorTrue : highLights[i][j] = colorFalse;
                }
            }
            else
            {
                if (pointerX == i && pointerY == j && grid[pointerX][pointerY] != 0)
                {
                    value = to_string(grid[pointerX][pointerY].getValue());
                    if (highLights[i][j] != 32 && highLights[i][j] != 31)
                    {
                        highLights[i][j] = colorFocus;
                    }
                }
                else if (highLights[i][j] != 32 && highLights[i][j] != 31)
                {
                    highLights[i][j] = colorValueDefault;
                }
            }

            if (j == 0)
            {

                cout << printColor("|| ", colorBorder) << printColor(value, highLights[i][j].getValue()) << printColor(" |", colorBorder);
                continue;
            }
            else if (j == 8)
            {
                cout
                    << " " << printColor(value, highLights[i][j].getValue()) << printColor(" ||", colorBorder);
            }
            else if (j == 2 || j == 5)
            {
                cout << " " << printColor(value, highLights[i][j].getValue()) << printColor(" ||", colorBorder);
            }
            else
            {
                cout << " " << printColor(value, highLights[i][j].getValue()) << printColor(" |", colorBorder);
            }
        }
        if (h % 3 == 0)
        {
            cout << endl;
            cout << printColor("=========================================", colorBorder) << endl;
        }
        else
        {
            cout << endl;
        }
    }
    cout << endl;
    cout << endl;
    cout << setw(2) << "" << printColor("Mistakes: ", 36) << (5 - incorrect) << "/5" << endl;
    cout << setw(2) << "" << printColor("Progress: ", 33) << finalProgress << "%" << endl;
    showProgressHardMode(finalProgress);
    cout << endl
         << endl;
    if (incorrect > 0)
    {
        cout << setw(2) << "" << printColor("Press [ESC] or [P] to pause the game", 31) << endl;
    }
    else if (incorrect <= 0 || correct == N * N)
    {
        cout << setw(2) << "" << printColor("Press [ESC] or [P] to go menu", 31) << endl;
    }
}

void Sudoku::showProgressHardMode(double finalProgress)
{
    if (finalProgress >= 69)
    {
        if (finalProgress >= 84)
        {
            if (finalProgress >= 94)
            {
                cout << setw(2) << ""
                     << "Just a little bit!";
            }
            else
            {
                cout << setw(2) << ""
                     << "Almost there!";
            }
        }
        else
        {
            cout << setw(2) << ""
                 << "Half-way there!";
        }
    }

    else
    {
        cout << setw(2) << ""
             << "Unfinshed";
    }
}

// KEYBOARD

void Sudoku::upKey()
{
    if (pointerX == 0)
    {
        pointerX = 8;
    }
    else
    {
        pointerX--;
    }
}
void Sudoku::downKey()
{
    if (pointerX == 8)
    {
        pointerX = 0;
    }
    else
    {
        pointerX++;
    }
}
void Sudoku::leftKey()
{
    if (pointerY == 0)
    {
        pointerY = 8;
    }
    else
    {
        pointerY--;
    }
}
void Sudoku::rightKey()
{
    if (pointerY == 8)
    {
        pointerY = 0;
    }
    else
    {
        pointerY++;
    }
}
void Sudoku::pauseKey()
{
    clearSystem();
    cout << printColor("=========================================", 37) << endl;
    cout << setw(10) << right << "" << printColor("PAUSE GAME", 33) << endl;
    if (incorrect > 0)
    {
        cout << printColor("[1] RESUME", 32) << endl;
    }
    else if (incorrect <= 0 || correct == N * N)
    {
        cout << printColor("[1] NEW GAME", 32) << endl;
    }

    cout << printColor("[2] EXIT TO MENU", 33) << endl;
    cout << printColor("=========================================", 37) << endl;

    while (true)
    {
        char select = getch();
        if ((select == '1' || select == '2' || select == 'p' || (int)select == 27))
        {
            cout << endl;
            if (select == '2')
            {
                menu();
            }
            else
            {
                if (incorrect > 0)
                {
                    if (select == '1' || select == 'p' || (int)select == 27)
                    {
                        mainGame(0);
                    }
                }
                else
                {
                    if (select == '1')
                    {
                        playSudoku();
                    }
                    else if (select == 'p' || (int)select == 27)
                    {
                        mainGame(0);
                    }
                }
            }
        }
    }
}

void Sudoku::backSpaceKey()
{
    grid[pointerX][pointerY] = 0;
}
