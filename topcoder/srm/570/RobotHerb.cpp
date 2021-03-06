#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

struct RobotHerb
{
	ll getdist( int t, vector<int> a )
	{
		ll x = 0, y = 0;
		int d = 0;
		for( int i = 0; i < a.size(); i++ )
			x += dx[d] * a[i], y += dy[d] * a[i], d = ( d + a[i] ) % 4;
		if( d == 0 ) return t * ( abs( x ) + abs( y ) );
		if( d == 2 ) return t % 2 ? abs( x ) + abs( y ) : 0;
		if( t % 4 == 0 ) return 0;
		if( t % 4 == 2 ) return abs( x + y ) + abs( x - y );
		return abs( x ) + abs( y );
	}
};
