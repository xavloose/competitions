#include <iostream>
#include <string>

using namespace std;

#define N 100

int len[N];

int main()
{
	int hi = 0, n = 0;
	for( ; ; n++ )
	{
		string str;
		getline( cin, str );
		if( cin.fail() ) break;
		len[n] = str.size();
		if( len[n] > hi ) hi = len[n];
	}
	int ans = 0;
	for( int i = 0; i < n - 1; i++ ) ans += ( hi - len[i] ) * ( hi - len[i] );
	cout << ans << endl;
	return 0;
}
