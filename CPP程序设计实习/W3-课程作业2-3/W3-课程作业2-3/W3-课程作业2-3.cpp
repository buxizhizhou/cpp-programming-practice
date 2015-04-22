// W3-课程作业2-3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//下面程序的输出是：10
//请补足Sample类的成员函数。不能增加成员变量。

#include <iostream>
using namespace std;
class Sample{
public:
	int v;
	Sample(int n) :v(n) { }
	// 在此处补充你的代码
	Sample(const Sample& a)
	{
		v = a.v*2;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Sample a(5);
	Sample b = a;
	cout << b.v;
	system("pause");
	return 0;
}

