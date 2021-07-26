#include<iostream>
#include<utility>
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
    bool mstSet[V];
    for(int i = 0; i < V; i++)
        mstSet[i] = false, key[i] = INT_MAX;
    
    key[0] = 0;
    for(int count = 0; count < V-1; count++)
    {
        int minVal = INT_MAX, u;
        for(int i = 0; i < V; i++)
        {
            if(!mstSet[i] && key[i] < minVal)
                minVal = key[i], u = i;
        }

        mstSet[u] = true;

        for(auto node : adj[u])
        {
            int v = node.first;
            int weight = node.second;
            if(!mstSet[v] && key[v] > weight)
                key[v] = weight;
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