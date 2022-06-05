struct Data { // change this
	ll val;
	Data(ll x) {
		val = x;
	}
};

class SegTree {
public:
    vector<Data> st;
    vector<Data> lazy;
    vector<bool> isLazy;
    Data ID = Data(0); // change this
    int n = 0;
    SegTree(int s) {
        n = s;
        st.assign(4*n+5, ID);
        lazy.assign(4*n+5, ID);
        isLazy.assign(4*n+5, false);
    }

    void merge(Data& curr, Data& a, Data& b) { // change this
        curr.val = a.val + b.val;
    }

    void propogate(int node, int L, int R) { // change this
        if(L!=R) {
            isLazy[2*node] = 1;
            isLazy[2*node + 1] = 1;
            lazy[2*node] = lazy[node];
            lazy[2*node + 1] = lazy[node];
        }
        st[node].val = (R-L+1)*lazy[node].val;
        lazy[node] = ID;
        isLazy[node] = 0;
    }

    void Build(int node, int L, int R, vector<ll>& arr) {
        if(L==R) {
            st[node].val = arr[L];
            return;
        }
        int M = (L + R) / 2;
        Build(2*node, L, M, arr);
        Build(2*node+1, M+1, R, arr);
        merge(st[node], st[2*node], st[2*node+1]);
    }

    void pUpdate(int node, int L, int R, int pos, ll val) {
        if(L==R) {
            st[node].val = val;
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
            lazy[node].val = val;
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

    Data Query(int node, int L, int R, int lo, int hi) {
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
        Data lft = Query(2*node, L, M, lo, hi);
        Data rght = Query(2*node+1, M+1, R, lo, hi);
        Data curr = ID;
        merge(curr, lft, rght);
        return curr;
    }

    Data pQuery(int node, int L, int R, int pos) {
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

    Data query(int lo, int hi) {
        return Query(1, 1, n, lo, hi);
    }

    Data query(int pos) {
        return pQuery(1, 1, n, pos);
    }
};