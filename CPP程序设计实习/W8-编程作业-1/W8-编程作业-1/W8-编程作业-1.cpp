// W8-编程作业-1.cpp : Defines the entry point for the console application.
/*写一个程序完成以下命令：
    new id ——新建一个指定编号为id的序列(id<10000)
	add id num ——向编号为id的序列加入整数num
	merge id1 id2 ——合并序列id1和id2中的数，并将id2清空
	unique id ——去掉序列id中重复的元素
	out id ——从小到大输出编号为id的序列中的元素，以空格隔开

输入
	第一行一个数n，表示有多少个命令(n＜＝２０００００)。以后n行每行一个命令。*/

/*
  思考：out的时候需要是有序的，可以序列本身是有序，或输出前sort一下
       unique不能作用于关联容器，所以序列就不能是set之类的关联容器
	   merge作用于有序区间，如果序列本身不是有序的，那merge之前需要sort一下
	   
	   还是有问题，因为unique并不是真正的删除，就算用一个迭代器标志位置还是会有问题。
	   额，还是可以的，先unique，然后erase
*/

#include "stdafx.h"
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("C:\\Users\\hello\\Documents\\Visual Studio 2013\\Projects\\cpp-programming-practice\\OJ-AC-code\\8list-in.txt","r",stdin);

	int n;
	cin >> n;
	//cout << n << endl;
	map<int,vector<int> > xulie;
	//map<int, vector<int>::iterator > xlit;//保存有效元素的下一个位置，考虑到unique不能真正删除的原因
	while (n-- > 0)
	{
		string sml;
		cin >> sml;
		if (sml == "new")
		{
			int id;
			cin >> id;
			xulie[id];
		}
		else if (sml == "add")
		{
			int id, num;
			cin >> id >> num;
			//xulie[id].insert(num);
			xulie[id].push_back(num);
		}
		else if (sml == "merge")
		{
			int id1, id2;
			cin >> id1 >> id2;
			if (id1 == id2) continue;  //！！！注意这个
			//xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			/*sort(xulie[id1].begin(),xulie[id1].end());
			sort(xulie[id2].begin(), xulie[id2].end());
			xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			merge(xulie[id1].begin(),xulie[id1].end(),xulie[id2].begin(),xulie[id2].end(),xulie[id1].begin());//两个区间必须是有序的 */
			
			vector<int> vtmp(xulie[id1].begin(),xulie[id1].end());
			sort(vtmp.begin(),vtmp.end());
			sort(xulie[id2].begin(), xulie[id2].end());
			xulie[id1].clear();
			xulie[id1].resize(xulie[id1].size() + xulie[id2].size());
			merge(vtmp.begin(),vtmp.end(),xulie[id2].begin(),xulie[id2].end(),xulie[id1].begin());//两个区间必须是有序的
			xulie[id2].clear();
		}
		else if (sml == "unique")
		{
			int id;
			cin >> id;
			sort(xulie[id].begin(),xulie[id].end());
			vector<int>::iterator newend=unique(xulie[id].begin(),xulie[id].end());//删除算法不应作用于关联容器
			xulie[id].erase(newend,xulie[id].end());
			/*if (xulie[id].empty() == false)
			{
				for (vector<int>::iterator it = xulie[id].end()-1; it != xulie[id].begin(); --it)
				{
					if (*it == *(it - 1)) xulie[id].erase(it);
				}
			}*/
		}
		else if (sml == "out")
		{
			int id;
			cin >> id;
			sort(xulie[id].begin(), xulie[id].end());
			for (vector<int>::iterator it = xulie[id].begin(); it != xulie[id].end(); ++it)
			{
				cout << *it << " ";
			}
			cout << endl;

		}
	}

	return 0;
}

