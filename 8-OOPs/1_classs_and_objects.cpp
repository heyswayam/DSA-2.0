#include <bits/stdc++.h>
using namespace std;

class Student
{
private:
    string gf;
    void gfChatting()
    {
        cout << "chatting with gf" << endl;
    }

public:
    string name;
    int age;
    char gender;
    int *p;

    // Default Constructor  present : default
    Student()
    {
        cout << "Accessing student constructor" << endl;
    }

    // parameterized constructor
    Student(string _name, int _age, string _gf)
    {
        cout << "Parameterized contstructor called" << endl;
        name = _name;
        age = _age;
        this->gf = _gf;
        cout << this << endl;
    }

    // copy constructor
    Student(Student &srcobj)
    {
        cout << "Copy ctor called" << endl;
    }

    // getter
    string getGf()
    {

        return gf;
    }
    void setgf(string &s)
    {
        gf = s;
        return;
    }

    void study(){
        cout<<"studying.."<<endl;
    }
    ~Student()
    {
        cout << "Student dtor called" << endl;
        delete p;
    }
};

int main()
{

    {
        Student s1("Danny", 23, "Ana");
        cout << "address of s1: " << &s1 << endl;
        s1.p = new int(10);
        cout << s1.getGf() << endl;
        string s = "mandy";
        s1.setgf(s);
        cout << s1.getGf() << endl;
        s1.study();
    }
    return 0;
}