#include "Sudoku.h"

Sudoku::Sudoku(int N)
{
    this->N = N;
    menu();
}
Sudoku::~Sudoku()
{
}

void Sudoku::menu()
{
    int choice;
    while (true)
    {
        clearSystem();
        cout << printColor("=========================================", 37);
        cout << setw(35) << right << printColor("Sudoku", 36);
        cout << printColor("=========================================", 37);
        cout << endl;
        cout << printColor("[1] START GAME", 32);
        cout << printColor("[2] INSTRUCTIONS", 33);
        cout << printColor("[3] EXIT", 31);
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

    // CONDITION LEVEL
    if (setLevel == '4')
    {
        // GO TO MENU
        menu();
    }
    else
    {
        // GAME START
        level = (int)setLevel - 48; // Initialize Level\

        // Random level
        int randNomal = rand() % 4 + 35;
        int randMedium = rand() % 4 + 40;
        int randHard = rand() % 4 + 45;
        if (level == 1)
        {
            this->K = randNomal;
        }
        else if (level == 2)
        {
            this->K = randMedium;
        }
        else if (level == 3)
        {
            this->K = randHard;
        }

        status = "playing"; // SET STATUS
        pointerX = 0;       // RESET POINTER
        pointerY = 0;       // RESET POINTER
        mainGame();
    }

    // PAUSE
    getch();

    // // GO TO MAIN MENU
    // menu();
}

void Sudoku::helpSudoku(string located)
{
    clearSystem();
    cout << printColor("=========================================", 37);
    cout << setw(35) << right << printColor("Sudoku", 36);
    cout << printColor("=========================================", 37);
    cout << endl;
    cout << setw(38) << right << printColor("INSTRUCTIONS", 33);

    cout << printColor("  * The sudoku puzzle is consist of", 34);
    cout << printColor("  a 9x9 grid, you have to fill", 34);
    cout << printColor("  the empty squares using the", 34);
    cout << printColor("  numbers 1 to 9.", 34);
    cout << printColor("  * Use the 1-9 keys in your", 34);
    cout << printColor("  keybord to fill the sudoku", 34);
    cout << printColor("  puzzle.", 34);
    cout << printColor("  * To move arround the sudoku", 34);
    cout << printColor("  puzzle, use the WASD letter", 34);
    cout << printColor("  keys or the arrow keys. ", 34);
    cout << printColor("  * Use backspace or delete key to", 34);
    cout << printColor("  clear the number selected in", 34);
    cout << printColor("  the sudoku puzzle.", 34);
    cout << printColor("  * Once you finish the sudoku", 34);
    cout << printColor("  puzzle, it will prompt you that", 34);
    cout << printColor("  you finished it if not you can", 34);
    cout << printColor("  press P then you can choose", 34);
    cout << printColor("  \"Quit\" in the pause menu", 34);
    cout << printColor("  if your having a hard time.", 34);
    cout << endl;
    cout << printColor("(Press any key to go back!) ", 35);

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
    cout << printColor("=========================================", 37);
    cout << setw(10) << right << "" << printColor("DO YOU WANT TO EXIT?", 31);
    cout << printColor("[1] YES", 32);
    cout << printColor("[2] NO", 33);
    cout << printColor("=========================================", 37);

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
        cout << printColor("=========================================", 37);
        cout << setw(35) << right << printColor("Sudoku", 36);
        cout << printColor("=========================================", 37);

        cout << setw(10) << right << "" << printColor("SELECT A DIFFICULTY", 34);
        cout << printColor("[1] EASY", 32);
        cout << printColor("[2] MEDIUM", 33);
        cout << printColor("[3] HARD", 35);
        cout << printColor("[4] BACK", 37); // BACK TO MENU
        cout << endl;
        cout << printColor(" Press the number of your choice! ", 37);

        // GET USER CHOICE
        char select = getch();
        if (!(select < '1' || select > '4'))
        {
            choice = select;
            break;
        }
    } while (true);

    return choice;
}
void Sudoku::createGrid()
{
    grid = new Square *[N];
    // Create a row for every pointer
    for (int i = 0; i < N; i++)
    {

        // Note : Rows may not be contiguous
        grid[i] = new Square[N];

        // Initialize all entries as false to indicate
        // that there are no edges initially
    }
}
// Fill the diagonal of SRN x SRN matrices
void Sudoku::fillDiagonal()
{
}
// Fill remaining blocks
void Sudoku::fillRemaining()
{
}
// Remove Randomly K digits to make game
void Sudoku::removeKDigits()
{
}

void Sudoku::mainGame()
{
    // get time for random
    srand(time(0));

    char key;
    clearSystem();
    bool check = true;
    cout << printColor("=========================================", 37);
    cout << setw(35) << right << printColor("Sudoku", 36);
    cout << printColor("=========================================", 37);

    key = getch();
    if (key == 'p')
    {
        check = false;
        exit(0);
    }
    else
    {
        mainGame();
    }
}

void Sudoku::printGrid()
{
}