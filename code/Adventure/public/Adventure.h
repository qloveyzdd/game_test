#pragma once
#include "Creature.h"
#include <string>

enum AdventureType
{
    Warriors,
    Rogues,
    OffensiveMages,
    DefensiveMages,
};

class Adventurer : public Creature
{
private:
    AdventureType m_type;
    std::string m_name;       //姓名
    int m_age;                //年龄
    int m_money;              //金钱
    bool m_isattackedbyclose; //攻击停止

public:
    Adventurer(int basedamage, std::string name, int age, AdventureType type, int id);
    virtual ~Adventurer(){};
    virtual void CloseAttack(Creature &one) = 0;
    virtual void DistanceAttackNoMp(Creature &a){};
    virtual bool DistanceMagic(Creature &a) { return false; }
    virtual bool DistanceMagic(Creature &a, Creature &b) { return false; }
    virtual bool DistanceMagic(Creature &a, Creature &b, Creature &c) { return false; }
    virtual void MpRestore() {}

    AdventureType ReturnType() const { return m_type; };
    void HpRestore() { m_curhp = m_curhp; }
    void AddMaxHp(int delta)
    {
        m_maxhp += delta;
        m_curhp = m_maxhp;
    }
    std::string GetName() const { return m_name; }
    int GetAge() const { return m_age; }
    int GetMoney() const { return m_money; }
    void AddMoney(const int delta) { m_money += delta; }
    void AddBaseDamaged(const int delta) { m_basedamage += delta; }
    bool IsAttackedByClose() { return m_isattackedbyclose; }
    void SetAttackedByClose(bool attacked) { m_isattackedbyclose = attacked; }
    int GetArmor() { return m_armor; }
};
