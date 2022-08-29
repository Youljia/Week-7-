#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	//����С����
	void operator()(int* arra, int len)
	{
		//���й鲢����
		merge_sort(arra, 0, len - 1, len);
		return;
	}
	void merge_sort(int* arra, int l, int r, int len)
	{
		if (r - l <= 15)
			insert_sort(arra, l, r);
			return;
		int mid = (l + r) / 2;
		merge_sort(arra, l, mid, len);
		merge_sort(arra, mid + 1, r, len);
		merge(arra, l, mid, r, len);
	}
	//��������
	void insert_sort(int* arra, int l, int r)
	{
		int i = l;
		for (i; i <= r; ++i)
		{
			int m = arra[i];
			for (int j = i; j-1 >= l; --j)
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
	//�ϲ�������������
	void merge(int* arra, int l, int mid, int r, int len)
	{
		//����if�����������Ż�
		//������ȫ����������������Լ�����������
		if (arra[mid] > arra[mid + 1])
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