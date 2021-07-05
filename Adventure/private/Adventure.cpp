#include "Adventure.h"

Adventure::Adventure(int basedamage, std::string name, int age,AdventureType type, int id)
    : m_name(name), m_age(age),m_type(type)
{
    m_basedamage = basedamage;
    m_id = id;
    m_maxhp = 100;
    m_curhp = m_maxhp;
    m_armor = 0;
    m_money = 0;
    m_isattackedbyclose = false;

}