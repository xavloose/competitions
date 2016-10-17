#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define range(i,a,b) for(auto i=(a);i<(b);i++)
#define rep(i,n) range(i,0,n)
#define all(c) begin(c),end(c)

struct FindingFriend {
int find(int m, vi xs, int y) {
	for (auto x : xs) if (x == y) return 1;
	int n = xs.size(), ans = 1, cur = 0;
	sort(all(xs));
	xs.push_back(n * m + 1);
	for (int i = n - 1; i >= 0; i--) {
		cur += xs[i + 1] - xs[i] - m;
		if (xs[i] < y) {
			if (cur == 0) break;
			ans++;
		}
	}
	return ans;
}
};
