#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void topoSort(vector<int> adj[], int s, bool visited[], stack<int> &st)
{
    visited[s] = true;
    for(auto node : adj[s])
    {
        if(visited[node] == false)
            topoSort(adj, node, visited, st);
    }
    st.push(s);
}

void reverseDFS(vector<int> transposed[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for(auto node : transposed[s])
    {
        if(visited[node] == false)
            reverseDFS(transposed, node, visited);
    }
}

void kosarajusAlgo(vector<int> adj[], int V)
{
    bool visited[V] = {false};
    stack<int> st;
    for(int i = 0; i < V; i++){
        if(visited[i] == false)
        {
            topoSort(adj, i, visited, st);
        }
    }
    
    vector<int> transposed[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        for(auto node : adj[i])
        {
            transposed[node].push_back(i);
        }
    }

    while(!st.empty())
    {
        int node = st.top();
        st.pop();
        if(visited[node] == false)
        {
            cout << "SCC : ";
            reverseDFS(transposed, node, visited);
            cout << endl;
        }
    }

}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);

    kosarajusAlgo(adj, V);
    return 0;
}