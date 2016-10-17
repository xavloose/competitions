typedef long long ll;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define M(x) ((x)%MOD)

constexpr ll MOD = 1000000007, N = 5005;

ll choose[N][N], tree[N], forest[N];

ll mod_pow(ll a, ll b) {
	if(!b) return 1;
	return M(mod_pow(M(a * a), b / 2) * (b % 2 ? a : 1));
}

struct CrazyFunctions {
int count(int n, int k) {
	int m = n - k;

	rep (i, m + 1) choose[i][0] = 1;
	range (i, 1, m + 1) range (j, 1, i + 1)
		choose[i][j] = M(choose[i-1][j] + choose[i-1][j-1]);

	range (i, 1, m + 1)
		tree[i] = mod_pow(i, i - 1);

	forest[0] = 1;
	range (i, 1, m + 1) range (j, 1, i + 1)
		forest[i] = M(
			M(M(M(choose[i-1][j-1] * tree[j]) * k) * forest[i-j])
			+ forest[i]
		);

	ll ans = forest[m];
	rep (i, k) ans = M(ans * (n - i));
	return ans;
}
};
