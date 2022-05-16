class SegTree {
public:
    vector<ll> st;
    ll ID = 0; // change this
    int n = 0;
    SegTree(int s) {
        n = s;
        st.assign(4*n+5, ID);
    }

    void merge(ll& curr, ll& a, ll& b) { // change this
        curr = a + b;
    }

    void Build(int node, int L, int R, vector<ll>& arr) {
        if(L==R) {
            st[node] = arr[L];
            return;
        }
        int M = (L + R) / 2;
        Build(2*node, L, M, arr);
        Build(2*node+1, M+1, R, arr);
        merge(st[node], st[2*node], st[2*node+1]);
    }

    void pUpdate(int node, int L, int R, int pos, ll val) {
        if(L==R) {
            st[node] = val;
            return;
        }
        int M = (L + R) / 2;
        if(pos<=M) {
            pUpdate(2*node, L, M, pos, val);
        }
        else {
            pUpdate(2*node+1, M+1, R, pos, val);
        }
        merge(st[node], st[2*node], st[2*node+1]);
    }

    ll Query(int node, int L, int R, int lo, int hi) {
        if(R<lo || L>hi) {
            return ID;
        }
        if(lo<=L && R<=hi) {
            return st[node];
        }
        int M = (L + R) / 2;
        ll lft = Query(2*node, L, M, lo, hi);
        ll rght = Query(2*node+1, M+1, R, lo, hi);
        ll curr = ID;
        merge(curr, lft, rght);
        return curr;
    }

    ll pQuery(int node, int L, int R, int pos) {
        if(L==R) {
            return st[node];
        }
        int M = (L + R) / 2;
        if(pos<=M) {
            return pQuery(2*node, L, M, pos);
        }
        else {
            return pQuery(2*node+1, M+1, R, pos);
        }
    }

    void build(vector<ll>& arr) {
        Build(1, 1, n, arr);
    }

    void update(int pos, ll val) {
        pUpdate(1, 1, n, pos, val);
    }

    ll query(int lo, int hi) {
        return Query(1, 1, n, lo, hi);
    }

    ll query(int pos) {
        return pQuery(1, 1, n, pos);
    }
};