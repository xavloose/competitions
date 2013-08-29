#include <algorithm>
#include <iostream>

using namespace std;

#define N 9

int p[N+1];
bool g[N][N];

int main()
{
	int n, m;
	cin >> n >> m;
	for( int i = 0; i < m; i++ )
	{
		int a, b;
		cin >> a >> b;
		g[a][b] = true;
	}

	int ans = 0;
	for( int i = 1; i < 1<<n; i++ )
	{
		int k = 0;
		for( int j = 0; j < n; j++ ) if( ( i >> j ) & 1 ) p[k++] = j;
		p[k] = p[0];
		do
		{
			bool ok = true;
			for( int j = 0; j < k && ok; j++ ) if( !g[p[j]][p[j+1]] ) ok = false;
			ans += ok;
		}
		while( next_permutation( p + 1, p + k ) );
	}
	cout << ans << endl;

	return 0;
}
