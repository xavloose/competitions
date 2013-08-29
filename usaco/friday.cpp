/*
ID: chens1
PROG: friday
LANG: C++
*/

#include <fstream>
#include <iostream>

using namespace std;

int n, cnt[7], days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	ifstream fin( "friday.in" );
	ofstream fout( "friday.out" );
	fin >> n;
	int d = 2;
	for( int year = 1900; year < 1900+n; year++ ) for( int month = 0; month < 12; month++ )
	{
		for( int day = 0; day < days[month]; day++ )
		{
			if( day == 12 ) cnt[d]++;
			d = (d+1)%7;
		}
		if( month == 1 && year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) ) d = (d+1)%7;
	}
	for( int i = 0; i < 6; i++ ) fout << cnt[i] << " ";
	fout << cnt[6] << endl;
	return 0;
}
