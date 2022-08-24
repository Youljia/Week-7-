#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	void show()
	{
		cout << "< " << a << " , " << b << "i >" << endl;
	}
	//友元函数
	friend ostream& operator<<(ostream& co, Complex& c);
	//右移操作符重载
	istream& operator>>(istream& ci)
	{
		cout << "a = " << endl;
		ci >> this->a;
		cout << "b = " << endl;
		ci >> this->b;
		return ci;
	}

private:
	int a;
	int b;
};

//全局左移操作符重载
ostream& operator<<(ostream& co, Complex& c)
{
	co << "< " << c.a << " , " << c.b << "i >" << endl;
	return co;
}

int main()
{
	Complex c1(10, 20);
	cout << c1 << endl;

	//cin >> c1;//报错！
	c1.operator>>(cin);//显示写法可以
	c1 >> cin;//隐式写法，含义变了，不可取！
	return 0;
}