#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfsUtil(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for(auto node : adj[s])
    {
        if(visited[node] == false)
            dfsUtil(adj, node, visited);
    }
}

void DFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
            dfsUtil(adj, i, visited);
    }
}

int main()
{
    int V = 6;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    // given graph is disconnected!
    DFS(adj, V);

    return 0;
}