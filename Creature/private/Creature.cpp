#include "Creature.h"

void Creature::BeDamaged(const int damage)
    {
        int delta = damage;
        if(m_armor>0)
        {
            if(m_armor>delta)
            {
                m_armor -= delta;
                return;
            }
            else
            {
                m_armor = 0;
                delta -= m_armor;
            }
        }

        if (m_curhp>0)
        {
            m_curhp-=delta;
        }
        
    }