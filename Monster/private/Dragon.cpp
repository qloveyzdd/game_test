#include "Dragon.h"

void Dragon::KillSKY(std::vector<Adventure *> &all)
{
    for (auto val : all)
    {
        val->BeDamaged(40);
    }
    usedKS = true;
}