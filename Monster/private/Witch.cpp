#include"Witch.h"

bool Witch::DistanceMagic(Creature &a)
{
    if (m_curmp >=20)
    {
        a.BeDamaged(m_distancedamage + ReturnRandom());
        m_curmp -= 20;
        AddHp(10);
        cout<<"吸收10点生命值！剩余魔法值："<<m_curmp<<endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Witch::DistanceMagic(Creature &a, Creature &b)
{
    if (m_curmp >=40)
    {
        a.BeDamaged(m_distancedamage + ReturnRandom());
        b.BeDamaged(m_distancedamage + ReturnRandom());
        m_curmp -= 40;
        AddHp(15);
        cout<<"吸收15点生命值！剩余魔法值："<<m_curmp<<endl;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool Witch::DistanceMagic(Creature &a, Creature &b, Creature &c)
{
    if (m_curmp >=60)
    {
        a.BeDamaged(m_distancedamage + ReturnRandom());
        b.BeDamaged(m_distancedamage + ReturnRandom());
        c.BeDamaged(m_distancedamage + ReturnRandom());
        m_curmp -= 60;
        AddHp(20);
        cout<<"吸收20点生命值！剩余魔法值："<<m_curmp<<endl;
        return true;
    }
    else
    {
        return false;
    }
}