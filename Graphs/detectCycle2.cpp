/*Detect cycle in directed graph*/
#include<iostream>
#include<queue>
#include<utility>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

bool isCycle(vector<int> adj[], int V)
{
    queue<int> q;
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++)
    {
        for(auto it : adj[i])
            indegree[it]++;
    }

    for(int i = 0; i < V; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for(auto u : adj[node])
        {
            indegree[u]--;
            if(indegree[u] == 0)
                q.push(u);
        }
    }

    return count!=V;
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 3);

    bool ans = isCycle(adj, V);
    cout << (ans == true?"Yes" : "No");
    return 0;
}