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
	friend Complex& operator+=(Complex& c1, Complex& c2);
	//类中-=重载函数
	Complex& operator-=(Complex& another)
	{
		this->a -= another.a;
		this->b -= another.b;
		return *this;
	}
private:
	int a;
	int b;
};

//全局+=重载函数
Complex& operator+=(Complex& c1,Complex& c2)
{
	c1.a += c2.a;
	c1.b += c2.b; 
	return c1;
}

int main()
{
	Complex c1(10, 20);
	Complex c2(11, 21);
	c1.show();
	c2.show();

	//加等
	for (int i = 0; i < 2; ++i)
	{
		c1 += c2;
	}
	c1.show();
	c2.show();

	//减等
	for (int i = 0; i < 2; ++i)
	{
		c1 -= c2;
	}
	c1.show();
	c2.show();
	return 0;
}
