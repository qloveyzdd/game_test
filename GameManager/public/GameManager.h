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

    GameManager();

public:
    static GameManager*GetInstance();
    ~GameManager();
    int ReturnRandom(const int max)const{return rand()%max+1;}//随机1-max
    int ReturnAge()const{return 18+ReturnRandom(10);}//随机年龄
    string ReturnName();//随机名字
    bool IsEncounter();//是否出现怪物
    void OutPutInstructionFromFile();//读取文件，提供描述
    void GenerateMonster();//刷新怪物容器
    void EveryAdventureAttack();//勇士攻击
    void EveryMonsterAttack();//怪物攻击
    int FindIndexForMonster(const int id)const;//通过id获取怪物索引
    int FindIndexForAd(const int id)const;//通过id获取勇士索引
    void DeadSettleForAd(const int index);//勇士伤害结算
    void DeadSettleForMonster(const int index);//怪物伤害结算
    void PassReward();//通关奖励
    void Start();

};