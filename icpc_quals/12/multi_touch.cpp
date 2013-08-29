#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define PI 3.141592653589793238462
#define all(x) (x).begin(),(x).end()
#define N 15
#define M 30

typedef char grid[N][M+1];

grid _a, _b;
int dx[] = { -1, 1, 0, 0 }, dy[] = { 0, 0, -1, 1 }, n;

struct pt
{ 
	double x, y;
	pt( double _x, double _y ) : x(_x), y(_y) {}
};

inline bool operator <( const pt & a, const pt & b )
{ return a.x < b.x || ( a.x == b.x && a.y < b.y ); }

struct grip
{
	vector<pt> pts;
	pt grip_pt;
	grip( grid );
};

void rec( grid g, int x, int y, vector<pt> & pts )
{
	if( x < 0 || x >= N || y < 0 || y >= M || g[x][y] == '.' ) return;
	pts.push_back( pt( x, y ) );
	g[x][y] = '.';
	for( int d = 0; d < 4; d++ ) rec( g, x + dx[d], y + dy[d], pts );
}

grip::grip( grid g ) : grip_pt( 0.0, 0.0 )
{
	for( int i = 0; i < N; i++ ) for( int j = 0; j < M; j++ )
	if( g[i][j] == 'X' )
	{
		vector<pt> pts2;
		rec( g, i, j, pts2 );
		int n2 = pts2.size();
		double x = 0, y = 0;
		for( int k = 0; k < n2; k++ )
			x += pts2[k].x, y += pts2[k].y;
		pts.push_back( pt( x / n2, y / n2 ) );
	}
	
	n = pts.size();
	for( int i = 0; i < n; i++ )
		grip_pt.x += pts[i].x, grip_pt.y += pts[i].y;
	grip_pt.x /= n, grip_pt.y /= n;
}

double d2( double x, double y )
{ return x * x + y * y; }

void match( grip & a, grip & b )
{
	sort( all( a.pts ) ), sort( all( b.pts ) );
	double diff = -1;
	vector<pt> opt;
	do
	{
		double d = 0;
		for( int i = 0; i < n; i++ )
			d += d2( a.pts[i].x - b.pts[i].x, a.pts[i].y - b.pts[i].y );
		if( diff == -1 || d < diff ) opt = b.pts, diff = d;
	}
	while( next_permutation( all( b.pts ) ) );
	b.pts = opt;
}

double pan_d( grip & a, grip & b )
{ return hypot( a.grip_pt.x - b.grip_pt.x, a.grip_pt.y - b.grip_pt.y ); }

double grip_spread( grip & a )
{
	double ans = 0;
	for( int i = 0; i < n; i++ )
		ans += hypot( a.pts[i].x - a.grip_pt.x, a.pts[i].y - a.grip_pt.y );
	return ans / n;
}

double zoom_d( grip & a, grip & b )
{ return grip_spread( b ) - grip_spread( a ); }

double touch_rot( grip & a, grip & b, int i )
{
	double dxa = a.pts[i].x - a.grip_pt.x, dya = a.pts[i].y - a.grip_pt.y;
	double dxb = b.pts[i].x - b.grip_pt.x, dyb = b.pts[i].y - b.grip_pt.y;
	if( ( dxa == 0 && dya == 0 ) || ( dxb == 0 && dyb == 0 ) ) return 0;
	double ans = atan2( dyb, dxb ) - atan2( dya, dxa );
	if( ans > PI ) ans -= 2 * PI;
	if( ans < -PI ) ans += 2 * PI;
	return ans;
}

double rot_d( grip & a, grip & b )
{
	double q = 0;
	for( int i = 0; i < n; i++ ) q += touch_rot( a, b, i );
	return q / n * grip_spread( a );
}

int main()
{
	for( int i = 0; i < N; i++ ) scanf( "%s%s", _a[i], _b[i] );
	grip a(_a), b(_b);
	match( a, b );
	double pan = pan_d( a, b ), zoom = zoom_d( a, b ), rot = rot_d( a, b );
	double d = pan;
	string ans = "pan";
	if( abs( zoom ) > d )
	{
		if( zoom > 0 ) ans = "zoom out";
		else ans = "zoom in";
		d = abs( zoom );
	}
	if( abs( rot ) > d )
	{
		if( rot > 0 ) ans = "rotate counter-clockwise";
		else ans = "rotate clockwise";
	}

	printf( "%d %s\n", n, ans.c_str() );
	return 0;
}
