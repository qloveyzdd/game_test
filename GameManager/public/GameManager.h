#pragma once
#include <vector>
#include "Adventure.h"
#include "Monster.h"
#include <string>

using std::string;
using std::vector;

class GameManager
{
private:
    int m_totallevel;
    int m_curlevel;
    int m_encounterprob;

    vector<Adventure *> m_adventures;
    vector<Monster *> m_monsters;
    vector<string> m_names;

public:
    GameManager();
    ~GameManager();
};

GameManager::~GameManager()
{
}
