class SegTree {
public:
    vector<ll> segs;
    ll size = 0;
    ll ID = -INF; // change this
 
    SegTree(ll sz) {
        segs.assign(2 * sz, ID);
        size = sz;  
    }   
   
    ll comb(ll a, ll b) { // change this
        return max(a, b);  
    }
 
    void upd(ll idx, ll val) {
        segs[idx += size] = val;
        for(idx >>= 1; idx; idx >>= 1) segs[idx] = comb(segs[idx<<1], segs[idx<<1 | 1]);
    }
 
    ll query(ll l, ll r) {
        ll lans = ID, rans = ID;
        for(l += size, r += size + 1; l < r; l >>= 1, r >>= 1) {
            if(l & 1) lans = comb(lans, segs[l++]);
            if(r & 1) rans = comb(segs[--r], rans);
        }
        return comb(lans, rans);
    }
};