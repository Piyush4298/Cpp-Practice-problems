#include<iostream>
#include<utility>
#include<queue>
#include<vector>
using namespace std;

void addEdge(vector<pair<int, int>> adj[], int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int prims(vector<pair<int, int>> adj[], int V)
{
    int key[V];
    for(int i = 0; i < V; i++)
        key[i] = INT_MAX;
    
    key[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({key[0], 0});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto node : adj[u])
        {
            int v = node.first;
            int weight = node.second;
            if(weight < key[v])
                key[v] = weight, pq.push({key[v], v});
        }
    }
    int ans = 0;
    for(int d : key)
        ans += d;
    return ans;
}

int main()
{
    int V = 4;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 5);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 10);
    addEdge(adj, 1, 3, 15);

    cout << "Sum of weights in MST : " << prims(adj, V);
    
    return 0;
}