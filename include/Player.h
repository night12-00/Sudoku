#pragma once
#include "include.h"
#include "ListPlayer.h"

class Player
{
private:
    string name;
    int score;
    friend class ListPlayer;
    friend class Sudoku;

public:
    Player();
    Player(string name, double timePlay);
    Player(string name, int score);
    ~Player();
    void setPlayer(string name, int score);
    Player getPlayer();
    Player &operator=(const Player &player);
    bool operator==(const Player &player);
    bool operator!=(const Player &player);
};