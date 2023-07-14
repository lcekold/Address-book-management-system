#include<iostream>
#include<string>
#include"head.h"
#define MAX 1000 //最大人数
using namespace std;


//菜单界面
void showMenu()
{
	cout << "*********************************" << endl;
	cout << "*******  1、添加联系人   ********" << endl;
	cout << "*******  2、显示联系人   ********" << endl;
	cout << "*******  3、删除联系人   ********" << endl;
	cout << "*******  4、查找联系人   ********" << endl;
	cout << "*******  5、修改联系人   ********" << endl;
	cout << "*******  6、清空联系人   ********" << endl;
	cout << "*******  0、退出通讯录   ********" << endl;
	cout << "*********************************" << endl;
}





//1.添加联系人
void addPerson(Addressbooks* abs)
{
	//判断通讯录是否满了，如果满了就不再进行添加
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else
	{
		//姓名
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;

		//性别
		cout << "请输入性别:" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex != 1 && sex != 2)
			{
				cout << "您输入的性别有误，请重新输入" << endl;
			}
			else
			{
				break;
			}
		}
	
		//年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		cin >> age;

		//电话
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;

		//住址
		cout << "请输入家庭住址:" << endl;
		string address;
		cin >> address;

		//读取进通讯录当中
		abs->personArray[abs->m_Size] = Person(name, sex, age, phone, address);
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功" << endl;

		system("pause");//请按任意键继续
		system("cls");//清屏操作
	}
}

//输出流运算符重载
ostream& operator <<(ostream& out, Person& s)
{
	out << "姓名:" << s.m_Name << "\t" << "性别:" << (s.m_Sex == 1 ? "男" : "女") << "\t" << "年龄 : " << s.m_Age << "\t" << "电话:" << s.m_Phone << "\t" << "地址:" << s.m_Addr << endl;
	return out;
}



//2.显示所有的联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	if (abs->m_Size == 0)
	{
		cout << "记录为空" << endl;
	}
	//如果不为0，显示记录的联系人信息
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i] << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");//清屏操作
}


//检测联系人是否存在，如果存在，返回联系人所在数组的具体位置，不存在返回-1
int isExist(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名了
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到了返回这个人在数组的下标编号
		}
		
	}
		return -1;//如果遍历结束都没有找到，返回-1
	
}



//3.删除联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;

	//ret == -1代表没有查到此人
	//ret != -1代表没有查到
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}





//4.查找指定的联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	//判断指定的联系人是否存在通讯录中
	int ret=isExist(abs, name);

	if (ret != -1)
	{
		cout << abs->personArray[ret] << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	//按下任意键后清屏
	system("pause");
	system("cls");
}


//5.修改指定联系人的信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)//找到指定联系人
	{
		//姓名
		string name;
		cout << "请输入姓名:" << endl;
		cin >> name;

		//性别
		cout << "请输入性别:" << endl;
		cout << "1----男" << endl;
		cout << "2----女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex != 1 && sex != 2)
			{
				cout << "您输入的性别有误，请重新输入" << endl;
			}
			else
			{
				break;
			}
		}

		//年龄
		cout << "请输入年龄:" << endl;
		int age = 0;
		cin >> age;

		//电话
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;

		//住址
		cout << "请输入家庭住址:" << endl;
		string address;
		cin >> address;

		//读取进通讯录当中
		abs->personArray[ret] = Person(name, sex, age, phone, address);
	
		cout << "修改成功!" << endl;
	}
	else //未找到联系人
	{
		cout << "查无此人" << endl;
	}

	//按任意键后清屏
	system("pause");
	system("cls");
}


//6.清空联系人
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//将当前记录联系人数量重置为0，做逻辑清空操作
	cout << "通讯录已清空" << endl;

	system("pause");
	system("cls");
}