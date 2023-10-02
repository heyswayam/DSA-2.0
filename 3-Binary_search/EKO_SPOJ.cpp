#include <bits/stdc++.h>
using namespace std;

bool check(vector<long long int> &height, long long int mid, long long int K){
    long long int sum=0;
    for(auto i: height){
        if(i>mid){
            sum+=(i-mid);
        }
    }

    if (sum>=K)
    {
        return true;
    }
    
    return false;
}
int main(){
    long long int n;
    cin>>n;
    long long int M;
    cin>>M;
    vector<long long int> height(n);
    long long int i=0;
    while (n--)
    {
        cin>>height[i++];
    }
    

    sort(height.begin(),height.end());
    long long int s=0;
    long long int e=height[height.size()-1];
    long long int ans=-1;
    while (s<=e)
    {
        long long int mid = s+(e-s)/2;
        if(check(height,mid,M)){
            s=mid+1;
            ans=mid;
        }
        else{
            e=mid-1;
        }
    }
    
    cout<<ans;
    return 0;
}