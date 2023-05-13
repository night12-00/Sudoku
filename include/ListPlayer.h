#pragma once
#include "Player.h"
#include "Sudoku.h"
#include "include.h"

class Player;

class ListPlayer
{
private:
    friend class Sudoku;
    Player *players;
    int length;

public:
    ListPlayer();
    ListPlayer(Player *players, int length);
    ~ListPlayer();
    void getRankingToFile();
    void addRankingToFile();
    void printPlayers();
    Player *getList();
    int getLength();
    void AddPlayer(Player player);
    Player *Ranking();
    void ShellSortPlayer();
    ListPlayer &operator=(const ListPlayer &ListPlayer);
};