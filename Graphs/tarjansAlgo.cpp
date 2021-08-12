#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

void dfs(vector<int> adj[], int u, vector<int> &disc, vector<int> &low, vector<bool> &inStack, stack<int> &st)
{
    static int timer = 0;
    disc[u] = low[u] = timer;
    timer += 1;
    st.push(u);
    inStack[u] = true;
    for(auto v : adj[u])
    {
        if(disc[v] == -1)
        {
            dfs(adj, v, disc, low, inStack, st);
            low[u] = min(low[u], low[v]); 
        }
        else if(inStack[v])
            low[u] = min(low[u], disc[v]);
    }

    if(disc[u] == low[u])
    {
        cout << "SCC: ";
        while(st.top() != u)
        {
            cout << st.top() << " ";
            inStack[st.top()] = false;
            st.pop();
        }
        cout << st.top() << "\n";
        inStack[st.top()] = false;
        st.pop();
    }
}

void TarjansAlgo(vector<int> adj[], int V)
{
    vector<int> disc(V, -1), low(V, -1);
    vector<bool> inStack(V, false);
    stack<int> st;
    for(int i = 0; i < V; i++)
    {
        if(disc[i] == -1)
            dfs(adj, i, disc, low, inStack, st);
    }
}

int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 2);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 5);

    TarjansAlgo(adj, V);
    return 0;
}