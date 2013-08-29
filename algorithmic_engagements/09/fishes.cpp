#include <cstdio>
#include <map>
#include <vector>

using namespace std;

#define N 1005
#define M 10005

char buf[M];
int zone[N][N], path[M], nf;
map< vector<int>, int > id;
vector<int> fish[N];

void push( int * & s, int * & t, int x )
{
	if( t > s && *(t-1) == -x ) t--;
	else *(t++) = x;
}

int min_rot( int * s, int * t )
{
	int n = t - s, ans = 0, cur = 1, len = 0;
	while( cur < n && ans + len + 1 < n )
	{
		if( s[ans+len] < s[(cur+len)%n] )
		{
			cur = cur + len + 1;
			len = 0;
		}
		else if( s[ans+len] > s[(cur+len)%n] )
		{
			ans = max( ans + len + 1, cur );
			cur = ans + 1;
			len = 0;
		}
		else len++;
	}
	return ans;
}

vector<int> get_canonical( int * s, int * t )
{
	if( s >= t ) return vector<int>();
	int n = t - s, rot = min_rot( s, t );
	vector<int> ans( n );
	for( int i = 0; i < n; i++ ) ans[i] = s[(i+rot)%n];
	return ans;
}

void process_path( int path_num )
{
	int x, y, len, * s = path, * t = path;
	scanf( "%d%d%d%s", &x, &y, &len, buf );

	x--, y--;
	for( int i = 0; i < len; i++ )
	switch( buf[i] )
	{
		case 'N': y--; push( s, t, -zone[y][x] ); break;
		case 'S': push( s, t, zone[y][x] ); y++; break;
		case 'E': x++; break;
		case 'W': x--; break;
	}
	while( s < t && *s == -*(t-1) ) s++, t--;

	vector<int> canon = get_canonical( s, t );
	if( !id.count( canon ) ) id[canon] = nf++;
	fish[id[canon]].push_back( path_num );
}

int main()
{
	int w, h, zone_id = 0;
	scanf( "%d%d", &w, &h );
	for( int y = 0; y < h; y++ )
	{
		scanf( "%s", buf );
		zone[y][0] = ++zone_id;
		for( int x = 1; x < w; x++ )
		{
			if( buf[x] == '#' && buf[x-1] == '.' ) zone_id++;
			zone[y][x] = zone_id;
		}
	}

	int n;
	scanf( "%d", &n );
	for( int i = 1; i <= n; i++ ) process_path( i );

	printf( "%d\n", nf );
	for( int i = 0; i < nf; i++ )
	{
		for( int j = 0; j + 1 < fish[i].size(); j++ )
			printf( "%d ", fish[i][j] );
		printf( "%d\n", fish[i].back() );
	}

	return 0;
}
