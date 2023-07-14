#pragma once

#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //�������


void showMenu();


//��ϵ�˽ṹ��
struct Person
{
	string m_Name;//����
	int m_Sex;//�Ա�1�� 2Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Addr;//סַ

	Person(string name, int sex, int age, string phone, string address)
	{
		m_Name = name;
		m_Sex = sex;
		m_Age = age;
		m_Phone = phone;
		m_Addr = address;
	}
	Person(){};
};


//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size;//ͨѶ¼����Ա����
};


void addPerson(Addressbooks* abs);

void showPerson(Addressbooks* abs);

int isExist(Addressbooks* abs, string name);

void deletePerson(Addressbooks* abs);

void findPerson(Addressbooks* abs);

void modifyPerson(Addressbooks* abs);

void cleanPerson(Addressbooks* abs);