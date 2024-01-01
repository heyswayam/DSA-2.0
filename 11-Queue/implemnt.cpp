#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q1;
    queue<int> q2 = q1;
    q1.push(5);
    q1.push(5);
    q1.push(5);
    q1.push(5);
    q1.push(5);

    while (q2.empty()!=1)
    {
        cout<<q2.front()<<" ";
        q2.pop();
    }
    
    return 0;
}