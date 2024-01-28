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
    unordered_map<int, int> parent;
    unordered_map<int, bool> vis;
    bool checkCycle(int src)
    {
        queue<int> q;
        q.push(src);
        parent[src] = -1;
        vis[src] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto &&child : edgeList[frontNode])
            {
                if (!vis[child])
                {
                    q.push(child);
                    vis[child] = true;
                    parent[child] = frontNode;
                }
                // else if (parent[frontNode] != child)     //could do this too
                // else if(vis[child]==true && parent[child]!=frontNode){
                // {
                //     return true;
                // }
                else if (vis[child] == true && parent[frontNode] == child){
                    continue;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(3, 5, 0);
    g.printAdjList();
    cout << g.checkCycle(0) << endl;
    return 0;
}