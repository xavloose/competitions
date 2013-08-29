#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define M 33

int x0[M], x1[M], y0[M], y1[M], x[M], y[M], r[M], nr, nc;

int main()
{
	int m, n;
	cin >> m;
	string line;
	getline( cin, line );
	for( int i = 0; i < m; i++ )
	{
		string type;
		getline( cin, line );
		istringstream iss( line );
		iss >> type;
		if( type[0] == 'r' )
		{
			iss >> x0[nr] >> y0[nr] >> x1[nr] >> y1[nr];
			nr++;
		}
		else
		{
			iss >> x[nc] >> y[nc] >> r[nc];
			nc++;
		}
	}
	cin >> n;
	while( n-- )
	{
		int a, b, ans = 0;
		cin >> a >> b;
		for( int i = 0; i < nr; i++ )
			ans += x0[i] <= a && a <= x1[i] && y0[i] <= b && b <= y1[i];
		for( int i = 0; i < nc; i++ )
			ans += ( a - x[i] ) * ( a - x[i] ) + ( b - y[i] ) * ( b - y[i] ) <= r[i] * r[i];
		cout << ans << endl;
	}
	return 0;
}
