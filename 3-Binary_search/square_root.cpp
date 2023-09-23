#include <iostream>
#include <math.h>
using namespace std;
float sqrt(int num, int z)
{
    float precisicion = 1.0/pow(z,10);
    float s = 0, e = num;
    float ans = -1;
    float mid = s + (e - s) / 2;
    while (e-s>=precisicion)
    {
        if (mid * mid == num)
        {
            ans = mid;
            break;
        }
        else if (mid * mid > num)
        {
            e = mid;
            ans = mid;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}
int main()
{
    cout << sqrt(2048,1);
    return 0;
}