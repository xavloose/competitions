#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

double b0, b1, b2, b3, t0, t1, t2, t3;

inline double eval( double x )
{ return t0 + x * ( t1 + x * ( t2 + x * t3 ) ); }

double get( const double & (*f)( const double &, const double & ) )
{
	double ans = f( t0, t0 + t1 + t2 + t3 );
	if( t3 != 0 )
	{
		if( t2 * t2 >= 3 * t1 * t3 )
		{
			double disc = sqrt( t2 * t2 - 3 * t1 * t3 );
			double r0 = ( -t2 - disc ) / 3 / t3, r1 = ( -t2 + disc ) / 3 / t3;
			if( 0 <= r0 && r0 <= 1 ) ans = f( ans, eval( r0 ) );
			if( 0 <= r1 && r1 <= 1 ) ans = f( ans, eval( r1 ) );
		}
	}
	else if( t2 != 0 )
	{
		double r = -t1 / 2 / t2;
		if( 0 <= r && r <= 1 ) ans = f( ans, eval( r ) );
	}
	return ans;
}

int main()
{
	while(1)
	{
		cin >> b0 >> b1 >> b2 >> b3 >> t0 >> t1 >> t2 >> t3;
		if( cin.fail() ) break;
		t0 -= b0, t1 -= b1, t2 -= b2, t3 -= b3;
		double hi = get( max ), lo = get( min );
		printf( "%.8lf\n", hi - lo );
	}
	return 0;
}
