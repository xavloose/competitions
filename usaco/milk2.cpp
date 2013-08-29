/*
ID: chens1
PROG: milk2
LANG: C++
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <utility>

using namespace std;

int n, a, b, milk, nomilk;
pair<int,int> t[5000];

int main()
{
	ifstream fin( "milk2.in" );
	ofstream fout( "milk2.out" );
	fin >> n;
	for( int i = 0; i < n; i++ )
	{
		fin >> a >> b;
		t[i] = make_pair(a,b);
	}
	sort(t,t+n);
	a = t[0].first, b = t[0].second, milk = b - a;
	for( int i = 0; i < n; i++ )
	{
		if( t[i].first <= b )
		{
			if( t[i].second > b )
			{
				b = t[i].second;
				if( b - a > milk ) milk = b - a;
			}
		}
		else
		{
			a = t[i].first;
			if( a - b > nomilk ) nomilk = a - b;
			b = t[i].second;
		}
	}
	fout << milk << " " << nomilk << endl;
	return 0;
}
