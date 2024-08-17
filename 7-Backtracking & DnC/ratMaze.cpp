#include <bits/stdc++.h>
using namespace std;

void rat_maze(vector<vector<int>> &v, int x, int y, int n, int m, vector<vector<bool>> &isVisited)
{
    if (x == n - 1 && y == m - 1)
    {
        cout <<endl << "found" << endl;
        return;
    }

    // right
    if (y + 1 < m && v[x][y + 1] == 1 && !isVisited[x][y + 1])
    {
        isVisited[x][y + 1] = true;
        cout << "R";

        rat_maze(v, x, y + 1, n, m, isVisited);
        isVisited[x][y + 1] = false;
    }

    // down
    if (x + 1 < n && v[x + 1][y] == 1 && !isVisited[x + 1][y])
    {
        isVisited[x + 1][y] = true;
        cout << "D";

        rat_maze(v, x + 1, y, n, m, isVisited);
        isVisited[x + 1][y] = false;
    }
    // left
    if (y - 1 >= 0 && v[x][y - 1] == 1 && !isVisited[x][y - 1])
    {
        isVisited[x][y - 1] = true;
        cout << "L";

        rat_maze(v, x, y - 1, n, m, isVisited);
        isVisited[x][y - 1] = false;
    }
    // up
    if (x - 1 >= 0 && v[x - 1][y] == 1 && !isVisited[x - 1][y])
    {
        isVisited[x - 1][y] = true;
        cout << "U";

        rat_maze(v, x - 1, y, n, m, isVisited);
        isVisited[x - 1][y] = false;
    }
}

int main()
{
    vector<vector<int>> v{{1, 0, 0}, {1, 0, 0}, {1, 1, 0}, {1, 1, 1}};
    int n = v.size(); // Number of rows
    int m = v[0].size(); // Number of columns
    cout << "n:" << n << " m:" << m << endl;
    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    isVisited[0][0] = true;
    rat_maze(v, 0, 0, n, m, isVisited);
    return 0;
}
