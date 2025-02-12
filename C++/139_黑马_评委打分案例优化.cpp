/*
create by wangjunjie
2019 4 16

*/

/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
//1. 创建五名选手，放到vector中
//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
//4. deque容器遍历一遍，累加分数，累加分数/d.size()
//5. person.score = 平均分
*/


#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include<ctime>
#include<vector>
#include<deque>
#include<algorithm>
#include<string>

//1、设计选手类
class Person
{
public:

	Person() {};

	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}


	string m_Name;   //姓名
	int m_Score;	//平均分
};

//2、创建存放选手容器
void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0;i < 5;i++)
	{
		//初始化姓名
		string name = "选手";
		name += nameSeed[i];

		//初始化分数
		int score = 0;

		//创建对象并赋初值
		Person p(name, score);

		//将对象放入到容器中 v容器中存放了5名选手的信息
		v.push_back(p);
	}
}

//3、创建5名选手
void setScore(vector<Person>&v)
{
	//v容器中存放了5名选手的信息
	//对选手的分值信息逐个赋值
	for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	{
		//准备deque容器 存放 评委分数
		deque<int>d;
		for (int i = 0;i < 10;i++)
		{
			int score = rand() % 41 + 60;//0-40 + 60 = 60--100
			d.push_back(score);
		}

		//查看10个评委分数
		//cout << "选手 " << it->m_Name << "打分： " << endl;
		//for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		//{
		//	cout << *dit << " ";
		//}
		//cout << endl;


		//排序
		sort(d.begin(), d.end());

		//去掉最高分 最低分
		d.pop_back();    //最高
		d.pop_front();  //最低

		//总分
		int sum = 0;
		for (deque<int>::iterator dit = d.begin();dit != d.end();dit++)
		{
			sum += *dit;
		}

		//平均分
		int average = sum / d.size();

		//将平均分赋值给Person
		it->m_Score = average;
	}
}

void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin();it != v.end();it++)
	{
		cout << "姓名："<< it->m_Name << "  年龄：  " << it->m_Score << endl;
	}
}

int main()
{
	//随机数种子
	srand((unsigned int)time(NULL));

	//1、设计选手类


	//2、创建存放选手容器
	vector<Person>v;


	//3、创建5名选手
	createPerson(v);


	//4、选手打分
	setScore(v);

	//5、打印平均分
	showScore(v);

	////测试容器
	//for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
	//{
	//	cout << "姓名： " << (*it).m_Name << " 分数： " << it->m_Score << endl;
	//}

	system("pause");
	return EXIT_SUCCESS;
}






