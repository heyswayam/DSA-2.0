#include <iostream>
using namespace std;

int main(){
    int num=6;

    // 24
    int a=1;
    for (int r = 0; r < num; r++)
    {
        for (int c = 0; c < r+1; c++)
        {
            cout<<a++<<" ";
        }
        cout<<endl;
    }
    


    // 27
//     for (int r = 0; r < num; r++)
//     {
//         // upper
//         // left stars
//         for (int c = 0; c < r+1; c++)
//         {
//             cout<<"* ";
//         }
        
//         // spaces
//         for (int c = 0; c < 2*(num-r-1); c++)
//         {
//             cout<<"  ";
//         }

//         // right stars
//         for (int c = 0; c < r+1; c++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
//     }

// for (int r = 0; r < num; r++)
// {
//         // lower
//         // left stars
//         for (int c = 0; c < num-r; c++)
//         {
//             cout<<"* ";
//         }
//         // spaces
//         for (int c = 0; c < r*2; c++)
//         {
//             cout<<"  ";
//         }
//         // right stars
//         for (int c = 0; c < num-r; c++)
//         {
//             cout<<"* ";
//         }
//         cout<<endl;
        
        
        
// }




        
    
    
    
    return 0;
}