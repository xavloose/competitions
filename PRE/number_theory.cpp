// alternatively, use __gcd from <algorithm>
int gcd(int a, int b) {
	while (b) tie(a, b) = tup(b, a % b);
	return a;
}

void extended_euclidean(int a, int b, int & lx, int & ly) {
	int x = 0, y = 1;
	lx = 1, ly = 0;
	while (b) {
		int q = a / b;
		tie(a, b) = tup(b, a % b);
		tie(x, lx) = tup(lx - q * x, x);
		tie(y, ly) = tup(ly - q * y, y);
	}
}

// modulo inverse using the extended Euclidean algorithm
int mod_inv(int a, int m) {
	int lx, ly;
	extended_euclidean(a, m, lx, ly);
	if (lx < 0) lx += m;
	return lx;
}

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

// modulo inverse using exponentiation
ll mod_inv(int a) {
	return mod_pow(a, MOD - 2);
}

// Factorise a number, naively, in O(sqrt(n)).
vector<pair<ll, int>> factorise(ll n) {
	vector<pair<ll, int>> ans;
	for (ll f = 2; f * f <= n; f++) if (!(n % f)) {
		int p = 0;
		while (!(n % f)) n /= f, p++;
		ans.emplace_back(f, p);
	}
	if (n > 1) ans.emplace_back(n, 1);
	return ans;
}

// The number of divisors grows rather slowly. For example, for all n <= 10^9,
// d(n) <= 1344, where d(n) is the number of divisors of n. See
// "count_number_factors.cpp" for more information.
vll get_divisors(ll n) {
	vll ans;
	ll x = 1;
	for (; x * x < n; x++) if (!(n % x)) ans.push_back(x), ans.push_back(n / x);
	if (x * x == n) ans.push_back(x);
	sort(all(ans));
	return ans;
}

// A modified sieve of Eratosthenes which generates the smallest prime factor
// of each integer in [0, ..., n - 1]. This lookup allows us to factorise x
// in O(f), where f is the number of factors of x.
vi smallest_factor(int n) {
	vi ans(n);
	for (int p = 2; p * p < n; p++) if (!ans[p]) {
		ans[p] = p;
		for (int q = p * p; q < n; q += p)
			ans[q] = p;
	}
	return ans;
}

// This function computes the prime factorisation of each number less than n.
// One nice property is is that it runs in O(n * log(log(n))) as with the normal
// sieve.
//
// The computed data structures are:
//
//     1. An array of primes.
//     2. An array whose x-th entry is the factorisation of x.
//
// Here a factorisation of x is a vector of pairs, where the first entry of the
// pair is the index of the prime in the array of primes, and the second entry
// of the pair is the prime's power in x. I.e,
//
//     x = product(primes[pid] ^ power for (pid, power) in factorisation)
//
// We proceed to show some results about its complexity. Let Omega(n) denote the
// number of prime factors of n, with multiplicity. I.e., if we factor x as
// above, then
//
//	   Omega(x) = sum(power for (pid, power) in factorisation)
//
// Then the runtime of the function is
//
//	   O(sum(Omega(x) for x < n))
//
// Omega actually grows very slowly. Since Omega(x * y) = Omega(x) + Omega(y)
// and Omega(p) = 1 for each prime p, then Omega grows at least as slowly as
// the logarithm. So the above runtime is at most O(n * log(n)). In fact, we can
// reduce the bound much further.
//
// As with the normal sieve, we can rewrite the runtime using the prime harmonic
// along with an additional term -- the prime power harmonic:
//
//     O(n * [sum(1 / p for primes p < n) + sum(1 / q for prime powers q < n)])
//
// It is a well-known combinatorial result that the set of prime powers is small
// -- i.e., the sum of its reciprocals converges. Hence we can ignore it in the
// asymptotic expression above. The final complexity is thus just the same as
// that of the ordinary sieve: O(n * log(log(n))).
void sieve_with_factors(int n, int * primes, vector<pii> * factors) {
	int pid = 0;
	range (p, 2, n) if (factors[p].empty()) {
		primes[pid] = p;
		for (int x = p; x < n; x += p) {
			int power = 0;
			for (int y = x; (y % p) == 0; y /= p) power++;
			factors[x].emplace_back(pid, power);
		}
		pid++;
	}
}

// This not a function, but rather a technique for computing
// f(x) = g(x) - sum(f(y) for all y dividing x)
// This can be useful in many number theory problems (e.g. SRMs 603 and 626).
int g(int x) { /* dummy function */ return x; }
void divisor_summation(int n) {
	vll ds = get_divisors(n);
	int m = ds.size();
	vll f(m);
	rep (i, m) {
		ll x = ds[i];
		f[i] = M(g(x) - f[i] + MOD);
		range (j, i + 1, m) {
			ll y = ds[j];
			if (y % x) continue;
			cnt[j] = M(cnt[j] + cnt[i]);
		}
	}
}
