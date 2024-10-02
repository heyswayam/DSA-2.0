#include <bits/stdc++.h>
using namespace std;

vector<char> normal_method(){
    vector<char> ans;
    string str;
    getline(cin,str);
    for(auto i:str){
        if(i!=','&&i!='['&&i!=']'){
            ans.push_back(i);
        }
    }
    return ans;
}
vector<char> using_stringstream(){
    vector<char> ans;
    string str;
    getline(cin,str);
    stringstream ss(str);
    char ch;
    while(ss>>ch){
        if(ch!=','&&ch!='['&&ch!=']'&&ch!='"'){
            ans.push_back(ch);
        }
    }
    return ans;
}
int main()
{
    vector<char> str =  using_stringstream();
    string temp;
    for(auto i:str){
        temp+=i;
    }
    cout<<sss;
    return 0;
}