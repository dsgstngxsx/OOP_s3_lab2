#include <string>
#include <iostream>

using namespace std;

class COne //1 �����
{
private:
	double d;
	string s;

public:

	//����������� ���������
	COne() {}
	//����������� � �����������
	COne(double d, string s) : d(d), s(s) {}
	//����������� �����������
	COne(const COne& copy) : d(copy.d), s(copy.s) {}
	//����������
	~COne() 
	{
		cout << "Destructor COne:" << endl;
		cout << "d = " << d << " deleted" << endl;
		cout << "s = " << s << " deleted" << endl;
	}
	//�������� ������������
	COne& operator=(const COne& copy) {
		if (this != &copy) {
			d = copy.d;
			s = copy.s;
		}
		return *this;
	}
	//������ �������
	double get_d() const 
	{ 
		return d; 
	}
	string get_s() const 
	{ 
		return s; 
	}
	//����� �� �����
	void print() const
	{
		cout << "COne: d = " << d << ", s = " << s;
	}
};

class CTwo //2 �����
{
private:
	double d;
	COne* p;

public:

	//����������� ���������
	CTwo() {}
	//����������� � �����������
	CTwo(double d, COne* p) : d(d), p(p) {}
	//����������� �����������
	CTwo(const CTwo& copy) : d(copy.d), p(new COne(*copy.p)) {}
	//����������
	~CTwo()
	{
		cout << "Destructor CTwo:" << endl;
		cout << "d = " << d << " deleted" << endl;
		cout << "&p = " << p << " deleted" << endl;
	}
	//�������� ������������
	CTwo& operator=(const CTwo& copy) {
		if (this != &copy) {
			d = copy.d;
			p = new COne(*copy.p);
		}
		return *this;
	}
	//������ �������
	double get_d() const
	{
		return d;
	}
	COne* get_p() const
	{
		return p;
	}
	//�����
	virtual void print() const
	{
		cout << "CTwo: d = " << d << ", *p = ";
		cout << "{ ";
		if (p) {
			
			p->print();  
		}
		else {
			cout << "nullptr";
		}
		cout << " }";
	}
};

class CThree : public CTwo
{
private:
	int a;
public:
	//����������� ���������
	CThree() {}
	//����������� � �����������
	CThree(double d, COne*p, int a) : CTwo(d,p), a(a) {}
	//����������� �����������
	CThree(const CThree& copy) : CTwo(copy), a(copy.a) {}
	//����������
	~CThree()
	{
		cout << "Destructor CThree" << endl;
		cout << "a = " << a << " deleted" << endl;
	}
	//����� �������
	int get_a() const
	{
		return a;
	}
	//�����
	virtual void print() const override
	{
		CTwo::print();
		cout << " CThree: a = " << a;
	}
};

class CFour : public CThree
{
private:
	float b;
public:
	//����������� ���������
	CFour() {}
	//����������� � �����������
	CFour(double d,COne* p, int a, float b) : CThree(d,p,a), b(b) {}
	//����������� �����������
	CFour(const CFour& copy) : CThree(copy), b(copy.b) {}
	//����������
	~CFour()
	{
		cout << "Destructor CFour" << endl;
		cout << "b = " << b << " deleted" << endl;
	}
	//����� �������
	float get_b() const
	{
		return b;
	}
	//�����
	virtual void print() const override
	{
		CThree::print();
		cout << " CFour: b = " << b;

	}
};

void printAll(CTwo* arr_ptr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr_ptr[i]->print();
		cout << endl;
	}
}

void line()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
int main()
{
	COne n1(12.5, "Object 1");
	CTwo n2(102.76, &n1);
	CThree n3(67.8, &n1, 10);
	CFour n4(12.3, &n1, 6, 0.18);
	CTwo* arr_ptr[] = { &n2, &n3, &n4 };
	int n = sizeof(arr_ptr) / sizeof(arr_ptr[0]);
	n1.print();
	cout << endl;
	printAll(arr_ptr, n);
	line();
	return 0;
}