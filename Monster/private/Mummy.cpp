#include "Mummy.h"

void Mummy::CloseAttack(Creature &one)
{
    one.BeDamaged(m_basedamage + ReturnRandom());
    AddHp(m_basedamage);
    cout << "吸取了" << m_basedamage << "点生命值" << endl;
}