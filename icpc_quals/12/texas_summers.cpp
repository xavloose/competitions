#include <iostream>
#include <set>
#include <utility>

using namespace std;

#define N 2505

int x[N], y[N], e[N][N], d[N], p[N];

int main()
{
	int n;
	cin >> n;
	for( int i = 0; i < n; i++ ) cin >> x[i] >> y[i];
	cin >> x[n] >> y[n] >> x[n+1] >> y[n+1];
	n += 2;

	for( int i = 0; i < n; i++ ) for( int j = 0; j < i; j++ )
	{
		int dx = x[i] - x[j], dy = y[i] - y[j];
		e[i][j] = e[j][i] = dx * dx + dy * dy;
	}

	for( int i = 0; i < n - 1; i++ ) d[i] = -1;
	set< pair< int, int > > q;
	q.insert( make_pair( 0, n - 1 ) );
	while( !q.empty() )
	{
		int u = q.begin()->second, x = d[u];
		q.erase( q.begin() );
		for( int v = 0; v < n; v++ ) if( d[v] == -1 || d[v] > d[u] + e[u][v] )
		{
			q.erase( make_pair( d[v], v ) );
			d[v] = d[u] + e[u][v], p[v] = u;
			q.insert( make_pair( d[v], v ) );
		}
	}

	if( p[n-2] == n - 1 ) cout << '-' << endl;
	else for( int i = p[n-2]; i != n - 1; i = p[i] ) cout << i << endl;

	return 0;
}
