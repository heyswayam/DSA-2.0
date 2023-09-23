#include <iostream>
using namespace std;

int main()
{
    int num = 6;
    // cin>>num;

    // 1
    //  for (int r = 0; r < num; r++)
    //  {
    //      for (int c = 0; c < r+1; c++)
    //      {
    //          cout<<"* ";
    //      }
    //      cout<<endl;
    //  }

    // 2
    // for (int r = 0; r < num; r++)
    // {
    //     for (int c = 0; c < num-r; c++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;

    // }

    // 3
    // for (int r = 0; r < num; r++)
    // {
    //     if (r == 0 || r == num - 1)
    //     {
    //         for (int c = 0; c < num-r; c++)
    //         {
    //             cout<<"* ";
    //         }
    //     }

    //     else
    //     {
    //         cout<<"* ";
    //         for (int c = 0; c < num-r-2; c++)
    //         {
    //             cout<<"  ";
    //         }
    //         cout<<"* ";
    //     }
    //     cout<<endl;
    // }

    // 4
    // for (int r = 0; r < num; r++)
    // {
    //     // spaces
    //     for (int c = 0; c < num-r-1; c++)
    //     {
    //         cout<<" ";
    //     }

    //     // stars
    //     for (int c = 0; c < r+1; c++)
    //     {
    //         cout<<"* ";
    //     }
    //     cout<<endl;

    // }

    // 5
    // for (int r = 0; r < num; r++)
    // {
    //     // spaces
    //     for (int c = 0; c < r; c++)
    //     {
    //         cout << " ";
    //     }

    //     // stars
    //     for (int c = 0; c < num-r; c++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    // return 0;

    // 6
    // for (int r = 0; r < num; r++)
    // {

    //     // space
    //     for (int c = 0; c < num - r - 1; c++)
    //     {
    //         cout << " ";
    //     }
    //     if (r == 0 || r == num - 1)
    //     {
    //         for (int c = 0; c < r + 1; c++)
    //         {
    //             cout << "* ";
    //         }
    //     }
    //     // spaces inside stars
    //     else
    //     {
    //         cout << "*";
    //         for (int c = 0; c < 2*r-1; c++)
    //         {
    //             cout << " ";
    //         }
    //         cout << "*";
    //     }

    //     cout << endl;
    // }
}