#include "Player.h"

Player::Player()
{
}
Player::Player(string name, double timePlay)
{
    this->name = name;
    this->score = (int)(1 / timePlay) * 5000000;
}
Player::Player(string name, int score)
{
    this->name = name;
    this->score = score;
}
Player::~Player()
{
}

void Player::setPlayer(string name, int score)
{
    this->name = name;
    this->score = score;
}
Player Player::getPlayer()
{
    return *this;
}
Player &Player::operator=(const Player &Player)
{

    this->name = Player.name;
    this->score = Player.score;
    return *this;
}

bool Player::operator==(const Player &Player)
{
    return (this->name == Player.name && this->score == Player.score);
}

bool Player::operator!=(const Player &Player)
{
    return !(*this == Player);
}
