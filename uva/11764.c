#include "stdio.h"

int T, t, n, a, b, hi, lo;

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d%d", &n, &a );
		hi = lo = 0;
		while(--n)
		{
			scanf( "%d", &b );
			if( b > a ) hi++;
			else if( b < a ) lo++;
			a = b;
		}
		printf( "Case %d: %d %d\n", t, hi, lo );
	}
	return 0;
}
