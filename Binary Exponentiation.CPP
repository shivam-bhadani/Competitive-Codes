// Time - O(log(n)) a <= 1e9

ll expo(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % m;
		a = (a * a) % m;
		b = b >> 1;
	}
	return res;
}

// Time - O(log^2(n)) Use this for very large input of a

ll binMultiply(ll a, ll b, ll m) {
	ll ans = 0;
	while (b) {
		if (b & 1) {
			ans = (ans + a) % m;
		}
		a = (a + a) % m;
		b >>= 1;
	}
	return ans;
}

ll expo(ll a, ll b, ll m) {
	ll ans = 1;
	while (b) {
		if (b & 1) {
			ans = binMultiply(ans, a, m);
		}
		a = binMultiply(a, a, m);
		b >>= 1;
	}
	return ans;
}
