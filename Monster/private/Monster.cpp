#include"Monster.h"

Monster::Monster(int basedamage,MonsterType type,int id)
:m_type(type)
{
    m_id = id;
    m_basedamage = basedamage;
    m_maxhp = 100;
    m_curhp = m_maxhp;
    m_armor = 0;
}

void Monster::AddHp(int delta)
{
    m_curhp += delta;
    if (m_curhp>m_maxhp)
    {
        m_curhp = m_maxhp;
    }
    
}