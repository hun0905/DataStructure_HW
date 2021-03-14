#include <iostream>
using namespace std;
class Polynomial;

class Term
{
    friend Polynomial;

public:
    float coef;
    int exp;
    Term *Next;
};
class Polynomial
{
    friend Term;

public:
    Polynomial(int c);
    Polynomial Add(Polynomial a, Polynomial b);
    friend ostream &operator<<(ostream &os, Polynomial &p);
    friend istream &operator>>(istream &is, Polynomial &p);

private:
    Term *termArray;
    int capacity;
    int terms;
};
Polynomial Polynomial::Add(Polynomial a, Polynomial b)
{
    int apos = 0, bpos = 0;
    float coef;
    int exp;
    int length = 0;
    Term *List = new Term;
    Term *head = List;
    while (apos < a.capacity || bpos < b.capacity)
    {
        length++;
        if (a.termArray[apos].exp > b.termArray[bpos].exp || apos > a.capacity-1)
        {
            List->coef = b.termArray[bpos].coef;
            List->exp = b.termArray[bpos].exp;
            Term *NewTerm = new Term;
            List->Next = NewTerm;
            List = List->Next;
            List->Next = NULL;
            bpos++;
        }
        else if (a.termArray[apos].exp < b.termArray[bpos].exp || bpos > b.capacity-1)
        {
            List->coef = a.termArray[apos].coef;
            List->exp = a.termArray[apos].exp;
            Term *NewTerm = new Term;
            List->Next = NewTerm;
            List = List->Next;
            List->Next = NULL;
            apos++;
        }
        else if (a.termArray[apos].exp == b.termArray[bpos].exp)
        {
            List->coef = a.termArray[apos].coef + b.termArray[bpos].coef;
            List->exp = a.termArray[apos].exp;
            Term *NewTerm = new Term;
            List->Next = NewTerm;
            List = List->Next;
            List->Next = NULL;
            apos++;
            bpos++;
        }
    }
    Polynomial c(length);
    int n = 0;
    for (Term *i = head ;i != NULL; i = i->Next)
    {
        c.termArray[n].coef = i->coef;
        c.termArray[n].exp = i->exp;
        n++;
    }
    return c;
}
ostream &operator<<(ostream &os, Polynomial &p)
{

    for (int i = 0; i < p.capacity; ++i)
    {
        os << p.termArray[i].coef << "x^";
        os << p.termArray[i].exp;
        if (i < p.capacity - 1)
            os << "+";
    }
    os << endl;
    return os;
}
istream &operator>>(istream &is, Polynomial &p)
{
    for (int i = 0; i < p.capacity; ++i)
    {
        is >> p.termArray[i].coef;
        is >> p.termArray[i].exp;
    }
    return is;
}
Polynomial::Polynomial(int c)
{
    capacity = c;
    termArray = new Term[capacity];
}

int main()
{
    float *coef = new float[4];
    int *exp = new int[4];
    int capacity;
    cout << "input the capacity" << endl;
    cin >> capacity;
    Polynomial P(capacity);
    Polynomial q(capacity);
    Polynomial C(capacity);
    cin >> P ;
    cin >> q ;
    C = P.Add(P,q);
    cout<<C;
    return 0 ;
}