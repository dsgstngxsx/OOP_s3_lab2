#include <string>
#include <iostream>

using namespace std;

class COne //1 класс
{
private:
	double d;
	string s;

public:

	//конструктор умолчания
	COne() {}
	//конструктор с параметрами
	COne(double d, string s) : d(d), s(s) {}
	//конструктор копирования
	COne(const COne& copy) : d(copy.d), s(copy.s) {}
	//деструктор
	~COne() 
	{
		cout << "Destructor COne:" << endl;
		cout << "d = " << d << " deleted" << endl;
		cout << "s = " << s << " deleted" << endl;
	}
	//оператор присваивания
	COne& operator=(const COne& copy) {
		if (this != &copy) {
			d = copy.d;
			s = copy.s;
		}
		return *this;
	}
	//методы доступа
	double get_d() const 
	{ 
		return d; 
	}
	string get_s() const 
	{ 
		return s; 
	}
	//вывод на экран
	void print() const
	{
		cout << "COne: d = " << d << ", s = " << s;
	}
};

class CTwo //2 класс
{
private:
	double d;
	COne* p;

public:

	//конструктор умолчания
	CTwo() {}
	//конструктор с параметрами
	CTwo(double d, COne* p) : d(d), p(p) {}
	//конструктор копирования
	CTwo(const CTwo& copy) : d(copy.d), p(new COne(*copy.p)) {}
	//деструктор
	~CTwo()
	{
		cout << "Destructor CTwo:" << endl;
		cout << "d = " << d << " deleted" << endl;
		cout << "&p = " << p << " deleted" << endl;
	}
	//оператор присваивания
	CTwo& operator=(const CTwo& copy) {
		if (this != &copy) {
			d = copy.d;
			p = new COne(*copy.p);
		}
		return *this;
	}
	//методы доступа
	double get_d() const
	{
		return d;
	}
	COne* get_p() const
	{
		return p;
	}
	//вывод
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
	//конструктор умолчания
	CThree() {}
	//конструктор с параметрами
	CThree(double d, COne*p, int a) : CTwo(d,p), a(a) {}
	//конструктор копирования
	CThree(const CThree& copy) : CTwo(copy), a(copy.a) {}
	//деструктор
	~CThree()
	{
		cout << "Destructor CThree" << endl;
		cout << "a = " << a << " deleted" << endl;
	}
	//метод доступа
	int get_a() const
	{
		return a;
	}
	//вывод
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
	//конструктор умолчания
	CFour() {}
	//конструктор с параметрами
	CFour(double d,COne* p, int a, float b) : CThree(d,p,a), b(b) {}
	//конструктор копирования
	CFour(const CFour& copy) : CThree(copy), b(copy.b) {}
	//деструктор
	~CFour()
	{
		cout << "Destructor CFour" << endl;
		cout << "b = " << b << " deleted" << endl;
	}
	//метод доступа
	float get_b() const
	{
		return b;
	}
	//вывод
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