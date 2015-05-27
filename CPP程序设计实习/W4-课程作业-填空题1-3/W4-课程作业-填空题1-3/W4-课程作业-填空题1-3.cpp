// W4-课程作业-填空题1-3.cpp : Defines the entry point for the console application.
/*
写一个二维数组类 Array2,使得下面程序的输出结果是：
输入
无
输出
0, 1, 2, 3,
4, 5, 6, 7,
8, 9, 10, 11,
next
0, 1, 2, 3,
4, 5, 6, 7,
8, 9, 10, 11,
*/

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;
// 在此处补充你的代码
class Array2
{
private:
	int hang, lie;
	int **iar;
public:
	Array2() :hang(0), lie(0), iar(NULL) {}
	Array2(int h, int l) :hang(h), lie(l)
	{
		iar = new int*[h];
		iar[0] = new int[h*l];
		for (int i = 1; i < h; ++i)
			iar[i] = iar[i - 1] + l;
	}
	~Array2()
	{
		//cout << "";
		if (iar != NULL)
		{
			delete[] iar[0];  //delete的方式要对，不然就会出现_Block_Type_Is_Valid (pHead->nBlockUse) Error
			delete[] iar;
		}
	}
	int*& operator[](int m)
	{
		return iar[m];
	}
	const int operator() (int m, int n)
	{
		return iar[m][n];
	}
	Array2& operator=(const Array2& ar)
	{
		if (ar.iar == iar) return *this;
		if (iar != NULL)
		{
			for (int i = 0; i < hang; ++i)
				delete[] iar[i];
			delete[] iar;
		}
		if (ar.iar != NULL)
		{
			hang = ar.hang;
			lie = ar.lie;
			iar = new int*[hang];
			iar[0] = new int[hang*lie];
			for (int i = 1; i < hang; ++i)
				iar[i] = iar[i - 1] + lie;
			for (int i = 0; i < hang; ++i)
				for (int j = 0; j < lie; ++j)
					iar[i][j] = ar.iar[i][j];
		}
		else
		{
			hang = 0;
			lie = 0;
			iar = NULL;
		}
		return *this;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Array2 a(3, 4);
	int i, j;
	for (i = 0; i < 3; ++i)
		for (j = 0; j < 4; j++)
			a[i][j] = i * 4 + j;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << a(i, j) << ",";
		}
		cout << endl;
	}
	cout << "next" << endl;
	Array2 b;     
	b = a;
	for (i = 0; i < 3; ++i) {
		for (j = 0; j < 4; j++) {
			cout << b[i][j] << ",";
		}
		cout << endl;
	}

	return 0;
}

