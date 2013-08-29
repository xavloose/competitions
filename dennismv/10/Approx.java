/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Approx
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Approx().solve( caseNum++ ) );
	}

	static int max = 1000000;

	boolean solve( int caseNum )
	{
		double d = in.nextDouble();
		if( d == 0 ) return false;
		int bestp = 0, bestq = 0;
		double best = max;
		for( int q = 1; q <= max; q++ )
		{
			int p1 = (int)Math.floor(d*q);
			int p2 = (int)Math.ceil(d*q);
			double e1 = 1.0*p1/q;
			double e2 = 1.0*p2/q;
			if( p1 >= 1 && p1 <= max && Math.abs(e1-d) < best )
			{
				best = Math.abs(e1-d);
				bestp = p1;
				bestq = q;
			}
			if( p2 >= 1 && p2 <= max && Math.abs(e2-d) < best )
			{
				best = Math.abs(e2-d);
				bestp = p2;
				bestq = q;
			}
		}
		if( caseNum > 1 ) System.out.println();
		System.out.printf( "Case %d is best approximated as %d/%d\n", caseNum, bestp, bestq );
		return true;
	}
}
