#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// ----------------- Adjacency Matrix -----------------
void UNGA(int n, int m) {
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// ----------------- Adjacency List -----------------
void UNGL(int n, int m) {
    vector<int> adj[n + 1];

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (auto x : adj[i]) cout << x << " ";
        cout << endl;
    }
}

// ----------------- BFS -----------------
vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> bfs;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for (auto it : adj[node]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}

// ----------------- DFS -----------------
void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls) {
    vis[node] = 1;
    ls.push_back(node);

    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, adj, vis, ls);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> ls;

    dfs(0, adj, vis, ls);
    return ls;
}