/*
ID: chens1
PROG: namenum
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

#define foreach(i,c) for(__typeof__((c).end()) i=(c).begin();i!=(c).end();i++)

long long n;
map< long long, set<string> > lookup;
map< char, int > keypad;
string tmp;

int main()
{
	ifstream fin( "namenum.in" );
	ofstream fout( "namenum.out" );
	fin >> n;

	ifstream din( "dict.txt" );
	keypad['A'] = 2;
	keypad['B'] = 2;
	keypad['C'] = 2;
	keypad['D'] = 3;
	keypad['E'] = 3;
	keypad['F'] = 3;
	keypad['G'] = 4;
	keypad['H'] = 4;
	keypad['I'] = 4;
	keypad['J'] = 5;
	keypad['K'] = 5;
	keypad['L'] = 5;
	keypad['M'] = 6;
	keypad['N'] = 6;
	keypad['O'] = 6;
	keypad['P'] = 7;
	keypad['R'] = 7;
	keypad['S'] = 7;
	keypad['T'] = 8;
	keypad['U'] = 8;
	keypad['V'] = 8;
	keypad['W'] = 9;
	keypad['X'] = 9;
	keypad['Y'] = 9;
	while( din >> tmp )
	{
		long long index = 0;
		for( int i = 0; i < tmp.size(); i++ ) index = 10 * index + keypad[tmp[i]];
		lookup[index].insert( tmp );
	}

	if( lookup.count(n) ) foreach(s,lookup[n]) fout << *s << endl;
	else fout << "NONE" << endl;
	return 0;
}
