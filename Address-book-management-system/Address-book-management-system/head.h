#pragma once

#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //最大人数


void showMenu();


//联系人结构体
struct Person
{
	string m_Name;//姓名
	int m_Sex;//性别，1男 2女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Addr;//住址

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


//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int m_Size;//通讯录中人员个数
};


void addPerson(Addressbooks* abs);

void showPerson(Addressbooks* abs);

int isExist(Addressbooks* abs, string name);

void deletePerson(Addressbooks* abs);

void findPerson(Addressbooks* abs);

void modifyPerson(Addressbooks* abs);

void cleanPerson(Addressbooks* abs);