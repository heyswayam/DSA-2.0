#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    map<int, list<int>> edgeList;
    void addEdge(int u, int v, bool dir)
    {
        if (dir)
        {
            edgeList[u].push_back(v);
        }
        else
        {
            edgeList[u].push_back(v);
            edgeList[v].push_back(u);
        }
    }
    void printAdjList()
    {
        for (auto &&i : edgeList)
        {
            cout << i.first << " = { ";
            for (auto &&j : i.second)
            {
                cout << j << " , ";
            }
            cout << "}" << endl;
        }
    }

    bool checkCycle(int src, unordered_map<int, bool> &vis, int parent)
    {
        vis[src] = true;
        bool ans = false;
        for (auto &child : edgeList[src])
        {
            if (!vis[child])
            {
                // parent[child]=src;
                ans = checkCycle(child, vis, src);
                if (ans == true)
                    return true;
            }
            else if (vis[child] == true && parent == child) // I was doing only if, so next conditions were getting executed
            {
                continue;
            }
            else if (vis[child] == true && parent != child)
            {
                return true;
            }
        }
        return ans;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    // g.addEdge(2, 3, 0);
    g.addEdge(1, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 0);
    g.printAdjList();
    unordered_map<int, bool> vis;
    // unordered_map<int, bool> parent;
    // parent[0]=-1;
    // bool ans = false;
    cout << g.checkCycle(0, vis, -1) << endl;
    // cout<<ans<<endl;
    return 0;
}