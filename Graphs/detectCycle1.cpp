/*Detect cycle in undirected graph*/
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool bfsCheckCycle(vector<int> adj[], int s, bool vis[])
{
    queue<pair<int, int>> q;
    vis[s] = true;
    q.push({s, -1});
    while(!q.empty())
    {
        int node = q.front().first;
        int par = q.front().second;
        q.pop();
        for(auto it : adj[node])
        {
            if(vis[it] == false)
            {
                vis[it] = true;
                q.push({it, node});
            }
            else if(par != it)
                return true;
        }
    }
    return false;
}

bool isCycle(vector<int> adj[], int V)
{
    bool vis[V] = {false};
    for(int i = 0; i < V; i++)
    {
        if(vis[i] == false)
            if(bfsCheckCycle(adj, i, vis))
                return true;
    }
    return false;
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 1);

    bool ans = isCycle(adj, V);

    cout << (ans == true ? "Yes" : "No"); 
    return 0;
}