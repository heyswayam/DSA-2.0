#include <bits/stdc++.h>
using namespace std;

// method 2
int lowerBound(vector<int> &arr, int x)
{
  int s = 0, e = arr.size() - 1, mid = s + (e - s) / 2;
  int ans;
  while (s < e)
  {
    if (arr[mid] == x)
    {
      ans = mid;
      return ans;
    }
    else if (arr[mid] > x)
    {
      e = mid - 1;
    }
    else
    {
      s = mid + 1;
      ans = mid;
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

vector<int> twoPtr_fromSmallsize(vector<int> &arr, int k, int x)
{
  int l = lowerBound(arr, x);
  int h = l + 1;
  cout << l << " " << h << endl
       << endl;
  while (k--)
  {
    if (x - arr[l] <= arr[l] - x)
      l--;
    else if (x - arr[l] > arr[l] - x)
      h++;
    cout << "l:" << l << " h:" << h << endl;
  }
  return vector<int>(arr.begin() + l + 1, arr.begin() + h);
}
int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);
  int k = 4, x = 3;
  vector<int> ans = twoPtr_fromSmallsize(v, k, x);
  // cout<<"Hello";
  for (auto &&i : ans)
  {
    cout << i << " ";
  }

  // vector<int> ans;
  // int k=5;
  // int i= v.size()-k;
  // while(i<v.size()){
  //     ans.push_back(v[i++]);
  // }
  // // for (int i = v.size()-5; i <v.size(); i++)
  // // {
  // //     ans.push_back(v[i]);
  // // }

  // for (auto &&i : ans)
  // {
  //     cout<<i<<" ";
  // }

  return 0;
}