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
	//��s����Ϊα�������߷º���
	int i = s(10);
	cout << i << endl;
	return 0;
}