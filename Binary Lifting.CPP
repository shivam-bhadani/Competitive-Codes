// Tree is 1-based index
// Give k-th parent of any node in O(logk) time

class BinaryLifting {
public:
	ll n;
	ll mxLog;
	ll ID = -1;
	vector<vector<ll>> table;

	BinaryLifting(int s) {
		n = s;
		mxLog = log2(n+1);
		table.resize(n+5);
		for(int i=0; i<=n+1; i++) {
			table[i].assign(mxLog+1, ID);
		}
	}

	void build(int root, vector<int> adj[]) {
		dfsBL(root, -1, adj);
		for(int i=1; i<=mxLog; i++) {
			for(int j=1; j<=n; j++) {
				int intermidiate = table[j][i-1];
				if(intermidiate!=ID) {
					table[j][i] = table[intermidiate][i-1];
				}
			}
		}
	}

	void dfsBL(int node, int par, vector<int> adj[]) {
		for(auto& it: adj[node]) {
			if(it==par) continue;
			table[it][0] = node;
			dfsBL(it, node, adj);
		}
	}

	int kthParent(int node, int k) {
		for(int i=0; i<=mxLog; i++) {
			if(k & (1<<i)) {
				node = table[node][i];
				if(node==ID) {
					return node;
				}
			}
		}
		return node;
	}
};