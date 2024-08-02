#include <bits/stdc++.h>
using namespace std;

class Bird
{
    static int legs;
    int wings;
    void sound()
    {
        cout << "Bird is making sound (private)" << endl;
    }

protected:
    virtual void eat()
    {
        cout << "Bird is eating (protected)" << endl;
    }

public:
    Bird(int wings)
    {
        this->wings = wings;
    }
    void getWings()
    {
        cout << wings << endl;
    }
    virtual void fly()
    {
        cout << "Bird is flying (public)" << endl;
    }

    friend void accessingPrivate();
    friend class Sparrow;
};
int Bird::legs = 2;
class Sparrow : public Bird
{
public:
    Sparrow()
    {

    }
    void fly()
    {
        cout << "Sparrow is flying" << endl;
    }
    void eatLikeABird(Bird &b)
    {
        b.sound();
        cout << Bird::legs << endl;
    }
};

void accessingPrivate()
{

    cout << Bird::legs << endl;
}

int main()
{
    static Bird b1(3);
    b1.getWings();
    // Sparrow s1;
    // s1.eatLikeABird(b1);
    accessingPrivate(); // Calls the friend function

    return 0;
}
/*
1:
static Object initializes all the variables with ZERO

2:
The error message is indicating that the `Sparrow` class's constructor must explicitly initialize the `Bird` base class, which doesn't have a default constructor.

This is because the `Bird` class has a constructor that takes an integer parameter (`Bird(int wings)`), which means it doesn't have a default constructor (a constructor with no parameters).

When you create a `Sparrow` object, it needs to initialize its `Bird` base class, but it doesn't know how to do so because there's no default constructor in `Bird`.

To fix this, you need to explicitly initialize the `Bird` base class in the `Sparrow` constructor, like this:

```
class Sparrow : public Bird {
    public:
    Sparrow() : Bird(0) { } // Initialize Bird with wings = 0
    // ...
};
```

By doing so, you're telling the compiler to call the `Bird` constructor with a default value (in this case, 0) when creating a `Sparrow` object. This will properly initialize the `Bird` base class, and the error should go away.

*/