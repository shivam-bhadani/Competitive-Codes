/* JAI SHREE RAM */
/*
    Author: Shivam Bhadani (@Shivam28nov)
    Linkedin: https://www.linkedin.com/in/shivambhadani
    Github: https://github.com/shivam-bhadani
*/
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*----------------------------------------TYPEDEF--------------------------------------------------------------------------------------------------------------------------------------------*/
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
template <class T>
using ordered_set =  __gnu_pbds::tree<T,__gnu_pbds::null_type,less<T>,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

/*----------------------------------------MACROS------------------------------------------------------------------------------------------------------------------------------------------*/
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define foi(n) for(ll i=0; i<(n); i++)
#define loop(i, k, n) for(ll (i)=(k); (i)<=(n); (i)++)
#define loopr(i, k, n) for(ll (i)=(k); (i)>=(n); (i)--)
#define inp(v) for(auto &x:v) cin>>x
#define output(v) for(auto &x:v) cout<<x<<" "; cout<<'\n'
#define ps(x,y) fixed<<setprecision(y)<<x
#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define pm cout<<"-1\n"

/*----------------------------------------MATHEMATICAL FUNCTIONS----------------------------------------------------------------------------------------------------------------------------------------*/
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll m) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % m; a = (a * a) % m; b = b >> 1;} return res;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPrime(ll n) {if (n<=1) return false; for (ll i=2; i*i<=n; i++) {if (n%i==0) return false;} return true;}

/*----------------------------------------DEBUG----------------------------------------------------------------------------------------------------------------------------------------------------------*/
#ifdef Shivam28nov
#define dbg(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define dbg(x);
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(ordered_set<T> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*----------------------------------------CONSTANTS------------------------------------------------------------------------------------------------------------------------------------------------------*/
const int MOD = 1000000007;
const int MOD1 = 998244353;
const ll INF = 1e18;
const int N = 200005;
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void run_case();

int32_t main() {
#ifdef Shivam28nov
    freopen("Error.txt", "w", stderr);
#endif
    fastio();

    ll test_cases=1;                   
    // cin >> test_cases;
    while(test_cases--){
        run_case();
    }
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
}

void run_case() {
    int n; cin >> n;
    vector<ll> a(n); inp(a);
    ll ans = 0;
    for(int i=0; i<n; i+=2) { // start from opening
    	ll have = a[i];
    	ll prefSum = 0;
    	for(int j=i+1; j<n; j++) { // end at closing
    		if(have<=0) break;
    		if(j%2==0) {
    			prefSum += a[i];
    		}
    		else {
    			prefSum += a[i];
    			if(prefSum>0) {
    				prefSum -= a[i];
    				have -= a[i];
    				if(have>=0) {
    					ans += a[i];
    				}
    			}
    			else {
    				ans += have;
    				break;
    			}
    		}
    	}
    }
    cout << ans;
}