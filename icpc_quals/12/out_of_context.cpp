#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)
#define L 55

int n;
map< string, vector< string > > rules;
map< string, bool > mem[L][L];
string head, line;

bool rec( int i, int j, string s )
{
	if( mem[i][j].count( s ) ) return mem[i][j][s];
	bool & ans = mem[i][j][s];
	ans = false;
	if( s.size() == 0 )
		ans = j == 0;
	else if( s.size() == 1 )
	{
		if( 'a' <= s[0] && s[0] <= 'z' )
			ans = j == 1 && line[i] == s[0];
		else foreach( next, rules[s] ) if( rec( i, j, *next ) )
			ans = true;
	}
	else
	{
		if( 'a' <= s[0] && s[0] <= 'z' )
			ans = line[i] == s[0] && rec( i + 1, j - 1, s.substr( 1 ) );
		else for( int k = 0; k <= j; k++ )
		if( rec( i, k, s.substr( 0, 1 ) ) && rec( i + k, j - k, s.substr( 1 ) ) )
			ans = true;
	}
	return ans;
}

bool run()
{
	getline( cin, line );
	if( cin.fail() ) return false;
	n = line.size();
	for( int i = 0; i < n; i++ ) for( int j = 0; i + j <= n; j++ )
		mem[i][j].clear();
	int best_i = 0, best_j = 0;
	for( int i = 0; i < n; i++ ) for( int j = 0; i + j <= n; j++ )
	if( rec( i, j, head ) && j > best_j )
		best_i = i, best_j = j;
	cout << ( best_j ? line.substr( best_i, best_j ) : "NONE" ) << endl;
	return true;
}

int main()
{
	int m;
	cin >> m;
	string tmp, a, b, c;
	getline( cin, tmp );
	for( int i = 0; i < m; i++ )
	{
		getline( cin, tmp );
		istringstream is( tmp );
		is >> a >> b >> c;
		if( i == 0 ) head = a;
		if( is.fail() ) c = "";
		rules[a].push_back( c );
	}
	while( run() );
	return 0;
}
