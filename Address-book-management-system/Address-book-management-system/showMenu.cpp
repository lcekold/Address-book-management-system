#include<iostream>
#include<string>
#include"head.h"
#define MAX 1000 //�������
using namespace std;


//�˵�����
void showMenu()
{
	cout << "*********************************" << endl;
	cout << "*******  1�������ϵ��   ********" << endl;
	cout << "*******  2����ʾ��ϵ��   ********" << endl;
	cout << "*******  3��ɾ����ϵ��   ********" << endl;
	cout << "*******  4��������ϵ��   ********" << endl;
	cout << "*******  5���޸���ϵ��   ********" << endl;
	cout << "*******  6�������ϵ��   ********" << endl;
	cout << "*******  0���˳�ͨѶ¼   ********" << endl;
	cout << "*********************************" << endl;
}





//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ����ˣ�������˾Ͳ��ٽ������
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else
	{
		//����
		string name;
		cout << "����������:" << endl;
		cin >> name;

		//�Ա�
		cout << "�������Ա�:" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex != 1 && sex != 2)
			{
				cout << "��������Ա���������������" << endl;
			}
			else
			{
				break;
			}
		}
	
		//����
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;

		//�绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin >> phone;

		//סַ
		cout << "�������ͥסַ:" << endl;
		string address;
		cin >> address;

		//��ȡ��ͨѶ¼����
		abs->personArray[abs->m_Size] = Person(name, sex, age, phone, address);
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�" << endl;

		system("pause");//�밴���������
		system("cls");//��������
	}
}

//��������������
ostream& operator <<(ostream& out, Person& s)
{
	out << "����:" << s.m_Name << "\t" << "�Ա�:" << (s.m_Sex == 1 ? "��" : "Ů") << "\t" << "���� : " << s.m_Age << "\t" << "�绰:" << s.m_Phone << "\t" << "��ַ:" << s.m_Addr << endl;
	return out;
}



//2.��ʾ���е���ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	if (abs->m_Size == 0)
	{
		cout << "��¼Ϊ��" << endl;
	}
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << abs->personArray[i] << endl;
		}
	}
	system("pause");//�밴���������
	system("cls");//��������
}


//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
int isExist(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û������������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ��˷����������������±���
		}
		
	}
		return -1;//�������������û���ҵ�������-1
	
}



//3.ɾ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	//ret == -1����û�в鵽����
	//ret != -1����û�в鵽
	int ret = isExist(abs,name);
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}





//4.����ָ������ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����ͨѶ¼��
	int ret=isExist(abs, name);

	if (ret != -1)
	{
		cout << abs->personArray[ret] << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}

	//���������������
	system("pause");
	system("cls");
}


//5.�޸�ָ����ϵ�˵���Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);

	if (ret != -1)//�ҵ�ָ����ϵ��
	{
		//����
		string name;
		cout << "����������:" << endl;
		cin >> name;

		//�Ա�
		cout << "�������Ա�:" << endl;
		cout << "1----��" << endl;
		cout << "2----Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex != 1 && sex != 2)
			{
				cout << "��������Ա���������������" << endl;
			}
			else
			{
				break;
			}
		}

		//����
		cout << "����������:" << endl;
		int age = 0;
		cin >> age;

		//�绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin >> phone;

		//סַ
		cout << "�������ͥסַ:" << endl;
		string address;
		cin >> address;

		//��ȡ��ͨѶ¼����
		abs->personArray[ret] = Person(name, sex, age, phone, address);
	
		cout << "�޸ĳɹ�!" << endl;
	}
	else //δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}

	//�������������
	system("pause");
	system("cls");
}


//6.�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;//����ǰ��¼��ϵ����������Ϊ0�����߼���ղ���
	cout << "ͨѶ¼�����" << endl;

	system("pause");
	system("cls");
}