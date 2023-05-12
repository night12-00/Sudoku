#pragma once
#include "Player.h"
#include "Sudoku.h"
#include "include.h"

class Player;

class ListPlayer
{
private:
    Player *players;
    int length;
    friend class Sudoku;

public:
    ListPlayer();
    ListPlayer(Player *players, int length);
    ~ListPlayer();
    void addRankingToFile();
    void printPlayers();
    Player *getList();
    int getLength();
    void AddPlayer(Player player);
    Player *Ranking();
    void ShellSortPlayer();
    ListPlayer &operator=(const ListPlayer &ListPlayer);
};