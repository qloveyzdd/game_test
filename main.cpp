#include <iostream>
#include "Creature.h"
#include "Adventure.h"
#include"Monster.h"

int main()
{
    int d = 0;
    for (int i = 0; i < 10; i++)
    {
        d += i;
    }

    std::cout << "hello world!!" << d << std::endl;
    return 0;
}