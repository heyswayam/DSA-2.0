#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, vector<int>> adjList;
    void addEdge(int a, int b, int dir)
    {
        if (dir == 0)
        {
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        else
            adjList[a].push_back(b);
    }

    void printAdjList()
    {
        for (auto &&i : adjList)
        {
            cout << i.first << ": {";
            for (auto &&j : i.second)
            {
                cout << j << " , ";
            }
            cout << "} " << endl;
        }
    }

    map<int,bool> visited;
    bool checkCycle_DFS(int src)
    {
        // cout << src << " | ";
        visited[src] = true;
        bool ans = false;
        for (auto &child : adjList[src])
        {
            if (!visited[child])
            {
                ans = checkCycle_DFS(child);
                if (ans == true)
                {
                    return true;
                }
            }
            else if (visited[child == true])
            {
                // cout << endl
                //  << "inside src: " << src << endl;
                return true;
            }
        }
        return ans;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 1, 1);
    g.printAdjList();
    cout << g.checkCycle_DFS(0);
    return 0;
}