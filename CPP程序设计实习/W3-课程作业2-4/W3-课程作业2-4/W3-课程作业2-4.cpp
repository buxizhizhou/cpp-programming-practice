// W3-课程作业2-4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//下面程序的输出结果是：
//5, 5
//5, 5
//请填空：

#include <iostream>
using namespace std;
class Base {
public:
	int k;
	Base(int n) :k(n) { }
};
class Big  {
public:
	int v; Base b;
	// 在此处补充你的代码
	//Big ________________{}
	//Big ________________{}
	Big(int n) :v(n), b(n) {}
	
	Big(const Big& a) :v(a.v), b(a.b)
	{
		//v = a.v;
		//b = a.b;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Big a1(5);    
	Big a2 = a1;
	cout << a1.v << "," << a1.b.k << endl;
	cout << a2.v << "," << a2.b.k << endl;
	system("pause");
	return 0;
}

