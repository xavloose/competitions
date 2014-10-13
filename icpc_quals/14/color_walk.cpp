#include <deque>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define range(i,a,b) for(auto i=(a);i<b;i++)
#define rep(i,n) range(i,0,n)
#define fst first
#define snd second

#define N 12

int n, cnt[N][1<<N];
bool ok[N][1<<N];
vi g[N][2], h[N][2];

bool works(int s)
{
	s = 1 << s;
	int t = s / 2;
	rep(v, n) rep(p, s)
		cnt[v][p] = g[v][p & 1].size();
	deque<pii> q;
	rep(v, n) rep(p, t)
	{
		ok[v][p] = cnt[v][p] && cnt[v][p + t];
		if(!ok[v][p]) q.emplace_back(v, p);
	}
	while(!q.empty())
	{
		int v = q.front().fst, p = q.front().snd;
		q.pop_front();
		rep(c, 2) for(auto u : h[v][c])
		{
			int r = c + 2 * p;
			cnt[u][r]--;
			if(!cnt[u][r])
			{
				r %= t;
				if(ok[u][r]) q.emplace_back(u, r);
				ok[u][r] = false;
			}
		}
	}
	rep(p, t) if(!ok[0][p]) return false;
	return true;
}

int run()
{
	cin >> n;
	int t;
	rep(i, n) rep(c, 2) g[i][c].clear(), h[i][c].clear();
	rep(c, 2) rep(i, n) rep(j, n)
	{
		cin >> t;
		if(t) g[i][c].push_back(j), h[j][c].push_back(i);
	}
	rep(i, n) if(works(i + 1)) return i + 1;
	return 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--) cout << run() << endl;
	return 0;
}
