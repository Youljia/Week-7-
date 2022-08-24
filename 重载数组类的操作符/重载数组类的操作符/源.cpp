#include<iostream>
using namespace std;

class Array
{
public:
	Array(int len)
	{
		this->len = len;
		space = new int[len];
		size = 0;
	}

	//深拷贝
	Array(Array& another)
	{
		this->len = another.len;
		this->size = another.size;
		this->space = new int[len];
	}

	~Array()
	{
		cout << "is releasing... ..." << endl;
		if (space != NULL)
		{
			delete[]space;
			space = NULL;
			len = NULL;
		}
	}

	void set_data(int e)
	{
		space[size] = e;
		size++;
	}

	int get_data(int index)
	{
		return space[index];
	}

	int get_size()
	{
		return size;
	}

	void show()
	{
		cout << "Array:[";
		for (int i = 0; i < size; ++i)
		{
			cout << space[i];
			if (i != size - 1)
				cout << " , ";
		}
		cout << "]" << endl;
	}

	//重载取值操作符[]
	int operator[](int i)
	{
		return this->space[i];
	}

	//重载==操作符
	bool operator==(Array& another)
	{
		if (this->size == another.size)
		{
			for (int i = 0; i < size; ++i)
			{
				if (this->space[i] != another.space[i])
					return false;
			}
			return true;
		}
		else
			return false;
	}

	//友元函数
	friend ostream& operator<<(ostream& co, Array& array);
	friend istream& operator>>(istream& ci, Array& array);

private:
	int len;
	int size;
	int* space;
};

//重载<<操作符
ostream& operator<<(ostream& co, Array& array)
{
	co << "Array:[";
	for (int i = 0; i < array.size; ++i)
	{
		co << array.space[i];
		if (i != array.size - 1)
			cout << " , ";
	}
	co << "]" << endl;
	return co;
}

//重载>>操作符
istream& operator>>(istream& ci, Array& array)
{
	int size;
	cout << "请输入元素个数！" << endl;
	cin >> size;
	cout << "请开始输入" << endl;
	for (int i = 0; i < size; ++i)
	{
		int j;
		cin >> j;
		array.set_data(j);
	}
	return ci;
}

int main()
{
	Array array(10);
	Array array1(10);
	cin >> array;
	cout << array;
	cin >> array1;
	cout << array1;

	cout << array[1] << endl;

	if (array == array1)
	{
		cout << "两个数组相等！" << endl;
	}
	else
		cout << "两个数组不相等！" << endl;



	return 0;
}