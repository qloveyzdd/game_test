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
    m_names = {"老杨", "书吉", "周伟", "天驰", "老蔡"};
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

GameManager* GameManager::GetInstance()
{
    static GameManager instance;
    return &instance;
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
        if (var->ReturnType() == OffensiveMages)
        {
            while (1)
            {

                cout << var->GetID() << "号勇士" << var->GetName() << "是一个法师,他的技能有：1.近身攻击 2.远程攻击 3.魔法：火球术 4.魔法：火焰双子 5.魔法：地狱烈焰" << endl;
                int skill = 1;
                if (var->IsAttackedByClose())
                {
                    cout << "现在他被近身了，远程攻击被封锁，只能近战来反击对手" << endl;
                    var->SetAttackedByClose(false);
                }
                else
                {
                    cout << "输入你想让他使用的技能序号：";
                    std::cin >> skill;
                }
                if (skill == 1 || skill == 2 || skill == 3)
                {
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
                        else
                        {
                            if (!var->DistanceMagic(*m_monsters[i]))
                            {
                                cout << "魔力不足！选择别的攻击方式！" << endl;
                                continue;
                            }
                        }
                        cout << "攻击！！" << endl;
                        var->SetAttackedByClose(false);

                        DeadSettleForMonster(i);
                        break;
                    }
                }
                else
                {
                    cout << "该怪物不存在，重新选择攻击对象" << endl;
                }
                if (skill == 4)
                {
                    cout << "选择二个怪物的编号(从小到大)" << endl;
                    int m1 = 0;
                    int m2 = 0;
                    std::cin >> m1 >> m2;

                    int i = FindIndexForMonster(m1);
                    int i2 = FindIndexForMonster(m2);
                    if (i != -1 && i2 != -1)
                    {
                        if (!var->DistanceMagic(*m_monsters[i], *m_monsters[i2]))
                        {
                            cout << "魔力不足！选择别的攻击方式！" << endl;
                            continue;
                        }
                        cout << "攻击！！" << endl;
                        var->SetAttackedByClose(false);

                        DeadSettleForMonster(i2);
                        DeadSettleForMonster(i);
                        break;
                    }
                    else
                    {
                        cout << "该怪物不存在，重新选择攻击对象" << endl;
                    }
                }
                if (skill == 5)
                {
                    cout << "选择三个怪物的编号(从小到大)" << endl;
                    int m1 = 0;
                    int m2 = 0;
                    int m3 = 0;
                    std::cin >> m1 >> m2 >> m3;

                    int i = FindIndexForMonster(m1);
                    int i2 = FindIndexForMonster(m2);
                    int i3 = FindIndexForMonster(m3);
                    if (i != -1 && i2 != -1 && i3 != -1)
                    {
                        if (!var->DistanceMagic(*m_monsters[i], *m_monsters[i2], *m_monsters[i3]))
                        {
                            cout << "魔力不足！选择别的攻击方式！" << endl;
                            continue;
                        }
                        cout << "攻击！！" << endl;
                        var->SetAttackedByClose(false);

                        DeadSettleForMonster(i3);
                        DeadSettleForMonster(i2);
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
        if (var->ReturnType() == DefensiveMages)
        {
            while (1)
            {

                cout << var->GetID() << "号勇士" << var->GetName() << "是一个牧师,他的技能有：1.近身攻击 2.远程攻击 3.魔法：精准保护 4.魔法：联盟壁垒 5.魔法：大地守护" << endl;
                int skill = 1;
                if (var->IsAttackedByClose())
                {
                    cout << "现在他被近身了，远程攻击被封锁，只能近战来反击对手" << endl;
                    var->SetAttackedByClose(false);
                }
                else
                {
                    cout << "输入你想让他使用的技能序号：";
                    std::cin >> skill;
                }
                if (skill == 1 || skill == 2)
                {
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
                if (skill == 3)
                {
                    cout << "对几号冒险者使用：" << endl;
                    int m = 0;
                    std::cin >> m;

                    int i = FindIndexForAd(m);
                    if (i != -1)
                    {
                        if (!var->DistanceMagic(*m_adventures[i]))
                        {
                            cout << "魔力不足！选择别的方式！" << endl;
                            continue;
                        }
                        cout << "加强防御！！！" << endl;
                        var->SetAttackedByClose(false);
                        break;
                    }
                    else
                    {
                        cout << "该冒险者不存在或者已经死亡，重新选择" << endl;
                    }
                }
                if (skill == 4)
                {
                    cout << "选择二个冒险者的编号(从小到大)" << endl;
                    int m1 = 0;
                    int m2 = 0;
                    std::cin >> m1 >> m2;

                    int i = FindIndexForAd(m1);
                    int i2 = FindIndexForAd(m2);
                    if (i != -1 && i2 != -1)
                    {
                        if (!var->DistanceMagic(*m_monsters[i], *m_monsters[i2]))
                        {
                            cout << "魔力不足！选择别的方式！" << endl;
                            continue;
                        }
                        cout << "加强防御！！！" << endl;
                        var->SetAttackedByClose(false);
                        break;
                    }
                    else
                    {
                        cout << "该冒险者不存在或者已经死亡，重新选择" << endl;
                    }
                }
                if (skill == 5)
                {
                    cout << "选择三个冒险者的编号(从小到大)" << endl;
                    int m1 = 0;
                    int m2 = 0;
                    int m3 = 0;
                    std::cin >> m1 >> m2 >> m3;

                    int i = FindIndexForAd(m1);
                    int i2 = FindIndexForAd(m2);
                    int i3 = FindIndexForAd(m3);
                    if (i != -1 && i2 != -1 && i3 != -1)
                    {
                        if (!var->DistanceMagic(*m_monsters[i], *m_monsters[i2], *m_monsters[i3]))
                        {
                            cout << "魔力不足！选择别的方式！" << endl;
                            continue;
                        }
                        cout << "加强防御！！！" << endl;
                        var->SetAttackedByClose(false);
                        break;
                    }
                    else
                    {
                        cout << "该冒险者不存在或者已经死亡，重新选择" << endl;
                    }
                }
                if (m_monsters.size() == 0)
                {
                    break;
                }
            }
        }
    }
}

void GameManager::EveryMonsterAttack()
{
    for (auto var : m_monsters)
    {
        cout << var->GetID() << "号怪物出动！" << endl;
        int i = ReturnRandom(m_adventures.size()) - 1;

        if (var->ReturnType() == TIGER || var->ReturnType() == MUMMY)
        {
            var->CloseAttack(*m_adventures[i]);
            m_adventures[i]->SetAttackedByClose(true);
            cout << var->GetID() << "号怪物对" << m_adventures[i]->GetID() << "号冒险者进行了近身撕咬！" << endl;
            DeadSettleForAd(i);
        }
        else if (var->ReturnType() == EAGLE)
        {
            var->DistanceAttackNoMp(*m_adventures[i]);
            cout << var->GetID() << "号怪物对" << m_adventures[i]->GetID() << "号冒险者进行了羽翼风暴攻击！" << endl;
            DeadSettleForAd(i);
        }
        else if (var->ReturnType() == WITCH)
        {
            int i2 = ReturnRandom(m_adventures.size() - i) - 1 + i;
            int i3 = ReturnRandom(m_adventures.size() - i2) - 1 + i2;
            if (!var->DistanceMagic(*m_adventures[i], *m_adventures[i2], *m_adventures[i3]))
            {
                if (!var->DistanceMagic(*m_adventures[i], *m_adventures[i2]))
                {
                    if (!var->DistanceMagic(*m_adventures[i]))
                    {
                        var->DistanceAttackNoMp(*m_adventures[i]);
                        cout << var->GetID() << "号怪物对"
                             << m_adventures[i]->GetID() << "号冒险者发动了投石攻击" << endl;
                        DeadSettleForAd(i);
                    }
                    else
                    {
                        cout << var->GetID() << "号怪物对"
                             << m_adventures[i]->GetID() << "号冒险者发动了心灵暴振" << endl;
                        DeadSettleForAd(i);
                    }
                }
                else
                {
                    cout << var->GetID() << "号怪物对"
                         << m_adventures[i]->GetID() << "号冒险者和"
                         << m_adventures[i2]->GetID() << "号冒险者发动了鸦群攻击" << endl;
                    DeadSettleForAd(i2);
                    if (i != i2)
                    {
                        DeadSettleForAd(i);
                    }
                }
            }
            else
            {
                cout << var->GetID() << "号怪物对"
                     << m_adventures[i]->GetID() << "号冒险者和"
                     << m_adventures[i2]->GetID() << "号冒险者和"
                     << m_adventures[i3]->GetID() << "号冒险者发动了究极风暴攻击" << endl;
                DeadSettleForAd(i3);
                if (i2 != i3)
                {
                    DeadSettleForAd(i2);
                }
                if (i != i2)
                {
                    DeadSettleForAd(i);
                }
            }
        }
        else if (var->ReturnType() == DRAGON)
        {
            if (!var->IsUsedKS())
            {
                var->KillSky(m_adventures);
                cout << "天啊！！！" << var->GetID() << "号怪兽是巨龙！大家小心，它发动大招了！！" << endl;
                cout << "巨龙：毁天灭地！！！" << endl;

                for (int j = m_adventures.size() - 1; j >= 0; j--)
                {
                    DeadSettleForAd(j);
                }
            }
            else
            {
                var->DistanceAttackNoMp(*m_adventures[i]);
                cout << var->GetID() << "号怪物对" << m_adventures[i]->GetID() << "号冒险者发动了巨龙吐息！" << endl;
                DeadSettleForAd(i);
            }
        }
        if (m_adventures.size() == 0)
        {
            break;
        }
    }
}

int GameManager::FindIndexForMonster(const int id) const
{
    for (int i = 0; i < m_monsters.size(); i++)
    {
        if (m_monsters[i]->GetID() == id)
        {
            return i;
        }
    }
    return -1;
}

int GameManager::FindIndexForAd(const int id) const
{
    for (int i = 0; i < m_adventures.size(); i++)
    {
        if (m_adventures[i]->GetID() == id)
        {
            return i;
        }
    }
    return -1;
}

void GameManager::DeadSettleForAd(const int index)
{
    if (m_adventures[index]->GetHp() <= 0)
    {
        cout << m_adventures[index]->GetID() << "号冒险家" << m_adventures[index]->GetName() << "离开了冒险队伍" << endl;
        m_adventures.erase(m_adventures.begin() + index);
    }
    else
    {
        cout << m_adventures[index]->GetID() << "号冒险家" << m_adventures[index]->GetName() << "血量还剩下：" << m_adventures[index]->GetHp() << endl;
    }
}

void GameManager::DeadSettleForMonster(const int index)
{
    if (m_monsters[index]->GetHp() <= 0)
    {
        cout << m_monsters[index]->GetID() << "号怪物" << m_monsters[index]->ReturnType() << "死亡" << endl;
        m_monsters.erase(m_monsters.begin() + index);
    }
    else
    {
        cout << m_monsters[index]->GetID() << "号怪物" << m_monsters[index]->ReturnType() << "血量还剩下：" << m_monsters[index]->GetHp() << endl;
    }
}

void GameManager::PassReward()
{
    int coins = ReturnRandom(300) / m_adventures.size();
    for (auto var : m_adventures)
    {
        var->AddMoney(coins);
        var->HpRestore();
        var->MpRestore();
    }
    cout << "你解决掉了这一关的所有怪物！，在打扫战场时获得了战利品，每个冒险家获得了" << coins << "枚金币";

    int dice = ReturnRandom(3);

    switch (dice)
    {
    case 1:
        int choice = ReturnRandom(m_adventures.size()) - 1;
        m_adventures[choice]->AddMaxHp(20);
        cout << m_adventures[choice]->GetID() << "h号冒险者获得了生命的祝福，血量上限提高了20点" << endl;
        break;
    case 2:
        int choice = ReturnRandom(m_adventures.size()) - 1;
        m_adventures[choice]->AddBaseDamaged(8);
        cout << m_adventures[choice]->GetID() << "h号冒险者获得了战神附体，伤害提高了8点" << endl;
        break;
    default:
        cout << "打扫战场结束，没有发现什么特别的东西" << endl;
        break;
    }
}

void GameManager::Start()
{
    string adventurertype[4] = {"勇士", "刺客", "法师", "牧师"};
    string monstertype[5] = {"老虎", "鹰", "女巫", "木乃伊", "恶龙"};

    cout << endl
         << "你的初期冒险团队是：" << endl;
    for (auto val : m_adventures)
    {
        cout << val->GetID() << "号冒险者" << val->GetName() << endl;
        cout << "年龄：" << val->GetAge() << "  职业：" << adventurertype[val->ReturnType()] << endl;
    }
    cout << "冒险开始！" << endl;

    while (m_curlevel <= m_totallevel)
    {
        if (IsEncounter())
        {
            GenerateMonster();
            cout << "你在第" << m_curlevel << "hour遭遇了怪物！它们是：" << endl;
            for (auto var : m_monsters)
            {
                cout << var->GetID() << "号怪物:" << monstertype[var->ReturnType()] << endl;
            }
            cout << "现在，是你的回合" << endl;
            while (1)
            {
                cout << "轮到你了！" << endl;
                EveryAdventureAttack();
                if (m_monsters.size() == 0)
                {
                    break;
                }
                cout << endl
                     << "轮到怪物攻击了！" << endl;
                cout << endl;
                std::cin.get();
                std::cin.get();
                EveryMonsterAttack();
                if (m_adventures.size() == 0)
                {
                    break;
                }

                cout << endl
                     << "下一回合开始" << endl;

                cout << endl
                     << "目前怪物情况:" << endl;
                for (auto var : m_monsters)
                {
                    cout << var->GetID() << "号怪物血量:" << var->GetHp() << endl;
                }
                cout << endl
                     << "目前冒险家情况:" << endl;
                for (auto var : m_adventures)
                {
                    cout << var->GetID() << "号冒险家血量:" << var->GetHp() << " 护甲:" << var->GetArmor() << endl;
                }
                cout << endl;
                std::cin.get();
            }
            if (m_monsters.size() == 0) //过关，分配宝物
            {
                PassReward();
            }
            if (m_adventures.size() == 0)
            {
                cout << "游戏失败，您止步于第" << m_curlevel << "关" << endl;
                std::cin.get();
                return;
            }
        }
        else
            cout << "在第" << m_curlevel << "hour没有发生任何事" << endl;
        m_curlevel++;
    }
    cout << endl
         << "恭喜您通关！" << endl;
    cout << "存活的冒险家的最终情况为:" << endl;
    for (auto var : m_adventures)
    {
        cout << var->GetID() << "号冒险家:" << var->GetName() << "剩余血量:" << var->GetHp() << "  获得金币" << var->GetMoney() << endl;
    }
    return;
}
