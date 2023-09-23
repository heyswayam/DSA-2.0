#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<vector<int>> matrix)
{
    int r = matrix.size();
    int c = matrix[0].size();

    for (int i = 0; i < r; i++)
    {
        cout << "[";
        for (int j = 0; j < c; j++)
        {
            cout << matrix[i][j];
        }
        cout << "],";
    }
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++)
    {
        if (i == 0)
            ans[0][0] = 1;
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                ans[i][j] = 1;
            }
            else
            {
                ans[i][j] = (ans[i - 1][j] + ans[i - 1][j - 1]);
            }
        }
    }
    return ans;
}

int main()
{
    printArr(generate(5));
    return 0;
}