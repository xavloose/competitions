#include <algorithm>
#include <iostream>

using namespace std;

#define N 10
#define M 100

int a[N], d[1<<N], m, n;
bool ok[1<<N], b[M];

bool check( int s )
{
	for( int i = 1; i <= m; i++ )
	{
		bool ok = true;
		int mod = -1;
		for( int j = 0; j < n && ok; j++ ) if( ( s >> j ) & 1 )
		{
			if( mod == -1 ) mod = a[j] % i;
			else if( ( a[j] % i ) != mod ) ok = false;
		}
		if( !ok ) continue;
		for( int j = mod; j < m && ok; j += i ) if( !b[j] ) ok = false;
		if( ok ) return true;
	}
	return false;
}

bool run()
{
	cin >> m >> n;
	if( cin.fail() ) return false;
	for( int i = 0; i < M; i++ ) b[i] = false;
	for( int i = 0; i < n; i++ ) cin >> a[i], b[a[i]] = true;

	int k = 1<<n;
	for( int i = 1; i <= k; i++ ) ok[i] = check(i), d[i] = n;
	for( int i = 0; i < k; i++ ) for( int j = 0; j < k; j++ ) if( ok[j] )
		d[i|j] = min( d[i|j], d[i] + 1 );
	cout << d[k-1] << endl;
	return true;
}

int main()
{
	while(run());
	return 0;
}
