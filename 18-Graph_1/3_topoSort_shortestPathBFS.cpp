#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction -> 0 undirected
        // direction -> 1 directed
        if (direction == 1)
        {
            adj[u].push_back(v);
        }
        else
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << ": {";
            for (auto j : i.second)
            {
                cout << j << ",";
            }
            cout << "}" << endl;
        }
    }
    stack<int> element;
    unordered_map<int, bool> visited;
    void topoSortDFS(int src)
    {
        visited[src] = true;
        for (auto &&i : adj[src])
        {
            if (!visited[i])
            {
                topoSortDFS(i);
            }
        }
        element.push(src);
    }
    void printStack()
    {
        while (!element.empty())
        {
            cout << element.top() << " ";
            element.pop();
        }
    }

    void topoSortBFS(int src)
    {
        queue<int> q;
        unordered_map<int, int> indegree;
        vector<int> ans;

        // making indegree map
        for (auto &&i : adj)
        {
            for (auto &&child : i.second)
            {
                indegree[child]++;
            }
        }
        // pushing element with indegree = 0
        for (int i = 0; i < adj.size(); i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            for (auto &&child : adj[front])
            {
                indegree[child]--;
                if (indegree[child] == 0)
                    q.push(child);
            }
        }
        // printing the ans
        for (auto &&i : ans)
        {
            cout << i << " ";
        }
    }
    void shortestPathBFS(int start, int dest)
    {
        queue<int> q;
        map<int, bool> visited;
        map<int, int> parent;
        vector<int> ans;

        q.push(start);
        visited[start] = true;
        parent[start] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto &&child : adj[front])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    parent[child] = front;
                    q.push(child);
                }
            }
        }

        // we got the parent array from BFS traversal

        // now, tracking back the ancestor till u reach src (parent = -1)
        while (dest != -1)
        {
            ans.push_back(dest);
            dest = parent[dest];
        }

        reverse(ans.begin(), ans.end());
        // printig the shortest path
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 3, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(3, 5, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(4, 6, 1);
    // g.addEdge(6, 7, 1);
    // g.printAdjList();
    // g.topoSortDFS(0);
    // g.printStack();
    // g.topoSortBFS(0);

    g.addEdge(0, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.shortestPathBFS(0, 3);
}
