/*
ID: chens1
PROG: transform
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define check(x,y) ok = true; for( int i = 0; i < n; i++ ) for( int j = 0; j < n; j++ ) if( a[i][j] != b[x][y] ) ok = false; if( ok ) goto done;

bool ok;
int n, type = 1;
string a[10], b[10];

int main()
{
	ifstream fin( "transform.in" );
	ofstream fout( "transform.out" );
	fin >> n;
	for( int i = 0; i < n; i++ ) fin >> a[i];
	for( int i = 0; i < n; i++ ) fin >> b[i];

	check(j,n-i-1);
	type++;

	check(n-i-1,n-j-1);
	type++;

	check(n-j-1,i);
	type++;

	check(i,n-j-1);
	type++;

	check(n-j-1,n-i-1);
	check(n-i-1,j);
	check(j,i);
	type++;

	check(i,j);
	type++;

	done:
	fout << type << endl;
	return 0;
}
