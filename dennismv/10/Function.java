/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Function
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Function().solve( caseNum++ ) );
	}

	double eps = 1e-11;

	boolean solve( int caseNum )
	{
		double x1 = in.nextDouble(), x2 = in.nextDouble(), y = in.nextDouble();
		if( x1 == 0 && x2 == 0 && y == 0 ) return false;
		double f1 = fun(x1,y), f2 = fun(x2,y);
		if( ( f1 > 0 && f2 > 0 ) || ( f1 < 0 && f2 < 0 ) )
		{
			System.out.println( "Professor, there is no Function..." );
			return true;
		}
		while( x2-x1 > eps )
		{
			double x3 = (x1+x2)/2, f3 = fun(x3,y);
			if( f3 > 0 )
			{
				if( f1 > 0 )
				{
					f1 = f3;
					x1 = x3;
				}
				else
				{
					f2 = f3;
					x2 = x3;
				}
			}
			else
			{
				if( f1 < 0 )
				{
					f1 = f3;
					x1 = x3;
				}
				else
				{
					f2 = f3;
					x2 = x3;
				}
			}
		}
		System.out.printf( "%.4f\n", x1 );
		return true;
	}

	static int[] coeffs = { -329, 524, 3, -52, 2 };

	double fun( double x, double y )
	{
		x /= 20;
		double res = 1;
		for( int i = coeffs.length-1; i >= 0; i-- )
		{
			res *= x;
			res += coeffs[i];
		}
		res -= y;
		return res;
	}
}
