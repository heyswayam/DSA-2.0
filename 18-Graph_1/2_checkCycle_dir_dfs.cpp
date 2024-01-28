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
    
    void checkCycle(int src, unordered_map<int, bool> &vis, unordered_map<int, bool> &parent, bool &ans){

        for (auto &&child : edgeList[src])
        {
            if(vis[child]==true)
            {
                continue;
            } 
            vis[child]=true;
            
            parent[child]=src;
            checkCycle(child,vis);
            vis[child]=false;
            
            if(parent[src] != child)
        }
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
    unordered_map<int, bool> vis;
    bool ans = false;
    g.checkCycle(0,vis,ans) << endl;
    cout<<ans<<endl;
    return 0;
}