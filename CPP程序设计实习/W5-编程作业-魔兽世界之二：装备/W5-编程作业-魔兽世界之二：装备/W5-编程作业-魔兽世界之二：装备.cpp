// W5-编程作业-魔兽世界之二：装备.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using std::cin;
using std::string;
using std::cout;
using std::endl;
using std::ios_base;
//using namespace std;

int wlf[5];//dragon 、ninja、iceman、lion、wolf 的初始生命值
//string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string wpname[3] = { "sword","bomb","arrow" };//武器名

class Warrior
{
	int life;
	string name;

public:
	Warrior(int lf = 0, string nm="wolf") :life(lf),name(nm) {}

	string get_name()
	{
		return name;
	}

	int get_life()
	{
		return life;
	}
};

class Drag :public Warrior
{
	int wpno;//武器序号
	double morale;//士气

public:
	Drag() {}

	Drag(int lf, int no, double hd_sx_lf) :wpno(no%3), morale(hd_sx_lf/lf), Warrior(lf, "dragon") //第一个参数是它的生命元,第二个参数是编号,第三个参数是司令部剩余生命元
	{}

	void show()
	{
		cout << "It has a " << wpname[wpno] << ",and it's morale is ";
		cout.setf(ios_base::fixed, ios_base::floatfield);//设置使用定点表示法
		cout.precision(2);//对于定点表示法，精度为2表示小数点后有2位，一直有效
		cout<< morale << endl;
	}

};

class Nin :public Warrior
{
	int wpno1;
	int wpno2;

public:
	Nin(){}
	Nin(int lf, int no) :wpno1(no%3), wpno2((no+1)%3), Warrior(lf, "ninja") {}//第一个参数是武士的生命元，第二个参数是其编号

	void show()
	{
		cout << "It has a "<<wpname[wpno1]<<" and a "<<wpname[wpno2] << endl;
	}
};

class Ice :public Warrior
{
	int wpno;

public:
	Ice(){}
	Ice(int lf, int no) :wpno(no%3), Warrior(lf, "iceman") {}

	void show()
	{
		cout << "It has a "<<wpname[wpno] << endl;
	}
};

class Lion :public Warrior
{
	int loyalty;//忠诚度

public:
	Lion(){}
	Lion(int lf, int hd_sx_lf) :loyalty(hd_sx_lf), Warrior(lf, "lion") {}

	void show()
	{
		cout << "It's loyalty is "<<loyalty << endl;
	}
};

class HeadQ
{
	int lifen;//生命元
	int wno;//武士的最大编号
	int worrior[5];//5个武士依次的数量
	string name;
	bool stop;//是否停止制造武士

public:
	HeadQ(int lfn = 0, string snm = "") :lifen(lfn), wno(0), name(snm), stop(0)
	{
		memset(worrior, 0, sizeof(worrior));
	}

	bool gen_wr(int time, int k)//生成序号为k的武士
	{
		if (lifen < wlf[k])
		{
			return false;
		}
		wno++;
		worrior[k]++;
		lifen = lifen - wlf[k];//剩余生命元
		
		if (0 == k)
		{
			Drag drg(wlf[k],wno,lifen);
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout <<time << " " << name << " " << drg.get_name() << " " << wno << " born with strength " << drg.get_life()
				<<","<<worrior[k] <<" "<<drg.get_name()<<" in "<<name<<" headquarter" << endl;
			drg.show();
		}
		else if (1 == k)
		{
			Nin nnj(wlf[k],wno);
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " " << nnj.get_name() << " " << wno << " born with strength " << nnj.get_life()
				<< "," << worrior[k] << " " << nnj.get_name() << " in " << name << " headquarter" << endl;
			nnj.show();
		}
		else if (2 == k)
		{
			Ice icm(wlf[k],wno);
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " " << icm.get_name() << " " << wno << " born with strength " << icm.get_life()
				<< "," << worrior[k] << " " << icm.get_name() << " in " << name << " headquarter" << endl;
			icm.show();
		}
		else if (3 == k)
		{
			Lion lon(wlf[k],lifen);
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " " << lon.get_name() << " " << wno << " born with strength " << lon.get_life()
				<< "," << worrior[k] << " " << lon.get_name() << " in " << name << " headquarter" << endl;
			lon.show();
		}
		else if (4 == k)
		{
			//没有特别的
			Warrior wlf(wlf[k]);
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " " << wlf.get_name() << " " << wno << " born with strength " << wlf.get_life()
				<< "," << worrior[k] << " " << wlf.get_name() << " in " << name << " headquarter" << endl;
		}
		return true;
	}

	bool is_stop(int time)
	{
		bool flag = 0;//标志是否可以继续制造武士
		for (int i = 0; i < 5; ++i)
		{
			if (lifen >= wlf[i]) { flag = 1; break; }//只要还可以制造一个武士
		}
		if (flag == 0)
		{
			cout.fill('0');//设置填充字符，一直有效
			cout.width(3);//设域宽为3，一次有效
			cout << time << " " << name << " headquarter stops making warriors" << endl;
			stop = true;
			return true;
		}
		return false;
	}

	bool getstopflag(void)
	{
		return stop;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cout << "Case:" << i << endl;
		int m;
		cin >> m;
		cin >> wlf[0] >> wlf[1] >> wlf[2] >> wlf[3] >> wlf[4];
		HeadQ redhq(m, "red");//红方按iceman、lion、wolf、ninja、dragon顺序:2,3,4,1,0
		HeadQ bluehq(m, "blue");//蓝方按lion、dragon、ninja、iceman、wolf顺序:3,0,1,2,4
		int redsx[5] = { 2, 3, 4, 1, 0 };
		int bluesx[5] = { 3, 0, 1, 2, 4 };

		int time = 0;
		int redk = 0;
		int bluek = 0;
		while (redhq.getstopflag() == false || bluehq.getstopflag() == false)
		{
			while (redhq.getstopflag() == false && redhq.is_stop(time) == false && redhq.gen_wr(time, redsx[redk]) == false)//当没有停止生成武士且生成武士失败时，生成下一个可生成的武士
			{
				redk = (redk + 1) % 5;
			}
			redk = (redk + 1) % 5;

			while (bluehq.getstopflag() == false && bluehq.is_stop(time) == false && bluehq.gen_wr(time, bluesx[bluek]) == false)//当没有停止生成武士且生成武士失败时，生成下一个可生成的武士
			{
				bluek = (bluek + 1) % 5;
			}
			bluek = (bluek + 1) % 5;

			time++;
		}
	}
	return 0;
}



