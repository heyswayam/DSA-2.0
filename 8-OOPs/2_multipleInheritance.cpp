#include <bits/stdc++.h>
using namespace std;

/// @brief 
class Person
{

public:
    void walk()
    {
        cout << "person walks..." << endl;
    }
};
class Teacher :virtual public Person
{

public:
    void teaches()
    {
        cout << "Teacher teaches..." << endl;
    }
};

class Researcher :virtual public Person
{

public:
    void researcher()
    {
        cout << "Researcher researches..." << endl;
    }
};

class Professor : public Researcher, public Teacher
{

public:
    void researcher()
    {
        cout << "Researcher researches..." << endl;
    }
};
int main()
{
    Person p1;
    p1.walk();
    Researcher r1;
    r1.walk();
    Teacher t1;
    t1.walk();
    Professor prf1;
    prf1.walk();
    return 0;
}