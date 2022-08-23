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

	//��Ԫ����
	friend Complex operator+(Complex& c1, Complex& c2);

	//���в���������
	Complex operator-(Complex& another)
	{
		int a = this->a - another.a;
		int b = this->b - another.b;
		Complex c3(a, b);
		return c3;
	}

private:
	int a;
	int b;
};

//ȫ�ּӲ���������
Complex operator+(Complex& c1, Complex& c2)
{
	int a = c1.a + c2.a;
	int b = c1.b + c2.b;
	Complex c3(a, b);
	return c3; 
}

int main()
{
	Complex c1(10, 5);
	Complex c2(11, 6);
	c1.show();
	c2.show();

	//���
	Complex c3 = c1 + c2;//��ʽд��
	c3.show();
	c3 = operator+(c1, c2);//��ʾд��
	c3.show();

	//���
	Complex c4 = c1 - c2;
	c4.show();
	c4 = c1.operator-(c2);
	c4.show();

	return 0;
}