vector<vector<ll>> capacity(N + 5, vector<ll>(N + 5));

int canReach(vector<int>& par, int src, int sink) {
	queue<int> q;
	q.push(src);
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto& it : adj[node]) {
			if (capacity[node][it] && par[it] == -1) {
				par[it] = node;
				q.push(it);
			}
		}
	}
	return par[sink] != -1;
}

ll maxFlow(int src, int sink, int n) {
	vector<int> par(n + 5, -1);
	ll ans = 0;
	while (canReach(par, src, sink)) {
		ll mn = INF;
		int node = sink;
		while (node != src) {
			int p = par[node];
			mn = min(mn, capacity[p][node]);
			node = p;
		}
		node = sink;
		while (node != src) {
			int p = par[node];
			capacity[p][node] -= mn;
			capacity[node][p] += mn;
			node = p;
		}
		ans += mn;
		fill(par.begin(), par.end(), -1);
	}
	return ans;
}