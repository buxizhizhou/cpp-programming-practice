// W6-课程作业-2.2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/*下面程序的输出结果是：

destructor B

destructor A

请完整写出 class A。 限制条件：不得为 class A 编写构造函数。*/

#include <iostream>
using namespace std;
class A {
	// 在此处补充你的代码
public:
	virtual ~A() { cout << "destructor A" << endl; }
};
class B :public A {
public:
	~B() { cout << "destructor B" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	A * pa;
	pa = new B;
	delete pa;
	system("pause");
	return 0;
}

