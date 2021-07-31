#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bridgeDFS(vector<int> adj[], int s, int parent, vector<int> &disc, vector<int> &low, vector<bool> &vis, int &timer)
{
    vis[s] = true;
    disc[s] = low[s] = ++timer;
    for(auto node : adj[s])
    {
        if(node == parent)
            continue;
        if(vis[node] == false)
        {
            bridgeDFS(adj, node, s, disc, low, vis, timer);
            low[s] = min(low[s], low[node]);
            if(low[node] > disc[s])
                cout << s << " - " << node << endl;
        }
        else
            low[s] = min(low[s], disc[node]);
    }
}

void printBridges(vector<int> adj[], int V)
{
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> vis(V, false);

    int timer = 0;
    for(int i = 0; i < V; i++)
    {
        if(vis[i] == false)
        {
            bridgeDFS(adj, i, -1, disc, low, vis, timer);
        }
    }
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    printBridges(adj, V);
    return 0;
}