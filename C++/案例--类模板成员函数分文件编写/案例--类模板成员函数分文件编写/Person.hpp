#pragma  once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;


template<class T1, class T2>
class Person
{
public:

	//有参构造
	Person(T1 name, T2 age);

	void showPerson();

	T1 m_Name;
	T2 m_Age;
};

//类外实现
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Age = age;
	this->m_Name = name;
}

//类外实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名： " << this->m_Name << "  年龄： " << this->m_Age << endl;
}











