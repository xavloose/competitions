/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Dj
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Dj().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		String[] input = in.nextLine().split(" ");
		int a=Integer.parseInt(input[0]), b=Integer.parseInt(input[2]), c=Integer.parseInt(input[4]), d=Integer.parseInt(input[6]);
		if( a==0 && b==0 && c==0 && d==0 )
		{
			System.out.println( "Zhzyatslya, I did this for YOU!" );
			return false;
		}
		int denom = b*d, num = a*d+b*c;
		if( num%denom == 0 ) System.out.println( num/denom );
		else
		{
			int g = gcd(denom,num);
			denom /= g; num /= g;
			if( num < denom ) System.out.printf( "%d / %d\n", num, denom );
			else System.out.printf( "%d and %d / %d\n", num/denom, num%denom, denom );
		}
		return true;
	}

	static int gcd( int a, int b )
	{
		while( b != 0 )
		{
			int t = a%b;
			a = b;
			b = t;
		}
		return a;
	}
}
