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
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4://����ָ����ϵ����Ϣ
			findPerson(&abs);
			break;
		case 5: //�޸�ָ����ϵ����Ϣ
			modifyPerson(&abs);
			break;
		case 6://���ͨѶ¼
			cleanPerson(&abs);
			break;
		case 0:   //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:  
			break;
		}
	}

	system("pause");
}