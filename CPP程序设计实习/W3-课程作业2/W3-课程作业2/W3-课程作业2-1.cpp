// W3-课程作业2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A {
	int val;
public:
	A(int n) { val = n; }
	int GetVal() { return val; }
};
class B : public A {
private:
	int val;
public:
	B(int n) :
		// 在此处补充你的代码
		val(2 * n), A(3*n)
	{ }
	int GetVal() { return val; }
};

//下面程序输出的结果是：4, 6
int _tmain(int argc, _TCHAR* argv[])
{
	B b1(2);
	cout << b1.GetVal() << "," << b1.A::GetVal() << endl;
	system("pause");
	return 0;
}

