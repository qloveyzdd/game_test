#include "OffensiveMage.h"

void OffensiveMage::CloseAttack(Creature&a)
{
    a.BeDamaged(m_basedamage+ReturnRandom());
}

void OffensiveMage::DistanceAttackNoMp(Creature&a)
{
    a.BeDamaged(m_basedamage+ReturnRandom());
}

bool OffensiveMage::DistanceMagic(Creature&a)
{
    if (m_curmp>=20)
    {
        a.BeDamaged(m_distancedamage+ReturnRandom());
        m_curmp -= 20;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool OffensiveMage::DistanceMagic(Creature&a,Creature&b)
{
    if (m_curmp>=40)
    {
        a.BeDamaged(m_distancedamage+ReturnRandom());
        b.BeDamaged(m_distancedamage+ReturnRandom());
        m_curmp -= 40;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool OffensiveMage::DistanceMagic(Creature&a,Creature&b,Creature&c)
{
    if (m_curmp>=60)
    {
        a.BeDamaged(m_distancedamage+ReturnRandom());
        b.BeDamaged(m_distancedamage+ReturnRandom());
        c.BeDamaged(m_distancedamage+ReturnRandom());
        m_curmp -= 60;
        std::cout<<"剩余魔法值："<<m_curmp<<std::endl;
        return true;
    }
    else
    {
        return false;
    }
}