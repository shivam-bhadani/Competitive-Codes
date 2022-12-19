vector<ll> phi(N);

void totient() {
	for (int i = 0; i < N; i++) {
		phi[i] = i;
	}
	for (int i = 2; i < N; i++) {
		if (phi[i] == i) {
			for (int j = i; j < N; j += i) {
				phi[j] *= (i - 1);
				phi[j] /= i;
			}
		}
	}
}