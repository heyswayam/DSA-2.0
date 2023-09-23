#include <iostream>
using namespace std;

int main()
{
    int num = 5;
    //  7
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < r+1; c++)
    //     {
    //         cout<<c+1;
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // 8
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < num-r; c++)
    //     {
    //         cout<<c+1;
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    // 9
    // for (int r = 0; r < num; r++)
    // {
    //     if (r==0 || r==num-1)
    //     {
    //         for (int c = 0; c < r+1; c++)
    //         {
    //             cout<<c+1;
    //             cout<<" ";
    //         }

    //     }
    //     else{
    //         cout<<"1 ";
    //         for (int c = 0; c < r-1; c++)
    //         {
    //             cout<<"  ";
    //         }
    //         cout<<r+1;
    //     }
    //     cout<<endl;
    // }

    // 10
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < num - r - 1; c++)
    //     {
    //         cout << "  ";
    //     }

    //     for (int c = r + 1; c <= (2 * r) + 1; c++)
    //     {
    //         cout << c;
    //         cout << " ";
    //     }

    //     for (int c = r * 2; c >= r + 1; c--)
    //     {
    //         cout << c;
    //         cout << " ";
    //     }
    //     cout << endl;
    // }

    // 11
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < num - r - 1; c++)
    //     {
    //         cout << "  ";
    //     }

    //     if (r == 0 || r == num - 1)
    //     {
    //         for (int c = 0; c < r + 1; c++)
    //         {
    //             cout << c + 1 << "   ";
    //         }
    //     }
    //     else
    //     {
    //         cout << "1 ";
    //         for (int c = 0; c < (r * 2) - 1; c++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << r + 1;
    //     }
    //     cout << endl;
    // }

    // 12
    // for (int r = 0; r < num; r++)
    // {
    //     if (r == 0)
    //     {
    //         for (int c = 0; c < num - r; c++)
    //         {
    //             cout << c + 1 << " ";
    //         }
    //     }
    //     else if (r == num - 1)
    //     {
    //         cout << num;
    //     }
    //     else
    //     {
    //         cout << r + 1 << " ";
    //         for (int c = 0; c < num - r - 2; c++)
    //         {
    //             cout << "  ";
    //         }
    //         cout << num;
    //     }
    //     cout << endl;
    // }

    // 13
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < r + 1; c++)
    //     {
    //         cout << c + 1 << " ";
    //     }

    //     for (int c = r; c > 0; c--)
    //     {
    //         cout<<c<<" ";
    //     }
    //     cout<<endl;
    // }

    return 0;
}