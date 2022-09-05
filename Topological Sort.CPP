vector<int> topo;

// Kahn's algorithm
bool topoSort(int n) {
	topo.clear();
	vector<int> indeg(n + 5);
	for (int i = 1; i <= n; i++) {
		for (auto& it : adj[i]) {
			++indeg[it];
		}
	}
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indeg[i] == 0) {
			q.push(i);
		}
	}
	int no_of_node = 0;
	while (!q.empty()) {
		int node = q.front();
		q.pop();
		topo.push_back(node);
		++no_of_node;
		for (auto& it : adj[node]) {
			--indeg[it];
			if (indeg[it] == 0) q.push(it);
		}
	}
	return no_of_node == n;
}
