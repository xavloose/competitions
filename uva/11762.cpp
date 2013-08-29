#include <cstdio>
#include <vector>

using namespace std;

#define MAX 1000005

vector<int> f[MAX];
int n, T, p[MAX];
double dp[MAX];

int main()
{
	for( int i = 2; i < MAX; i++ ) p[i] = 1;
	for( int i = 2; i < MAX; i++ ) if( p[i] )
	{
		for( int j = 2*i; j < MAX; j += i ) p[j] = 0;
		for( int j = i; j < MAX; j += i ) f[j].push_back(i);
	}
	int cnt = 0;
	for( int i = 2; i < MAX; i++ )
	{
		cnt += p[i];
		for( int j = 0; j < f[i].size(); j++ ) dp[i] += dp[i/f[i][j]];
		dp[i] = ( cnt + dp[i] ) / f[i].size();
	}
	scanf( "%d", &T );
	for( int t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		printf( "Case %d: %.10f\n", t, dp[n] );
	}
	return 0;
}
