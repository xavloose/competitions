/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Finger
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Finger().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n == 0 ) return false;
		n--;
		int ans = 0, next = 0;
		if( n%8<4 )
		{
			ans = (n%8)+1;
			next = ans+1;
			if( next > 5 ) next = 4;
		}
		else
		{
			ans = 8-(n%8)+1;
			next = ans-1;
			if( next == 0 ) next = 2;
		}
		if( caseNum > 1 ) System.out.println();
		System.out.printf( "Counting to %d will stop on finger %d, going on %d.\n", n+1, ans, next );
		return true;
	}
}
