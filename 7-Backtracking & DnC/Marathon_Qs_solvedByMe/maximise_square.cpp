#include <bits/stdc++.h>
using namespace std;

int maximise_sq(vector<vector<char>> &v, int m, int n, int i, int j, int &ans)
{
    if (i == n && j == m)
        return 0;
    if (i == m)
        return 0;
    if (j == n)
        return 0;

    int right = maximise_sq(v, m, n, i + 1, j, ans);
    int diagonal = maximise_sq(v, m, n, i + 1, j + 1, ans);
    int down = maximise_sq(v, m, n, i, j + 1, ans);

    int temp = min(right, min(diagonal, down));
    // cout << "ans: " << ans << " temp:" << temp << " i: " << i << " j: " << j << endl;

    if (v[i][j] == '0')
    {
        return 0;
    }
    else
        ans = max(ans, 1 + temp);

    return 1 + temp;
}
int main()
{
    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    // vector<vector<char>> matrix = {{'1','0','1'},{'1','0','1'},{'1','1','1'}};
    // vector<vector<char>> matrix = {{'1', '1', '1'}, {'1', '1', '1'},{'1', '1', '1'}};
    vector<vector<char>> matrix = {{'0','0','0'},{'0','0','0'}};

    int rows = matrix.size();
    int cols = matrix[0].size();
    int ans = INT_MIN;
    int result = maximise_sq(matrix, rows, cols, 0, 0, ans);
    cout <<INT_MAX* INT_MAX << endl;
    // cout<<result*result<<endl;
    return 0;
}