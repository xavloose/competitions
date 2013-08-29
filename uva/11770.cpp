#include <cstdio>
#include <vector>

using namespace std;

#define REP(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) REP(i,0,n)
#define irep(i,n) REP(i,1,n+1)

#define MAX 10005

vector<int> g[MAX], h[MAX];
int T, n, m, a, b, c[MAX], nc, q[MAX], nq, p[MAX], ans;
bool seen[MAX];

void dfs1( int x )
{
	if(seen[x]) return;
	seen[x] = true;
	rep(y,g[x].size()) dfs1(g[x][y]);
	q[nq++] = x;
}

void dfs2( int x )
{
	if(c[x]>-1) return;
	c[x] = nc;
	rep(y,h[x].size()) dfs2(h[x][y]);
}

int main()
{
	scanf( "%d", &T );
	irep(t,T)
	{
		scanf( "%d%d", &n, &m );

		rep(i,n) g[i].clear(), h[i].clear();
		while(m--)
		{
			scanf( "%d%d", &a, &b );
			a--, b--;
			g[a].push_back(b);
			h[b].push_back(a);
		}

		nq = 0;
		rep(i,n) seen[i] = false;
		rep(i,n) dfs1(i);

		nc = 0;
		rep(i,n) c[i] = -1;
		for( int i = n-1; i >= 0; i-- ) if(c[q[i]]==-1)
		{
			dfs2(q[i]);
			nc++;
		}

		ans = nc;
		rep(i,nc) p[i] = 0;
		rep(i,n) rep(j,g[i].size()) if(c[i]!=c[g[i][j]]) p[c[g[i][j]]] = 1;
		rep(i,nc) ans -= p[i];

		printf( "Case %d: %d\n", t, ans );
	}
}
