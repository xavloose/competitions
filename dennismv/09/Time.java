/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Time
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Time().solve( caseNum++ ) );
	}

	static int mod = 3600*24;
	boolean solve( int caseNum )
	{
		String time = in.next();
		String[] split = time.split( ":" );
		int[] stime = new int[3];
		for( int i = 0; i < 3; i++ ) stime[i] = Integer.parseInt( split[i] );
		if( stime[0] >= 24 || stime[1] >= 60 || stime[2] >= 60 )
		{
			System.out.println( "I broke time-space continuum!" );
			return true;
		}
		int t = stime[0]*3600 + stime[1]*60 + stime[2];
		if( t == 0 ) return false;
		t = mod-t;
		System.out.printf( "%2d:%02d:%02d\n", t/3600, (t%3600)/60, t%60 );
		return true;
	}
}
