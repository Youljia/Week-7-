#include<iostream>
using namespace std;

class Sqrt
{
public:
	int operator()(int value)
	{
		return value * value;
	}
};

int main()
{
	Sqrt s;
	//称s对象为伪函数或者仿函数
	int i = s(10);
	cout << i << endl;
	return 0;
}