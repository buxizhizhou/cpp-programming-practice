// WEEK8-课程作业-填空题1-1.cpp : Defines the entry point for the console application.
//
//输入
//无
//输出
//1 2 6 7 8 9

#include "stdafx.h"
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = { 8, 7, 8, 9, 6, 2, 1 };
	// 在此处补充你的代码
	set<int> v(a,a+7);   //此题主要考察set容器，set容器这样的初始化，有序且不重复。

	ostream_iterator<int> o(cout, " ");
	copy(v.begin(), v.end(), o);

	system("pause");
	return 0;
}

