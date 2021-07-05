#include "DefensiveMage.h"

void DefensiveMage::CloseAttack(Creature&a)
{
    a.BeDamaged(m_basedamage+ReturnRandom());
}

void DefensiveMage::DistanceAttackNoMp(Creature&a)
{
    a.BeDamaged(m_basedamage+ReturnRandom());
}

bool DefensiveMage::DistanceMagic(Creature&a)
{
    if (m_curmp>=20)
    {
        a.AddArmor(m_gain);
        m_curmp -= 20;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool DefensiveMage::DistanceMagic(Creature&a,Creature&b)
{
    if (m_curmp>=40)
    {
        a.AddArmor(m_gain);
        b.AddArmor(m_gain);
        m_curmp -= 40;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool DefensiveMage::DistanceMagic(Creature&a,Creature&b,Creature&c)
{
    if (m_curmp>=60)
    {
        a.AddArmor(m_gain);
        b.AddArmor(m_gain);
        c.AddArmor(m_gain);
        m_curmp -= 60;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}