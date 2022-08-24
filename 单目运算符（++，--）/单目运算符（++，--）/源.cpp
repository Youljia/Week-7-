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

	//�Լ�--a
	Complex& operator--()
	{
		this->a -= 1;
		return *this;
	}
	//�Լ�a--
	Complex operator--(int)
	{
		Complex temp = *this;
		this->a -= 1;
		return temp;
	}

	//��Ԫ����
	friend Complex& operator++(Complex& c1);
	friend const Complex& operator++(Complex& c1, int);
private:
	int a;
	int b;
};

//����++a
Complex& operator++(Complex& c1)
{
	c1.a += 1;
	return c1;
}
//����a++
const Complex& operator++(Complex& c1,int)
{
	Complex temp = c1;
	c1.a += 1;
	return temp;
}

int main()
{
	int a = 1;
	//a++++;
	++++a;

	Complex c1(10, 20);
	c1.show();

	Complex c3 = operator++(c1,1);
	c3.show();
	c1.show();

	++c1;
	c1.show();

	++++c1;
	c1.show();
	return 0;
}