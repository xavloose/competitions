/*
ID: chens1
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

map<string,int> cnt;
int n, amt, m;
string a, b, names[10];

int main()
{
	ifstream fin( "gift1.in" );
	ofstream fout( "gift1.out" );
	fin >> n;
	for( int i = 0; i < n; i++ ) fin >> names[i];
	while( fin >> a )
	{
		fin >> amt >> m;
		for( int i = 0; i < m; i++ )
		{
			fin >> b;
			cnt[a] -= amt / m;
			cnt[b] += amt / m;
		}
	}
	for( int i = 0; i < n; i++ ) fout << names[i] << " " << cnt[names[i]] << endl;
	return 0;
}
