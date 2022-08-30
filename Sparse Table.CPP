// Use for idempotent queries and answer those in O(1)

class SparseTable {
public:
    vector<vector<ll>> table;
    vector<ll> logValues;
    int mxLog, n;
    ll ID = INF;

    SparseTable(int s) {
        n = s;
        table.resize(n + 5);
        logValues.resize(n + 5);
        mxLog = log2(n);
        logValues[1] = 0;
        for (int i = 2; i <= n; i++) {
            logValues[i] = logValues[i / 2] + 1;
        }
        for (int i = 0; i < n; i++) {
            table[i].assign(mxLog + 1, ID);
        }
    }

    void merge(ll &curr, ll &a, ll &b) {
        curr = min(a, b);
    }

    void build(vector<ll>& a) {
        for (int i = 0; i < n; i++) {
            table[i][0] = a[i];
        }
        for (int j = 1; j <= mxLog; j++) {
            for (int i = 0; (i + (1 << j)) <= n; i++) {
                merge(table[i][j], table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    ll query(int L, int R) {
        int j = logValues[R - L + 1];
        ll ans = ID;
        merge(ans, table[L][j], table[R - (1 << j) + 1][j]);
        return ans;
    }
};