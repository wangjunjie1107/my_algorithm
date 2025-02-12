#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>    //  accumulate头文件  累加
#include <iterator>

/*
accumulate算法 计算容器元素累计总和
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value累加值
*/
void test01()
{
	vector<int>v;
	for (int i = 1;i <= 100;i++)
	{
		v.push_back(i);
	}

	//参数3 累加起始的值
	int sum = accumulate(v.begin(), v.end(),0);
	cout << sum << endl;
}

/*
fill算法 向容器中添加元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value t填充元素
*/

void test02()
{
	vector<int>v;
	v.resize(10);

	//向容器中添加元素
	fill(v.begin(), v.end(), 100);

	//利用 copy 函数打印
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
}

int main() 
{

	test01();
	test02();

	system("pause");
	return EXIT_SUCCESS;
}

