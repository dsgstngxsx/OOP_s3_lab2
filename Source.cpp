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
	COne& operator=(const COne& other) {
		if (this != &other) {
			d = other.d;
			s = other.s;
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
	void print()
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
	CTwo& operator=(const CTwo& other) {
		if (this != &other) {
			d = other.d;
			p = new COne(*other.p);
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
	void print()
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

void line()
{
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~\n";
}
int main()
{
	COne n1(12.5, "Object 1");
	n1.print();
	cout << endl;
	cout << n1.get_d() << endl;
	cout << n1.get_s() << endl;
	COne copy_n1 = n1;
	copy_n1.print();
	line();
	CTwo n2(102.76, &n1);
	n2.print();
	cout << endl;
	cout << n2.get_d() << endl;
	cout << n2.get_p() << endl;
	CTwo copy_n2 = n2;
	copy_n2.print();
	line();
	return 0;
}