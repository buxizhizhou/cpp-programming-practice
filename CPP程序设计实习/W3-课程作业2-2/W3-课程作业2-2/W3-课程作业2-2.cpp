//下面程序输出的结果是：0，5
#include <iostream>
using namespace std;
class A {
public:
	int val;
	// 在此处补充你的代码
	//所缺代码具有如下形式：
	//A(_________________){ val = n; }
	//________________ GetObj() {
	//	return _________________;
	//}
	A(int n = 0){ val = n; }
	int& GetObj(){
		return val;
	}
};
int main()  {
	A a;
	cout << a.val << endl;
	a.GetObj() = 5;
	cout << a.val << endl;
	system("pause");
	return 0;
}