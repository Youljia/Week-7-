#include<iostream>
using namespace std;

class Sum
{
public:
	int operator()(int* array,int len)
	{
		return sum(array, len, 0);
	}

	int sum(int* array,int len, int l)
	{
		if (l == len)
			return 0;
		else
			return array[l] + sum(array, len, l + 1);
	}
};

 void main()
{
	int* array = new int[10];
	for (int i = 0; i < 10; ++i)
		array[i] = i;

	Sum s;
	int a = s(array, 10);
	cout << a << endl;
}