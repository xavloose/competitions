#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long ll;

constexpr int N = 100005;

int _[2][N], *xs = _[0], *ys = _[1];

ll merge(int a, int b, int c) {
	int *i = xs + a, *i_ = xs + b, *j = xs + b, *j_ = xs + c;
	ll ans = 0;
	for (int *k = ys + a; i < i_ || j < j_; k++) {
		if (j == j_ || (i < i_ && *i <= *j)) *k = *(i++);
		else *k = *(j++), ans += i_ - i;
	}
	return ans;
}

ll solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", xs + i);
	ll ans = 0;
	for (int l = 1; l < n; l *= 2) {
		for (int i = 0; i < n; i += 2 * l)
			ans += merge(i, min(i + l, n), min(i + 2 * l, n));
		swap(xs, ys);
	}
	return ans;
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) printf("%lld\n", solve());
	return 0;
}
