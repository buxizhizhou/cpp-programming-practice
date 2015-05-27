// W4-编程作业-大整数的加减乘除.cpp : Defines the entry point for the console application.
/*
给出两个正整数以及四则运算操作符（+ - * /），求运算结果。

输入
第一行：正整数a，长度不超过100
第二行：四则运算符o，o是“+”，“-”，“*”，“/”中的某一个
第三行：正整数b，长度不超过100

保证输入不含多余的空格或其它字符
输出
一行：表达式“a o b”的值。

补充说明：
1. 减法结果有可能为负数
2. 除法结果向下取整
3. 输出符合日常书写习惯，不能有多余的0、空格或其它字符
样例输入
9876543210
+
9876543210
样例输出
19753086420
*/

//!!!没有AC，基本没做。

#include "stdafx.h"

#define MAXN 100

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

struct bign
{
	int len, s[MAXN];
	bign(){ memset(s, 0, sizeof(s)); len = 1; }
	bign(const bign& c)
	{
		*this = c;
	}
	bign(const char* num){ *this = num; }

	void clean()
	{//去除前导0   
		while (len>1 && !s[len - 1]) len--;
	}

	string str() const
	{
		string res = "";
		for (int i = 0; i<len; ++i) res = (char)(s[i] + '0') + res;
		return res;
	}

	bign operator=(const bign &b)
	{
		len = b.len;
		for (int i = 0; i<MAXN; ++i)
			s[i] = b.s[i];

		return *this;
	}

	bign operator=(const char *num)
	{
		len = strlen(num);
		for (int i = 0; i<len; ++i) s[i] = num[len - 1 - i] - '0';
		return *this;
	}

	bign operator+(const bign &b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; i<max(len, b.len) || g; ++i)
		{
			int x = g;
			if (i<len) x += s[i];
			if (i<b.len) x += b.s[i];
			c.s[c.len++] = x % 10;
			g = x / 10;
		}
		return c;
	}

	bign operator-(const bign& b) const
	{
		bign c;
		c.len = 0;
		for (int i = 0, g = 0; i<len; ++i)
		{
			int x = s[i] - g;
			if (i<b.len) x = x - b.s[i];
			if (x<0)
			{
				x = x + 10;
				g = 1;
			}
			else g = 0;
			c.s[c.len++] = x;
		}//for      
		c.clean();//去除前导0   
		return c;
	}

	bign operator/(const bign& b) const
	{
		bign c = *this;
		bign s;//商   
		for (int i = len - b.len; i >= 0; --i)
		{
			bign d = b.scale(i);
			int n = 0;
			while (c >= d)
			{
				c = c - d;
				n = n + 1;
			}
			s.s[i] = n;
		}//for   
		return s;
	}

	bign scale(int n) const
	{//把该数扩大n倍，即在该数尾部添n个0   
		string s = (*this).str();
		string ts(n, '0');
		s = s + ts;
		return bign(s.c_str());
	}

	bign operator%(const bign& b) const
	{
		bign c = *this;
		for (int i = len - b.len; i >= 0; --i)
		{
			bign d = b.scale(i);
			while (c >= d)
			{
				c = c - d;
			}
		}//for   
		return c;
	}

	bool operator<(bign& b)
	{//该函数首先调用clean函数去除前导0，所以可能改变bign变量   
		clean();
		b.clean();
		if (len != b.len) return len<b.len;
		for (int i = len - 1; i >= 0; --i)
			if (s[i] != b.s[i]) return s[i]<b.s[i];
		return false;
	}

	bool operator>=(bign &b)
	{
		return !(*this<b);
	}

	bign operator * (const bign& b) {
		bign c; c.len = len + b.len;
		for (int i = 0; i < len; i++)
			for (int j = 0; j < b.len; j++)
				c.s[i + j] += s[i] * b.s[j];
		for (int i = 0; i < c.len - 1; i++){
			c.s[i + 1] += c.s[i] / 10;
			c.s[i] %= 10;
		}
		c.clean();
		return c;
	}

};

istream& operator>>(istream& in, bign& x)
{
	string s;
	cin >> s;
	x = s.c_str();
	return in;
}

ostream& operator<<(ostream& out, const bign& x)
{
	out << x.str();
	return out;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//freopen("C:\\Users\\hello\\Documents\\Visual Studio 2013\\Projects\\cpp-programming-practice\\OJ-AC-code\\4bign-in.txt", "r", stdin);

	bign a, b;
	char c;
	cin >> a >> c >> b;
	//cout << "a:" << a << "o:" << c << "b:" << b << endl;
	if (c == '+') cout << a + b << endl;
	else if (c == '-')
	{
		if (b<a) cout << a - b << endl;
		else if(a<b) cout <<"-"<< b - a << endl;
		else cout << "0" << endl;
	}
	else if (c == '*') cout << a*b << endl;
	else if (c == '/') cout << a / b << endl;

	return 0;
}

