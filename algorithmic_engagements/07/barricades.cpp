#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

#define N 3005

vector<int> g[N];
short best[N][N], sz[N], tmp[2][N], ans[N];

void rec( int u, int p = -1 )
{
	foreach( v, g[u] ) if( *v != p ) rec( *v, u );

	sz[u]++;
	short * cur = tmp[0], * next = tmp[1];
	cur[1] = 0;
	foreach( v, g[u] ) if( *v != p )
	{
		for( int s = 1; s <= sz[u]; s++ ) next[s] = cur[s] + 1;
		for( int t = 1; t <= sz[*v]; t++ ) next[sz[u]+t] = N;

		for( int s = 1; s <= sz[u]; s++ )
		for( int t = 1; t <= sz[*v]; t++ )
			next[s+t] = min( next[s+t], (short) ( cur[s] + best[*v][t] ) );

		sz[u] += sz[*v];
		swap( cur, next );
	}
	for( int s = 1; s <= sz[u]; s++ ) best[u][s] = cur[s];
}

int main()
{
	int n, m;
	scanf( "%d", &n );

	for( int i = 1; i < n; i++ )
	{
		int a, b;
		scanf( "%d%d", &a, &b );
		a--, b--;
		g[a].push_back( b ), g[b].push_back( a );
	}

	rec( 0 );
	for( int s = 1; s <= n; s++ )
	{
		ans[s] = best[0][s];
		for( int i = 1; i < n; i++ ) if( sz[i] >= s )
			ans[s] = min( ans[s], (short) ( best[i][s] + 1 ) );
	}
	
	scanf( "%d", &m );
	while( m-- )
	{
		int k;
		scanf( "%d", &k );
		printf( "%d\n", ans[k] );
	}

	return 0;
}
