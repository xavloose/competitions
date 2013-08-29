#include <iostream>
#include <string>

using namespace std;

int main()
{
	while(1)
	{
		string line;
		getline( cin, line );
		if( cin.fail() ) break;
		for( int i = 0; i < line.size(); i++ ) if( 'A' <= line[i] && line[i] <= 'Z' ) line[i] += 'a' - 'A';
		cout << ( line.find( "problem" ) != string::npos ? "yes" : "no" ) << endl;
	}
	return 0;
}
