int disc[N], low[N];
vector<pair<int, int>> bridges;

void dfs(int node, int par) {
    vis[node] = 1;
    disc[node] = low[node] = timer++;
    for (auto& it : adj[node]) {
        if (it == par) continue;
        if (!vis[it]) {
            dfs(it, node);
            low[node] = min(low[node], low[it]);
            if (low[it] > disc[node]) {
                bridges.push_back({node, it});
            }
        }
        else {
            low[node] = min(low[node], low[it]);
        }
    }
}