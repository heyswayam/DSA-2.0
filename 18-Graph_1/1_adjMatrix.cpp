#include <bits/stdc++.h>
using namespace std;

void createAdjMatrix(map<int, vector<int>> edgeList)
{
    int n = 4;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (auto &&i : edgeList)
    {
        int row = i.first;
        for (auto &&j : i.second)
        {
            int col = j;
            matrix[row][col] = 1;
        }
    }
    //printing
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{

    map<int, vector<int>> edgeedgeList;
    edgeedgeList[0] = {1};
    edgeedgeList[1] = {2, 3};
    edgeedgeList[2] = {3};

    cout << endl;
    cout << endl;
    createAdjMatrix(edgeedgeList);
    return 0;
}