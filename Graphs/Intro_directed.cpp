#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void printAdjacencyList(vector<int> adj[], int V)
{
    for(int i = 0; i < V; i++)
    {
        cout << i << "->";
        for(auto node : adj[i])
        {
            cout << node << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);

    printAdjacencyList(adj, V);
    return 0;
}