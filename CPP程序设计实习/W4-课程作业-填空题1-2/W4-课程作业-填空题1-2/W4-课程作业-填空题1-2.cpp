// W4-课程作业-填空题1-2.cpp : Defines the entry point for the console application.
/*
请写出被隐藏的部分。（您写的内容必须是能全部放进 MyInt类内部的，MyInt的成员函数里不允许使用静态变量）。

输入
无
输出
4,1
*/

#include "stdafx.h"

#include <iostream>
using namespace std;

class MyInt  {
	int nVal;
public:
	MyInt(int n) { nVal = n; }
	int ReturnVal() { return nVal; }
	// 在此处补充你的代码
	MyInt& operator-(int x)
	{
		nVal -= x;
		return *this;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	MyInt objInt(10);
	objInt - 2 - 1 - 3;
	cout << objInt.ReturnVal();
	cout << ",";
	objInt - 2 - 1;
	cout << objInt.ReturnVal();

	return 0;
}

