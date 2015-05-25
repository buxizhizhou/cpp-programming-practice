// W2-简单的学生信息处理程序实现.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<string>

#define MAXLEN 20

class Student
{
	std::string name;
	int age;
	std::string xueno;
	int avgsc1, avgsc2, avgsc3, avgsc4;

public:
	
	Student(std::string nm, int ag, std::string xh, int avg1, int avg2, int avg3, int avg4)
	{
		name = nm;
		age = ag;
		xueno = xh;
		avgsc1 = avg1;
		avgsc2 = avg2;
		avgsc3 = avg3;
		avgsc4 = avg4;
	}

	Student(){}

	std::string getname()
	{
		return name;
	}

	std::string getxh()
	{
		return xueno;
	}

	int getage()
	{
		return age;
	}

	int getavg()
	{
		return (avgsc1 + avgsc2 + avgsc3 + avgsc4) / 4;
	}
};

//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	char nm[MAXLEN];
	int ag;
	char xh[MAXLEN];
	int sc1, sc2, sc3, sc4;
	scanf("%[^,],%d,%[^,],%d,%d,%d,%d",nm,&ag,xh,&sc1,&sc2,&sc3,&sc4);
	Student s (std::string(nm),ag,std::string(xh),sc1,sc2,sc3,sc4);
	printf("%s,%d,%s,%d\n", s.getname().c_str(), s.getage(), s.getxh().c_str(),s.getavg());
	//system("pause");
	return 0;
}