#include <iostream>
using namespace std;
float div(int divident,int divisor, int dec)
{
    float precisicion = 1.0/pow(dec,10);
    cout<<"prec:"<<precisicion<<endl;  // when dec=2 prec:0.000976562
    float s = 0, e = divident;
    float ans = -1;
    float mid = s + (e - s) / 2;
    while (e-s>=precisicion)
    {
        if (mid * divisor == divident)
        {
            ans = mid;
            break;
        }
        else if (mid * divisor > divident)
        {
            e = mid;
        }
        else
        {
            s = mid;
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
int main()
{
    cout << div(13,3,2);
    return 0;
}