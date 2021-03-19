#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
class Polynomial; //forward declaration
//first
class Term
{
	friend Polynomial;

private:
	float coef; //coefficient
	int exp;	//exponent
};
class Polynomial
{
public:
	Polynomial(int c = 0);
	void GetTerm(float &coef, int &exp, int location);
	friend istream &operator>>(istream &is, Polynomial &p);
	friend ostream &operator<<(ostream &os, Polynomial &p);
	void NewTerm(float coef, int exp);
	Polynomial Add(Polynomial b);
	Polynomial Mult(Polynomial b);
	float eval(float x);
	~Polynomial();
	//omit
private:
	Term *termArray;
	int capacity; //size of termArray
	int terms;	  //number of nonzero terms
};
Polynomial::Polynomial(int c)
{
	capacity = c;
	terms = 0;
	termArray = new Term[c];
}
void Polynomial::GetTerm(float &coef, int &exp, int location)
{
	coef = termArray[location].coef;
	exp = termArray[location].exp;
}
void Polynomial::NewTerm(float coef, int exp)
{
	if (capacity == terms)
	{
		if (capacity == 0)
			capacity++;
		else
			capacity *= 2;
		Term *TermTmp = new Term[capacity];
		for (int i = 0; i < terms; ++i)
		{
			TermTmp[i] = termArray[i];
		}
		delete[] termArray;
		termArray = TermTmp;
		//p.termArray = new Term[p.capacity];
	}
	termArray[terms].coef = coef;
	termArray[terms].exp = exp;
	terms++;
}
Polynomial Polynomial::Add(Polynomial b)
{
	int apos = 0, bpos = 0;
	Polynomial c;
	while (apos < terms && bpos < b.terms)
	{
		if (termArray[apos].exp < b.termArray[bpos].exp)
		{
			c.NewTerm(termArray[apos].coef, termArray[apos].exp);
			apos++;
		}
		else if (termArray[apos].exp == b.termArray[bpos].exp)
		{
			float tmp = termArray[apos].coef + b.termArray[bpos].coef;
			if (tmp)
				c.NewTerm(tmp, termArray[apos].exp);
			apos++;
			bpos++;
		}
		else
		{
			c.NewTerm(b.termArray[bpos].coef, b.termArray[bpos].exp);
			bpos++;
		}
	}
	while (apos < terms)
	{
		c.NewTerm(termArray[apos].coef, termArray[apos].exp);
		apos++;
	}
	while (bpos < b.terms)
	{
		c.NewTerm(b.termArray[bpos].coef, b.termArray[bpos].exp);
		bpos++;
	}
	return c;
}
Polynomial Polynomial::Mult(Polynomial b)
{
	Polynomial c;
	
	for (int i = 0; i < terms; ++i)
	{
		Polynomial *tmp = new Polynomial(b.terms);
		for (int j = 0; j < b.terms; ++j)
		{
			tmp->termArray[j].coef = termArray[i].coef * b.termArray[j].coef;
			tmp->termArray[j].exp = termArray[i].exp + b.termArray[j].exp;
			tmp->terms++;
		}
		if (i == 0)
			c = *tmp;
		else
			c = c.Add(*tmp);
		delete tmp;
	}
	return c;
}
float Polynomial::eval(float x)
{
	float result = 0;
	for (int i = 0; i < terms; ++i)
	{
		result += termArray[i].coef * pow(x, termArray[i].exp);
	}
	return result;
}
Polynomial ::~Polynomial()
{
	//delete []termArray;
}
ostream &operator<<(ostream &os, Polynomial &p)
{
	float coef;
	int exp;
	for (int i = p.terms - 1; i >= 0; --i)
	{
		p.GetTerm(coef, exp, i);
		if (int(coef) != 0)
			os << coef;
		if (exp != 0)
		{
			os << "x^";
			os << exp;
			if (i > 0)
				os << "+";
		}
	}
	return os;
}
istream &operator>>(istream &is, Polynomial &p)
{
	float coef;
	int exp;
	char c;
	cout << "輸入polynomial(按任意英文字離開),由小到大" << endl;
	while (c != '\n')
	{
		is >> coef >> exp;
		c = cin.peek();
		while (c == ' ')
		{
			cin.ignore(1);
			c = cin.peek();
		}
		p.NewTerm(coef, exp);
	}
	return is;
}
int main()
{
	Polynomial p, q;
	Polynomial a, b;
	char c;
	cin >> p;
	cout << p << endl;
	cin >> q;
	cout << q << endl;
	a = p.Add(q);
	cout << a << endl;
	b = p.Mult(q);
	cout<<b<<endl;
	cout<<b.eval(2.5)<<endl;
	return 0;
}
