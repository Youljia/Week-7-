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
	friend ostream& operator<<(ostream& co, Complex& c);
	//���Ʋ���������
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

//ȫ�����Ʋ���������
ostream& operator<<(ostream& co, Complex& c)
{
	co << "< " << c.a << " , " << c.b << "i >" << endl;
	return co;
}

int main()
{
	Complex c1(10, 20);
	cout << c1 << endl;

	//cin >> c1;//����
	c1.operator>>(cin);//��ʾд������
	c1 >> cin;//��ʽд����������ˣ�����ȡ��
	return 0;
}