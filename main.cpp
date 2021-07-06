#include <iostream>
#include"GameManager.h"
#include<time.h>

#define MANAGER GameManager::GetInstance()

int main()
{
    srand((unsigned)time(0));
    char c =0;

    while (c != 'e')
	{
		MANAGER->Start();
		cout << endl << "输入e退出，输入其他键重新游戏" << endl;
		std::cin >> c;
	}
    return 0;
}