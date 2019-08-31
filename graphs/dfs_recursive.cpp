#include <iostream>
#include <vector>
using namespace std;
void dfs(int u, vector<vector<int> > &adj, vector<bool> &visited) {
    visited[u] = true;
    for(int v : adj[u])
        if(!visited[v])
            dfs(v, adj, visited);
    cout << "Done visiting node: " << u + 1 << endl;
}

int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    vector<vector<int> > adj(nodes);
    vector<bool> visited(nodes);
    for(int i = 1; i <= edges; ++i) {
        cin >> u >> v;
        --u, --v;       //there is an undirected edge between u and v (0 based)
        adj[u].push_back(v);
        adj[v].push_back(u);
}

dfs(0, adj, visited);   //assume root is always node 0
return 0;
}