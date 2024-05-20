// Time = O(logn)

class LCA {
public:
	ll n;
	ll mxLog;
	ll ID = -1;
	vector<vector<ll>> table;
	vector<ll> level;

	LCA(int s) {
		n = s;
		mxLog = log2(n + 1);
		table.resize(n + 5);
		for (int i = 0; i <= n + 1; i++) {
			table[i].assign(mxLog + 1, ID);
		}
		level.resize(n + 5);
	}

	void build(int root, vector<int> adj[]) {
		dfsBL(root, -1, adj);
		for (int i = 1; i <= mxLog; i++) {
			for (int j = 1; j <= n; j++) {
				int intermidiate = table[j][i - 1];
				if (intermidiate != ID) {
					table[j][i] = table[intermidiate][i - 1];
				}
			}
		}
		dfsLCA(root, -1, adj);
	}

	void dfsBL(int node, int par, vector<int> adj[]) {
		for (auto& it : adj[node]) {
			if (it == par) continue;
			table[it][0] = node;
			dfsBL(it, node, adj);
		}
	}

	void dfsLCA(int node, int par, vector<int> adj[]) {
		for (auto& it : adj[node]) {
			if (it == par) continue;
			level[it] = 1 + level[node];
			dfsLCA(it, node, adj);
		}
	}

	int kthParent(int node, int k) {
		for (int i = 0; i <= mxLog; i++) {
			if (k & (1 << i)) {
				node = table[node][i];
				if (node == ID) {
					return node;
				}
			}
		}
		return node;
	}

	int getLCA(int a, int b) {
		if (level[a] > level[b]) {
			swap(a, b);
		}
		b = kthParent(b, level[b] - level[a]);
		if (a == b) return a;
		for (int i = mxLog; i >= 0; i--) {
			int p1 = table[a][i];
			int p2 = table[b][i];
			if (p1 != p2 && p1 != -1 && p2 != -1) {
				a = p1;
				b = p2;
			}
		}
		return table[a][0];
	}
};