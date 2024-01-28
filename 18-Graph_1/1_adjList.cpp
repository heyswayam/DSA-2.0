#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Graph
{
public:
    map<T, list<T>> edgeList;
    void addEdge(T u, T v, int direction)
    {
        if (direction == 1)
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

    void bfsTraversal(T src, unordered_map<char, bool> &vis)
    {
        queue<T> q;

        // unordered_map<T, bool> vis;
        q.push(src);
        vis[src] = true;
        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();

            for (auto &&i : edgeList[frontNode])
            {
                if (!vis[i])
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }

    void dfsTraversal(T src, unordered_map<T, bool> &vis){
        vis[src]=true;
        cout<<src<<" ";
        
        for (auto &&i : edgeList[src])
        {
            if(!vis[i]){
                dfsTraversal(i,vis);
            }
        }
        
    }
};

int main()
{
    Graph<char> g;
    g.addEdge('a', 'b', 1);
    // g.addEdge('a', 'c', 0);
    g.addEdge('c', 'd', 1);
    g.addEdge('c', 'e', 1);
    g.addEdge('d', 'e', 1);
    g.addEdge('e', 'f', 1);
    g.addEdge('g', 'h', 1);

    g.printAdjList();
    // g.bfsTraversal('a');
    // g.dfsTraversal('a',vis);

    //to handle disconnected graph case use for loop for each node
    int countComponent = 0;
    unordered_map<char, bool> vis;
    for (char i = 'a'; i <= 'h'; i++)
    {
        if (!vis[i])
        {
            vis[i]=true;
            // g.bfsTraversal(i,vis);
            g.dfsTraversal(i,vis);
            countComponent++;

        }
    }
    cout<<countComponent<<endl;
    return 0;
}