/*
ID: chens1
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ifstream fin( "ride.in" );
	ofstream fout( "ride.out" );
	string a, b;
	fin >> a >> b;
	int x = 1, y = 1;
	for( int i = 0; i < a.size(); i++ ) x *= a[i] - 'A' + 1;
	for( int i = 0; i < b.size(); i++ ) y *= b[i] - 'A' + 1;
	fout << ( ( x % 47 == y % 47 ) ? "GO" : "STAY" ) << endl;
	return 0;
}
