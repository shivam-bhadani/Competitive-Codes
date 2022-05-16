class SegTree {
public:
    vector<ll> st;
    vector<ll> lazy;
    vector<bool> isLazy;
    ll ID = 0; // change this
    int n = 0;
    SegTree(int s) {
        n = s;
        st.assign(4*n+5, ID);
        lazy.assign(4*n+5, ID);
        isLazy.assign(4*n+5, false);
    }

    void merge(ll& curr, ll& a, ll& b) { // change this
        curr = a + b;
    }

    void propogate(int node, int L, int R) { // change this
        if(L!=R) {
            isLazy[2*node] = 1;
            isLazy[2*node + 1] = 1;
            lazy[2*node] = lazy[node];
            lazy[2*node + 1] = lazy[node];
        }
        st[node] = (R-L+1)*lazy[node];
        lazy[node] = ID;
        isLazy[node] = 0;
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
        if(isLazy[2*node]) {
            propogate(2*node, L, M);
        }
        if(isLazy[2*node+1]) {
            propogate(2*node+1, M+1, R);
        }
        if(pos<=M) {
            pUpdate(2*node, L, M, pos, val);
        }
        else {
            pUpdate(2*node+1, M+1, R, pos, val);
        }
        merge(st[node], st[2*node], st[2*node+1]);
    }

    void Update(int node, int L, int R, int lo, int hi, ll val) {
        if(R<lo || L>hi) {
            return;
        }
        if(lo<=L && R<=hi) {
            isLazy[node] = 1;
            lazy[node] = val;
            propogate(node, L, R);
            return;
        }
        int M = (L + R) / 2;
        if(isLazy[2*node]) {
            propogate(2*node, L, M);
        }
        if(isLazy[2*node+1]) {
            propogate(2*node+1, M+1, R);
        }
        Update(2*node, L, M, lo, hi, val);
        Update(2*node+1, M+1, R, lo, hi, val);
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
        if(isLazy[2*node]) {
            propogate(2*node, L, M);
        }
        if(isLazy[2*node+1]) {
            propogate(2*node+1, M+1, R);
        }
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
        if(isLazy[2*node]) {
            propogate(2*node, L, M);
        }
        if(isLazy[2*node+1]) {
            propogate(2*node+1, M+1, R);
        }
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

    void update(int l, int r, ll val) {
        Update(1, 1, n, l, r, val);
    }

    ll query(int lo, int hi) {
        return Query(1, 1, n, lo, hi);
    }

    ll query(int pos) {
        return pQuery(1, 1, n, pos);
    }
};