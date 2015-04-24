// W6-课程作业-2.3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*输出
A::Fun
A::Do
A::Fun
C::Do*/
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
	virtual void Do()
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
	A *p               // 在此处补充你的代码
	)  {
	p->Fun();  p->Do();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Call(new A());
	Call(new C());
	system("pause");
	return 0;
}

