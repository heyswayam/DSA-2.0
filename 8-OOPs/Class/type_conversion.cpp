#include <bits/stdc++.h>
using namespace std;

class Number
{
    int n;
public:
    Number(int n) // 1- for basic -> class type-conversion, it uses the default ctor
    {
        this->n = n;
    }
    operator int() // 2- for class -> basic type-conversion [syntax]
    { 
        return n;
    }
    int getN(){
        return n;
    }
    // operator Mark(){
    //     Mark temp(this->n);
    //     return temp;
    // }
};


class Mark
{
    int i;

public:
    Mark(int i)
    {
        this->i = i;
    }
    Mark(Number n){
        this->i = n.getN();
    }
    void print(){
        cout<<this->i<<endl;
    }
};





int main()
{
    Number n1(8);
    Mark m1 = n1;
    m1.print();
    return 0;
}

/*
3- one class type to another class type-conversion:
When we assign an object of a class into the object of another class then it is called as class to class conversion. The class to class conversion can be performed either "by defining casting operator function" in source class or "using the constructor in the destination class".
*/