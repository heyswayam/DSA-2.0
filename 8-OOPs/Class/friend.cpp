#include <bits/stdc++.h>
using namespace std;
class Bird
{
    int legs;
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
    int static x;
    virtual void fly()
    {
        cout << "Bird is flying (public)" << endl;
    }
    // friend void getPrivate(Bird &b);
};
int Bird::x = 3;
class Sparrow : public Bird
{
public:
    void fly()
    {
        cout << "Sparrow is flying" << endl;
    }
    // void eatLikeABird(Bird &b)
    // {
    //     b.sound();
    // }
};
void getPrivate()
{
    cout << Bird::x << endl;
}
int main()
{
    Bird b1;
    // Sparrow s1;
    getPrivate();
    return 0;
}




/*
********
Reason why you cant call members functions or variables by using ``` friend void getPrivate() ```
********

The issue here is that the `getPrivate()` function is a friend of the `Bird` class, but it's not a member of the `Bird` class. As a friend, it can access the private and protected members of `Bird`, but it doesn't have access to the `this` pointer of a `Bird` object.

In other words, `getPrivate()` is a standalone function, not a method of a `Bird` object. So, when it tries to call `sound()`, it doesn't have a `this` pointer to call it on.

To fix this, you need to pass a `Bird` object to the `getPrivate()` function, like this:

```
void getPrivate(Bird& bird) {
    bird.sound();
}
```

Then, in `main()`, you can call it like this:

```
int main() {
    Sparrow s1;
    getPrivate(s1);
    return 0;
}
```

This way, `getPrivate()` can access the `sound()` method of the `Sparrow` object `s1`, which is a `Bird` object.

********
By using ``` friend void getPrivate() ``` you can access the PRIVATE static member functions variables only.
u can try, but private static member functions arent available outside class if not friend, but PUBLIC static members are availabe outside the class
********
*/