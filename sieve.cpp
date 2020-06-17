void sieve() {
    primes[1] = 1;
    for (ll i = 2; i < MAXN; i++) {
        primes[i] = i;
    }
    for (ll i = 4; i < MAXN; i += 2) {
        primes[i] = 2;
    }
    for (ll i = 3; i * i < MAXN; i++) {
        if (primes[i] == i) {
            for (ll j = i * i; j < MAXN; j += i) {
                if (primes[j] == j) {
                    primes[j] = i;
                }
            }
        }
    }
}
