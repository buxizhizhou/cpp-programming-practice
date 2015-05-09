// W6-编程作业-魔兽世界终极版.cpp : Defines the entry point for the console application.
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

int wrlf[5];//dragon 、ninja、iceman、lion、wolf 的初始生命值
int wrgjl[5];//武士的初始攻击力
//string wrname[5] = { "dragon", "ninja", "iceman", "lion", "wolf" };
string wpname[3] = { "sword", "bomb", "arrow" };//武器名

//城市类型
class City
{
	int life;
	int flag;//旗子颜色，0为无旗，1为红旗，2为蓝旗
public:
	City(int lf = 0, int fg = 0): life(lf), flag(fg){}

	void setlf(int lf)
	{
		life = lf;
	}

	void setfg(int fg)
	{
		flag = fg;
	}
};

//武器的类定义
class Weapon
{

};

class Sword :public Weapon
{
	int gjl;
public:
	int getgjl()
	{
		return gjl;
	}
	void biandun()
	{
		gjl = gjl*0.8;
	}
	bool is_lost()//攻击力降为0时，视为失去sword
	{
		if (gjl <= 0) return true;
		else return false;
	}

	Sword(){}
	Sword(const Warrior &wr) :gjl()
	{

	}
};

class Arrow :public Weapon
{
	int gjl;
	int sytime;//已使用次数。使用3次后即被耗尽
public:
	void increasetime()
	{//增加使用次数
		sytime++;
	}
	bool is_lost()//是否使用了3次。使用3次后即被耗尽
	{
		if (sytime >= 3) return true;
		else return false;
	}
};

class Bomb :public Weapon
{

};

//武士的类定义
class Warrior
{
protected:
	int bh;//编号
	int life;//生命值
	string name;
	int gjl;//攻击力

public:
	Warrior(int bianhao=0, int lf = 0, int gl=0,string nm = "wolf") :bh(bianhao),life(lf), name(nm), gjl(gl) {}

	string get_name()
	{
		return name;
	}

	int get_life()
	{
		return life;
	}

	virtual ~Warrior() {}
};

class Drag :public Warrior
{
	//int wpno;//武器序号
	Weapon *wpno;
	double morale;//士气

public:
	Drag() {}

	Drag(int no,int lf,int gjl, double hd_sx_lf) :morale(hd_sx_lf / lf), Warrior(no,lf,gjl, "dragon") //第一个参数是它的生命元,第二个参数是武士编号,第三个参数是司令部剩余生命元
	{
		switch (no % 3)
		{
		case 0:
			wpno = new Sword();
			break;
		case 1:
			wpno = new Bomb();
			break;
		case 2:
			wpno = new Arrow();
			break;
		}
	}

	virtual ~Drag()
	{
		delete wpno;
	}

	void increaseml()
	{
		morale += 0.2;
	}

	void decreaseml()
	{
		morale -= 0.2;
	}

	bool is_dead()//生命值不大于0时，武士死亡
	{
		if (get_life() <= 0) return true;
		else return false;
	}

	bool is_huanhu()//是否欢呼。主动进攻结束后，喂战死且士气值大于0.8
	{
		if (is_dead() == false && morale > 0.8)  return true;
		else return false;
	}
};

class Nin :public Warrior   //从不反击
{
	//int wpno1;
	//int wpno2;
	Weapon * wpno[2];

public:
	Nin(){}
	Nin(int no,int lf,int gjl) : Warrior(no,lf,gjl, "ninja")//第一个参数是武士的生命元，第二个参数是其编号
	{
		switch(no % 3)
		{
		case 0:
			wpno[0] = new Sword();
			wpno[1] = new Bomb();
			break;
		case 1:
			wpno[0] = new Bomb();
			wpno[1] = new Arrow();
			break;
		case 2:
			wpno[0] = new Arrow();
			wpno[1] = new Sword();
		}
	}

	virtual ~Nin()
	{
		delete [] wpno;
	}
};

class Ice :public Warrior
{
	//int wpno;
	Weapon *wp;

public:
	Ice(){}
	Ice(int no, int lf, int gjl) :Warrior(no, lf, gjl, "iceman")
	{
		switch (no%3)
		{
		case 0:
			wp = new Sword();
			break;
		case 1:
			wp = new Bomb();
			break;
		case 2:
			wp = new Arrow();
			break;
		}
	}

	void steptwo()
	{
		//int lf = get_life();
		if (life - 9 <= 0)
		{
			life = 1;
		}
		else{
			life -= 9;
		}
		gjl += 20;
	}
};

class Lion :public Warrior
{
	int loyalty;//忠诚度

public:
	Lion(){}
	Lion(int no,int lf,int gjl,int hd_sx_lf) :loyalty(hd_sx_lf), Warrior(no,lf,gjl, "lion") {}

	void decreaselylt(int k)
	{
		loyalty -= k;
	}

	bool is_escape()//是否能逃跑。忠诚度降至0或0以下，逃离战场。
	{
		if (loyalty <= 0) return true;
		else return false;
	}
};

class Wolf :public Warrior
{
	Weapon *wp[3];
public :
	Wolf(int no, int lf, int gjl) : Warrior(no, lf, gjl, "Wolf")
	{
		for (int i = 0; i < 3; ++i)
			wp[i] = NULL;
	}

	void jiaohuo(int n)//缴获编号为n的武器
	{
		if (wp[i] == NULL)//只有当没有这个武器时，才会缴获
		{
			wp[i]
		}
	}
};

class HeadQ
{
	int lifen;//生命元
	int wno;//武士的最大编号
	int worrior[5];//5个武士依次的数量
	string name;
	//bool stop;//是否停止制造武士
	Warrior *wrs[100];//该司令部的武士,5000/60<=100
	int len;//含有的武士数量，即wrs的最大有效下标

public:
	HeadQ(int lfn = 0,string snm = "") :lifen(lfn), wno(0), name(snm), len(0)
	{
		memset(worrior, 0, sizeof(worrior));
	}

	bool is_enough(int k)//生命元是否足够生成编号为k的武士
	{
		if (lifen < wrlf[k]) return false;
		else return true;
	}

	bool gen_wr(int time, int k)//生成序号为k的武士
	{
		wno++;
		worrior[k]++;
		lifen = lifen - wrlf[k];//剩余生命元

		if (0 == k)
		{
			wrs[len++] = new Drag(wno,wrlf[k],wrgjl[k],lifen);
		}
		else if (1 == k)
		{
			wrs[len++]=new Nin(wno,wrlf[k],wrgjl[k]);
		}
		else if (2 == k)
		{
			wrs[len++] = new Ice(wno,wrlf[k],wrgjl[k]);
		}
		else if (3 == k)
		{
			wrs[len++] = new Lion(wno,wrlf[k],wrgjl[k],lifen);
		}
		else if (4 == k)
		{
			wrs[len++] = new Wolf(wno,wrlf[k],wrgjl[k]);
			//cout.fill('0');//设置填充字符，一直有效
			//cout.width(3);//设域宽为3，一次有效
		}
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

City cities[20 + 2];

int _tmain(int argc, _TCHAR* argv[])
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case:" << i << endl;
		int m, n, r, k, t;
		cin >> m >> n >> r >> k >> t;
		for (int j = 0; j < 5; ++j)
			cin >> wrlf[j];
		for (int j = 0; j < 5; ++j)
			cin >> wrgjl[j];
		
		HeadQ hdq[2] = {HeadQ(m,"red"),HeadQ(m,"blue")};
		int xhlen1 = 0, xhlen2 = 0;//两个司令部制造武士的序号
		int xhxb1[] = { 2, 3, 4, 1, 0 };//制造武士顺序的下标序列
		int xhxb2[] = { 3, 0, 1, 2, 4 };
		for(int j = 0; j <= t; j=j+5)//时间增长
		{
			int minute = j % 60;//分钟
			if (0 == minute)
			{
				int k1 = xhxb1[xhlen1 % 5];
				if (hdq[0].is_enough(k1))
				{
					hdq[0].gen_wr(k1);
					xhlen1++;
				}
				int k2 = xhxb2[xhlen2 % 5];
				if (hdq[1].is_enough(k2))
				{
					hdq[1].gen_wr(k2);
					xhlen2++;
				}
			}
			else if (5 == minute)
			{
				for (int )
			}
		}
	}
	return 0;
}





