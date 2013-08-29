/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Sum
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Sum().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		int[] nums = new int[n];
		for( int i = 0; i < n; i++ ) nums[i] = in.nextInt();
		// BRUTE FORCE
		BigInteger best = BigInteger.ZERO;
		int bests = -1;
		outer: for( int x0 = 1000; x0 > 0; x0-- )
		{
			int s = x0;
			BigInteger prod = new BigInteger( ""+s );
			for( int i = 0; i < n; i++ )
			{
				s = nums[i]-s;
				if( s <= 0 ) continue outer;
				prod = prod.multiply( new BigInteger( ""+s ) );
			}
			if( prod.compareTo( best ) >= 0 )
			{
				bests = x0;
				best = prod;
			}
		}
		if( bests != -1 )
		{
			System.out.printf( "Case %d: %d", caseNum, bests );
			for( int i = 0; i < n; i++ )
			{
				bests = nums[i]-bests;
				System.out.print( " "+bests );
			}
			System.out.println();
		}
		else System.out.printf( "Case %d: Impossible Sums!\n", caseNum );
		return true;
	}
}
