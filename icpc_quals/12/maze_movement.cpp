#include <iostream>

using namespace std;

#define N 1005
#define INF 1234567890

int n, a[N], g[N][N], f[N][N];
bool seen[N];

int dfs( int s, int t, int minf )
{
	if( s == t ) return minf;
	if( seen[s] ) return 0;
	seen[s] = true;
	for( int i = 0; i < n; i++ )
	{
		if( g[s][i] == f[s][i] ) continue;
		int minf2 = min( minf, g[s][i] - f[s][i] );
		minf2 = min( minf2, dfs( i, t, minf2 ) );
		if( minf2 )
		{
			f[s][i] += minf2;
			f[i][s] -= minf2;
			return minf2;
		}
	}
	return 0;
}

int max_flow( int s, int t )
{
	for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) f[i][j] = 0;
	do for( int i = 0; i < n; i++ ) seen[i] = false;
	while( dfs( s, t, INF ) );
	int ans = 0;
	for( int i = 0; i < n; i++ ) ans += f[s][i];
	return ans;
}

int gcd( int a, int b )
{
	while( b != 0 )
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	cin >> n;
	int lo = 0, hi = 0;
	for( int i = 0; i < n; i++ )
	{
		cin >> a[i];
		if( a[i] < a[lo] ) lo = i;
		if( a[i] > a[hi] ) hi = i;
	}
	for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ )
	{
		int x = gcd( a[i], a[j] );
		if( x > 1 ) g[i][j] = x;
	}
	cout << max_flow( lo, hi ) << endl;
	return 0;
}
