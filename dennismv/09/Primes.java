/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Primes
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		generate(max);
		int caseNum = 1;
		while( new Primes().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int a = in.nextInt(), b = in.nextInt();
		if( a==0 && b==0 ) return false;
		int A = Arrays.binarySearch( lookup, a ), B = Arrays.binarySearch( lookup, b );
		if( A < 0 ) A = -A-1; if( B < 0 ) B = -B-1; else B++;
		System.out.println( B-A );
		return true;
	}

	static int max = 9999999, lookup[];
	static void generate( int n )
	{
		boolean[] s = new boolean[n+1];
		for( int i = 2; i <= n; i++ ) s[i] = true;
		for( int i = 2; i < Math.ceil(Math.sqrt(n)); i++ )
			if( s[i] )
				for( int j = 2*i; j <= n; j += i )
					s[j] = false;
		for( int i = 2; i <= n; i++ )
			if( s[i] )
			{
				int reverse = 0;
				for( int t = i; t > 0; t /= 10 )
					reverse = 10*reverse + t%10;
				if( !s[reverse] )
					s[i] = false;
			}
		int l = 0;
		for( int i = 2; i < s.length; i++ ) if( s[i] ) l++;
		lookup = new int[l]; int j = 0;
		for( int i = 2; i < s.length; i++ ) if( s[i] ) lookup[j++] = i;
	}
}
