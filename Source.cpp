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
	COne& operator=(const COne& other) {
		if (this != &other) {
			d = other.d;
			s = other.s;
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
	void print()
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
	CTwo& operator=(const CTwo& other) {
		if (this != &other) {
			d = other.d;
			p = new COne(*other.p);
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