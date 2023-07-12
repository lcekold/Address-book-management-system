#include<iostream>
#include"head.h"

using namespace std;

int main()
{
	int select = 0;

	showMenu();

	
	
	while (true)
	{
		cin >> select;
		switch (select)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 0:   //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
}