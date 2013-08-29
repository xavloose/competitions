/*
 * Let X and Y be two integers such that 1 < X < Y < 100.
 *
 * Suppose Mr. S knows the sum X + Y, and Mr. P knows the product X * Y.
 * (Both Mr. S and Mr. P know the constraints on X and Y.) They engage in the
 * following conversation:
 *
 * Mr. P: I don't know the values of X and Y.
 * Mr. S: I knew that you didn't know. I don't know either.
 * Mr. P: Ah, now I know the values of X and Y.
 * Mr. S: Now I know them too.
 *
 * What are X and Y?
 *
 * (Problem originally written by the mathematician Hans Freudenthal.)
 */

import java.util.HashMap;

public class SP
{
	static int MIN = 2, MAX = 99;
	static HashMap<Integer,Boolean> cache1 = new HashMap<Integer,Boolean>();
	static HashMap<Integer,Boolean> cache2 = new HashMap<Integer,Boolean>();
	static HashMap<Integer,Boolean> cache3 = new HashMap<Integer,Boolean>();
	static HashMap<Integer,Boolean> cache4 = new HashMap<Integer,Boolean>();

	static boolean valid( int n )
	{
		return n >= MIN && n <= MAX;
	}

	/*
	 * Property 1: Mr. P cannot determine what the numbers are.
	 *
	 * Check if p has multiple pairs of valid divisors.
	 */
	static boolean property1( int p )
	{
		if( cache1.containsKey( p ) ) return cache1.get( p );
		int count = 0;
		for( int x = MIN; x <= MAX && x * x <= p; x++ )
		if( valid( p / x ) && p % x == 0 )
			count++;
		cache1.put( p, count >= 2 );
		return count >= 2;
	}

	/*
	 * Property 2: Mr. S knows that Mr. P cannot know what the numbers are.
	 *
	 * For all valid x, y such that x + y = s, it must be the case that x * y
	 * has multiple pairs of valid divisors.
	 */
	static boolean property2( int s )
	{
		if( s == MIN + MIN || s == MAX + MAX ) return false;
		if( cache2.containsKey( s ) ) return cache2.get( s );
		for( int x = MIN; x <= MAX && x <= s / 2; x++ )
		if( valid( s - x ) && !property1( x * ( s - x ) ) )
		{
			cache2.put( s, false );
			return false;
		}
		cache2.put( s, true );
		return true;
	}

	/*
	 * Property 3: Mr. P is able to figure out x and y, given that the sum
	 *             x + y must satisfy property 2.
	 *
	 * There is exactly one pair of divisors ( x, y ) of p such that property 2
	 * holds for the sum x + y.
	 */
	static boolean property3( int p )
	{
		if( cache3.containsKey( p ) ) return cache3.get( p );
		int count = 0;
		for( int x = MIN; x <= MAX && x * x <= p; x++ )
		if( valid( p / x ) && p % x == 0 && property2( x + p / x ) )
			count++;
		cache3.put( p, count == 1 );
		return count == 1;
	}

	/*
	 * Property 4: Mr. S is able to figure out x and y, given that the product
	 *             x * y must satisfy property 3.
	 *
	 * There is exactly one pair ( x, y ) with x + y = s, such that property 3
	 * holds for the product x * y.
	 */
	static boolean property4( int s )
	{
		if( cache4.containsKey( s ) ) return cache4.get( s );
		int count = 0;
		for( int x = MIN; x <= MAX && x <= s / 2; x++ )
		if( valid( s - x ) && property3( x * ( s - x ) ) )
			count++;
		cache4.put( s, count == 1 );
		return count == 1;
	}

	/*
	 * Search all possible x, y, and verify whether x + y and x * y satisfy
	 * properties 1 through 4.
	 */
	public static void main( String[] args )
	{
		for( int x = MIN; x <= MAX; x++ )
		for( int y = x+1; y <= MAX; y++ )
		{
			int s = x + y, p = x * y;
			if( !property1(p) ) continue;
			if( !property2(s) ) continue;
			if( !property3(p) ) continue;
			if( !property4(s) ) continue;
			System.out.println( x + " " + y );
		}
	}
}
