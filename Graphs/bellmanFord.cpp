#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int u, v, w;
    Node(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
void addEdge(vector<Node> &graph, int u, int v, int w)
{
    graph.push_back(Node(u, v, w));
}

void bellmanFord(vector<Node> &graph, int V, int src)
{
    vector<int> dist(V, 100000);
    dist[src] = 0;
    for(int i = 1; i <= V-1; i++)
    {
        for(auto it : graph)
        {
            if(dist[it.v] > dist[it.u] + it.w)
                dist[it.v] = dist[it.u] + it.w;
        }
    }

    bool flag = false;
    for(auto it : graph)
    {
        if(dist[it.v] > dist[it.u] + it.w)
        {
            flag = true;
            cout << "Negative cycle detected!";
            break;
        }
    }

    if(!flag)
    {
        for(int d : dist)
            cout << d << " ";
    }
}

int main()
{
    int V = 6;
    vector<Node> graph;
    addEdge(graph, 0, 1, 5);
    addEdge(graph, 1, 2, -2);
    addEdge(graph, 1, 5, -3);
    addEdge(graph, 2, 4, 3);
    addEdge(graph, 3, 2, 6);
    addEdge(graph, 3, 4, -2);
    addEdge(graph, 5, 3, 1);

    bellmanFord(graph, V, 0);
    return 0;
}