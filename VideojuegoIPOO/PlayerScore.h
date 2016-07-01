#ifndef PLAYERSCORE_H_INCLUDED
#define PLAYERSCORE_H_INCLUDED

#include <string>
#include <vector>

class PlayerScore
{
public:
    PlayerScore(const int &_pos = 0,
                const std::string &_name = "UNKNOWN",
                const int &_score = 0);
    PlayerScore(const std::string &_name = "UNKNOWN",
                const int &_score = 0);
    std::string getInfo();
    unsigned pos;
    int score;

private:
    void toArrInts(int _score);
    void toArrChar(const std::string &_name);

    std::string info;
    std::string name;
    int scoreArr[4];
};


class ArrPlayers
{
public:
    std::vector<PlayerScore *> arrPtrPlayers;
    void insertPlayer(PlayerScore *newPlayer);
    PlayerScore *getPlayer(const unsigned &pos);
};

#endif // PLAYERSCORE_H_INCLUDED
