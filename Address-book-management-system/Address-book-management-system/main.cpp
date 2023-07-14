#include<iostream>
#include"head.h"

using namespace std;



int main()
{
	int select = 0;
	Addressbooks abs;
	abs.m_Size = 0;


	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			deletePerson(&abs);
			break;
		case 4://查找指定联系人信息
			findPerson(&abs);
			break;
		case 5: //修改指定联系人信息
			modifyPerson(&abs);
			break;
		case 6://清空通讯录
			cleanPerson(&abs);
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