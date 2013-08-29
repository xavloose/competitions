/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Boxes
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Boxes().solve( caseNum++ ) );
	}

	boolean solve( int caseNum )
	{
		int d = in.nextInt();
		if( d == 0 ) return false;
		HashMap<Integer,Integer> count = new HashMap<Integer,Integer>();
		for( int i = 0; i < d; i++ )
		{
			int x = in.nextInt();
			if( !count.containsKey(x) ) count.put(x,0);
			count.put(x,count.get(x)+1);
		}
		long res = fact(d);
		for( int i : count.keySet() ) res /= fact(count.get(i));
		System.out.println( res );
		return true;
	}

	long fact( int d )
	{
		long res = 1;
		while( d != 0 )
		{
			res *= d;
			d--;
		}
		return res;
	}

}
