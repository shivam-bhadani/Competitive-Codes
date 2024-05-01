ll dis[N];
void dijkstra(int n) {
	for (int i = 0; i <= n; i++) {
		dis[i] = INF;
	}
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	pq.push({0, 1});
	dis[1] = 0;
	while (!pq.empty()) {
		int node = pq.top().second;
		ll curDis = pq.top().first;
		pq.pop();
		if (dis[node] < curDis) continue;
		for (auto& it : adj[node]) {
			int nxtNode = it.first;
			ll nxtDis = it.second + curDis;
			if (dis[nxtNode] > nxtDis) {
				dis[nxtNode] = nxtDis;
				pq.push({nxtDis, nxtNode});
			}
		}
	}
}
