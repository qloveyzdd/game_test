#include "GameManager.h"
#include "Warrior.h"
#include "Rogue.h"
#include "OffensiveMage.h"
#include "DefensiveMage.h"
#include <fstream>
#include "Tiger.h"
#include "Eagle.h"
#include "Witch.h"
#include "Mummy.h"
#include "Dragon.h"

GameManager::GameManager()
{
    m_names = {"A", "B", "C", "D", "E"};
    m_curlevel = 1;
    m_totallevel = 20;
    m_encounterprob = 30; //遇怪几率
    m_adventures.push_back(new Warrior(ReturnName(), ReturnAge(), 1));
    m_adventures.push_back(new Rogue(ReturnName(), ReturnAge(), 2));
    m_adventures.push_back(new OffensiveMage(ReturnName(), ReturnAge(), 3));
    m_adventures.push_back(new DefensiveMage(ReturnName(), ReturnAge(), 4));

    for (int i = 0; i < 3; i++)
    {
        int choice = ReturnRandom(4);
        switch (choice)
        {
        case 0:
            m_adventures.push_back(new Warrior(ReturnName(), ReturnAge(), 5 + i));
            break;
        case 1:
            m_adventures.push_back(new Rogue(ReturnName(), ReturnAge(), 5 + i));
            break;
        case 2:
            m_adventures.push_back(new OffensiveMage(ReturnName(), ReturnAge(), 5 + i));
            break;
        case 3:
            m_adventures.push_back(new DefensiveMage(ReturnName(), ReturnAge(), 5 + i));
            break;
        default:
            break;
        }
    }
}

GameManager::~GameManager()
{
    m_adventures.clear();
    m_monsters.clear();
}

string GameManager::ReturnName()
{
    int i = ReturnRandom(m_names.size()) - 1;
    string name = m_names[i];
    m_names.erase(m_names.begin() + i);
    return name;
}

bool GameManager::IsEncounter()
{
    int n = ReturnRandom(100);
    if (n <= m_encounterprob)
    {
        return false;
    }
    return true;
}

void GameManager::OutPutInstructionFromFile()
{
    char line[1024] = {0};
    std::ifstream fin("data.txt");
    if (!fin)
    {
        cout << "no data.txt!" << endl;
        return;
    }
    else if (fin.fail())
    {
        cout << "file is empty!" << endl;
        return;
    }
    do
    {
        fin.getline(line, sizeof(line));
        cout << line << endl;
    } while (!fin.eof());

    fin.close();
}

void GameManager::GenerateMonster()
{
    m_monsters.clear();

    int n = ReturnRandom(4) - 1;
    for (int i = 0; i < n; i++)
    {
        m_monsters.push_back(new Tiger(m_monsters.size() + 1));
    }

    int n = ReturnRandom(4) - 1;
    for (int i = 0; i < n; i++)
    {
        m_monsters.push_back(new Eagle(m_monsters.size() + 1));
    }

    int n = ReturnRandom(3) - 1;
    for (int i = 0; i < n; i++)
    {
        m_monsters.push_back(new Witch(m_monsters.size() + 1));
    }

    int n = ReturnRandom(3) - 1;
    for (int i = 0; i < n; i++)
    {
        m_monsters.push_back(new Mummy(m_monsters.size() + 1));
    }

    int n = ReturnRandom(2) - 1;
    for (int i = 0; i < n; i++)
    {
        m_monsters.push_back(new Dragon(m_monsters.size() + 1));
    }
}

void GameManager::EveryAdventureAttack()
{
    for (auto var : m_adventures)
    {
        if (var->ReturnType() == Warriors)
        {
            while (1)
            {
                cout << var->GetID() << "号勇士" << var->GetName() << "是一个勇士,他的技能有：1.近身攻击" << endl;
                int skill = 1;
                cout << "输入你想使用的技能序号：";
                std::cin >> skill;
                cout << "对几号怪物使用：" << endl;
                int m = 0;
                std::cin >> m;

                int i = FindIndexForMonster(m);
                if (i != -1)
                {
                    var->CloseAttack(*m_monsters[i]);
                    cout << "攻击！！" << endl;
                    break;
                }
                else
                {
                    cout << "该怪物不存在，重新选择攻击对象" << endl;
                }
            }
            if (m_monsters.size() == 0)
            {
                break;
            }
        }
        if (var->ReturnType() == Rogues)
        {
            while (1)
            {

                cout << var->GetID() << "号勇士" << var->GetName() << "是一个刺客,他的技能有：1.近身攻击 2.远程攻击" << endl;
                int skill = 1;
                if (var->IsAttackedByClose())
                {
                    cout << "现在他被近身了，远程攻击被封锁，只能近战来反击对手" << endl;
                }
                else
                {
                    cout << "输入你想让他使用的技能序号：";
                    std::cin >> skill;
                }
                cout << "对几号怪物使用：" << endl;
                int m = 0;
                std::cin >> m;

                int i = FindIndexForMonster(m);
                if (i != -1)
                {
                    if (skill == 1)
                    {
                        var->CloseAttack(*m_monsters[i]);
                    }
                    else if (skill == 2)
                    {
                        var->DistanceAttackNoMp(*m_monsters[i]);
                    }
                    cout << "攻击！！" << endl;
                    var->SetAttackedByClose(false);

                    DeadSettleForMonster(i);
                    break;
                }
                else
                {
                    cout << "该怪物不存在，重新选择攻击对象" << endl;
                }
            }
            if (m_monsters.size() == 0)
            {
                break;
            }
        }
    }
}