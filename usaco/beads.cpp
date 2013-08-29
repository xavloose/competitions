/*
ID: chens1
PROG: beads
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int n, best;
string str;

int main()
{
	ifstream fin( "beads.in" );
	ofstream fout( "beads.out" );
	fin >> n >> str;
	for( int i = 0; i < n; i++ )
	{
		int cnt = 0;
		char start = str[i];
		for( int j = 0; j < n; j++ )
		{
			char c = str[(i+j)%n];
			if( c != 'w' )
			{
				if( start == 'w' ) start = c;
				else if( c != start && c != 'w' ) break;
			}
			cnt++;
		}
		start = str[(i+n-1)%n];
		for( int j = 0; j < n; j++ )
		{
			char c = str[(i+n-j-1)%n];
			if( c != 'w' )
			{
				if( start == 'w' ) start = c;
				else if( c != start && c != 'w' ) break;
			}
			cnt++;
		}
		if( cnt > n ) cnt = n;
		if( cnt > best ) best = cnt;
	}
	fout << best << endl;
	return 0;
}
