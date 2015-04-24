// W6-课程作业2-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//下面程序的输出结果是：

//A::Fun

//C::Do

//请填空：

#include <iostream>
using namespace std;
class A {
private:
	int nVal;
public:
	void Fun()
	{
		cout << "A::Fun" << endl;
	}
	void Do()
	{
		cout << "A::Do" << endl;
	}
};
class B :public A {
public:
	virtual void Do()
	{
		cout << "B::Do" << endl;
	}
};
class C :public B {
public:
	void Do()
	{
		cout << "C::Do" << endl;
	}
	void Fun()
	{
		cout << "C::Fun" << endl;
	}
};
void Call(
	 B &p                           // 在此处补充你的代码
	)  
{
	p.Fun();  p.Do();
}

int _tmain(int argc, _TCHAR* argv[])
{
	C c;    Call(c);
	system("pause");
	return 0;
}

