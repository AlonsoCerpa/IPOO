#include "PlayerScore.h"

PlayerScore::PlayerScore(const int &_pos, const std::string &_name, const int &_score)
    : pos{_pos}, name{_name}, score{_score}
    {
        toArrInts(score);
    }

PlayerScore::PlayerScore(const std::string &_name, const int &_score)
    : name{_name}, score{_score}
    {
        toArrInts(score);
    }

void PlayerScore::toArrInts(int _score)
{
    for (int i = 3; i >= 0; --i)
    {
        scoreArr[i] = _score % 10;
        _score /= 10;
    }
}

std::string PlayerScore::getInfo()
{
    return info = std::to_string(pos) + ' ' +
    name + ' ' +
    static_cast<char>(scoreArr[0] + 48) +
    static_cast<char>(scoreArr[1] + 48) +
    static_cast<char>(scoreArr[2] + 48) +
    static_cast<char>(scoreArr[3] + 48) + '\n';
}

//////////////////////////////////////////////////////////////////////////////

void ArrPlayers::insertPlayer(PlayerScore *newPlayer)
{
    unsigned i;
    for (i = 0; i <= 4 && arrPtrPlayers[i]->score > newPlayer->score; ++i)
        ;
    delete arrPtrPlayers[4];
    for (unsigned h = 4; h > i; --h)
    {
        arrPtrPlayers[h] = arrPtrPlayers[h - 1];
        arrPtrPlayers[h]->pos = h + 1;
    }
    arrPtrPlayers[i] = newPlayer;
    arrPtrPlayers[i]->pos = i + 1;
}

PlayerScore *ArrPlayers::getPlayer(const unsigned &pos)
{
    return arrPtrPlayers[pos];
}
