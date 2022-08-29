#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//重载小括号
	void operator()(int* arra,int len)
	{
		//进行归并排序
		merge_sort(arra, 0, len - 1, len);
		return;
	}
	void merge_sort(int* arra, int l, int r, int len)
	{
		if (l >= r)
			return;
		int mid = (l + r) / 2;
		merge_sort(arra, l, mid, len);
		merge_sort(arra, mid + 1, r, len);
		merge(arra, l, mid, r,len);
	}
	//合并两个有序数组
	void merge(int* arra, int l, int mid, int r, int len)
	{
		int* arra_copy = new int [len];
		for (int x = 0; x < len; ++x)
		{
			arra_copy[x] = arra[x];
		}
		int i = l;
		int j = mid + 1;
		for (int t = l; t <= r; ++t)
		{
			if (i > mid)
			{
				arra[t] = arra_copy[j];
				++j;
			}
			else if (j > r)
			{
				arra[t] = arra_copy[i];
				++i;
			}
			else if (arra_copy[i] <= arra_copy[j])
			{
				arra[t] = arra_copy[i];
				++i;
			}
			else
			{
				arra[t] = arra_copy[j];
				++j;
			}
		}
	}
};
int main()
{
	int* p = new int[3];
	p[0] = 3;
	p[1] = 2;
	p[2] = 1;
	Solution s;
	s(p, 3);
	cout << p[0] << p[1] << p[2] << endl;

	return 0;
}