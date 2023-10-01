#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
void reverse(char ch[],int size){
    int s=0, e=size-1;
    while (s<e)
    {
        swap(ch[s++],ch[e--]);
    }
    
}
bool isPallindrome(string ch,int size){
    int s=0, e=size-1;

    while (s<e)
    {
        if (!(ch[s++]==ch[e--]))
        {
            return false;
        }
    }
    return true;
    
}
bool isPallindrome(char ch[],int size){
    int s=0, e=size-1;

    while (s<e)
    {
        if (!(ch[s++]==ch[e--]))
        {
            return false;
        }
    }
    return true;
    
}
int main()
{
    char ch[20];
    // cin>>ch;
    // reverse(ch,6);
    // cout<<a;
    string str1="BAb";
    string str2="Bab";
    // getline(cin,str);

  
    // if(str1==str2) cout<<"1";      // comparing strings
    // else cout<<"0";

    // cout<<str1.compare(str2);
    // cout << a;
    return 0;
}