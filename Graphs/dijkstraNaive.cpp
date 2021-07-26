#include<iostream>
#include<utility>
#include<vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

vector<int> dijkstra(vector<pair<int, int>> adj[], int V, int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> finalised(V, false);
    for(int count = 0; count < V-1; count++)
    {
        int u = -1;
        for(int i = 0; i < V; i++)
        {
            if(finalised[i] == false && (u==-1 || dist[i] < dist[u]))
                u = i;
        }

        finalised[u] = true;

        for(auto node : adj[u])
        {
            int v = node.first;
            int weight = node.second;
            if(finalised[v] == false && dist[v] > dist[u]+weight)
                dist[v] = dist[u] + weight;
        }
    }
    return dist;
}


int main()
{
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 11);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 2, 4, 7);
    addEdge(adj, 2, 5, 1);
    addEdge(adj, 3, 4, 2);
    addEdge(adj, 3, 6, 7);
    addEdge(adj, 3, 7, 4);
    addEdge(adj, 4, 5, 6);
    addEdge(adj, 5, 7, 2);
    addEdge(adj, 6, 7, 14);
    addEdge(adj, 6, 8, 9);
    addEdge(adj, 7, 8, 10);
    
    vector<int> sd = dijkstra(adj, V, 0);
    for(int d : sd)
        cout << d << " ";
    return 0;
}