#include <bits/stdc++.h>
using namespace std;

class Bird
{
private:
    void poop()
    {
        cout << "Birds poop..." << endl;
        return;
    }

public:
    int wings = 2;
    virtual // virtual keyword -> ignores below codes during compilation

        void
        sound()
    {
        cout << "Bird making sound..." << endl;
        return;
    }
};

class Sparrow : public Bird
{
public:
    string color = "Brown";
    void sound()
    {
        cout << "Makes sparrow sound" << endl;
    }
    string size = "Small";
};
int main()
{
    // Bird b1;
    // b1.sound();
    // cout << b1.wings << endl;

    // Sparrow s1;
    // cout << s1.color << endl;
    // cout << s1.wings << endl;
    // s1.sound();

    return 0;
}