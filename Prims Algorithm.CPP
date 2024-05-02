int vis[N];
vector<pair<int, int>> tree[N];
ll totalMSTWeight = 0;

bool prims() {
	totalMSTWeight = 0;
	priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> pq; // {wt, node, par}
	pq.push({0, 1, -1});
	while (!pq.empty()) {
		ll wt = pq.top()[0];
		int node = pq.top()[1];
		int parent = pq.top()[2];
		pq.pop();
		if (vis[node]) continue;
		vis[node] = 1;
		totalMSTWeight += wt;
		if (parent != -1) {
			tree[parent].push_back({node, wt});
		}
		for (auto& it : adj[node]) {
			if (!vis[it.first]) {
				pq.push({it.second, it.first, node});
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			return 0;
		}
	}
	return 1;
}