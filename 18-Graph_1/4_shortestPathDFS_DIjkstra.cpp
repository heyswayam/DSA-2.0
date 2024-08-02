#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, vector<pair<int, int>>> adj;

    void addEdge(int u, int v, int dist, bool direction)
    {
        // direction - 0 - undirected
        // direction - 1 - directed
        if (direction == 1)
        {
            adj[u].push_back({v, dist});
        }
        else
        {
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " : { ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << " , " << j.second << "), ";
            }
            cout << "} " << endl;
        }
    }

    stack<int> topo;
    unordered_map<int, bool> visit;
    void topoSort(int src)
    {
        visit[src] = true;
        for (auto &&child : adj[src])
        {
            if (!visit[child.first])
                topoSort(child.first);
        }
        topo.push(src);
    }

    void shortestPathDFS(int n)
    {
        // topo is stack containing topological ordering
        vector<int> dist(n + 1, INT_MAX);
        dist[topo.top()] = 0;
        while (!topo.empty())
        {
            int front = topo.top();
            topo.pop();
            for (auto &&child : adj[front])
            {
                int srcDist = dist[front];
                int childNode = child.first;
                int childDist = child.second;

                if (dist[front] + childDist < dist[childNode])
                {
                    dist[childNode] = dist[front] + childDist;
                }
            }
        }

        // printing dist vector
        for (auto &&i : dist)
        {
            cout << i << " ";
        }
    }

    void fun(int src, int n)
    {
        vector<int> dist(n + 1, INT_MAX);
        map<int, int> st;

        st.insert({src, adj[src].second});
        for (auto &&i : st)
        {
            cout << i.first << " " << i.second << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(4, 3, 1, 1);
    g.topoSort(0);
    // g.printAdjList();
    // g.shortestPathDFS(5);
    g.dijkstra(2, 10);

    return 0;
}