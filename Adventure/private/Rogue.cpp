#include "Rogue.h"

void Rogue::CloseAttack(Creature &one)
{
    one.BeDamaged(m_basedamage + ReturnRandom());
    m_curhp += m_basedamage;
    std::cout << "吸收了" << m_basedamage << "点血" << std::endl;
    if (m_curhp > m_maxhp)
    {
        m_curhp = m_maxhp;
    }
}

void Rogue::DistanceAttackNoMp(Creature&one)
{
    one.BeDamaged(m_basedamage + ReturnRandom());
}