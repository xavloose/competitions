#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define CLR(i,x) memset(i,x,sizeof(i))
#define clr0(i) CLR(i,0)
#define M(x) ((x)%MOD)
#define fst first
#define snd second

constexpr int N = 500005, NP = 41538;
int MOD, primes[NP], parent[N], size[N], powers[NP];
vector<pii> factors[N];

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

ll mod_pow(ll a, ll b) {
	if (!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

ll work() {
	int n;
	scanf("%d%d", &n, &MOD);

	clr0(powers);
	rep (x, n) for (auto & pp : factors[x])
		powers[pp.fst] += pp.snd;

	rep (i, n - 1) {
		scanf("%d", parent + i + 1);
		parent[i + 1]--;
	}

	rep (i, n) size[i] = 1;
	for (int i = n - 1; i; i--) {
		size[parent[i]] += size[i];
		for (auto & pp : factors[size[i]])
			powers[pp.fst] -= pp.snd;
	}

	ll ans = 1;
	rep (pid, NP)
		ans = M(ans * mod_pow(primes[pid], powers[pid]));
	return ans;
}

int main() {
	sieve_with_factors(N, primes, factors);
	int t;
	scanf("%d", &t);
	while (t--) printf("%lld\n", work());
	return 0;
}
