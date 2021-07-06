#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Creature
{
protected:
    int m_id;         //编号
    int m_maxhp;      //最大生命
    int m_curhp;      //当前速度
    int m_armor;      //护甲值
    int m_basedamage; //基础伤害
public:
    Creature(){};
    virtual ~Creature(){};

    void BeDamaged(const int damage); //受到伤害

    int ReturnRandom() const { return rand() % 5; } //随即

    void AddArmor(const int armor) { m_maxhp += armor; } //增加最大生命值

    int GetHp() const { return m_curhp; }

    int GetBaseDamage() const { return m_basedamage; }

    int GetID() const { return m_id; }
};
