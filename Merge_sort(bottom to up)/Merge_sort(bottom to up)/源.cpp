#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//重载小括号
	void operator()(int* arra, int len)
	{
		//进行归并排序
		merge_sort(arra, len);
		return;
	}

	void merge_sort(int* arra, int len)
	{
		//遍历所有size的可能情况
		for (int sz = 1; sz < len; sz += sz)
		{
			//插入排序法
			if (sz < 2)
			{
				//对[j,j+size-1]进行插入排序
				for (int j = 0; j < len; j += sz)
				{
					insert_sort(arra,j, j + sz - 1);
				}
			}
			//归并[i,size+i-1]和[i+size,i+size+size-1]
			for (int i = 0; i + sz < len; i += (sz + sz))
			{
				if (arra[sz + i - 1] > arra[i + sz])
				{
					int r = i + sz + sz - 1 > len - 1 ? len - 1 : i + sz + sz - 1;
					merge(arra, i, i + sz - 1, r, len);
				}
			}
		}
	}
	//插入排序法
	void insert_sort(int* arra, int l, int r)
	{
		int i = l;
		for (i; i <= r; ++i)
		{
			int m = arra[i];
			for (int j = i; j - 1 >= l; --j)
			{
				if (arra[j - 1] > m)
				{
					arra[j] = arra[j - 1];
					arra[j - 1] = m;
				}
				else
					break;
			}
		}
	}
	//合并两个有序数组
	void merge(int* arra, int l, int mid, int r, int len)
	{
		int* arra_copy = new int[len];
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
	int* p = new int[6];
	p[0] = 3;
	p[1] = 2;
	p[2] = 1;
	p[3] = 0;
	p[4] = 6;
	p[5] = 7;
	Solution s;
	s(p, 6);
	cout << p[0] << p[1] << p[2] << p[3] << p[4] << p[5] << endl;

	return 0;
}