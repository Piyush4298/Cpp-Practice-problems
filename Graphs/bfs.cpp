#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfsUtil(vector<int> adj[], int s, bool visited[])
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int u : adj[node])
        {
            if(visited[u] == false)
            {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

void BFS(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    for(int i = 0; i < V; i++)
    {
        if(visited[i] == false)
            bfsUtil(adj, i, visited);
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
    BFS(adj, V);

    return 0;
}