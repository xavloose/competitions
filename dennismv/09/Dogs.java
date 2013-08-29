/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Dogs
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Dogs().solve( caseNum++ ) );
	}

	int max = 100;
	boolean solve( int caseNum )
	{
		int n = in.nextInt();
		if( n==0 ) return false;
		int[] count = new int[max+1];
		TreeSet<Integer> nums = new TreeSet<Integer>();
		for( int i = 0; i < n; i++ ) count[in.nextInt()]++;
		for( int i = 0; i <= max; i++ ) if( count[i] > 1 ) nums.add(i);
		if( nums.size()==0 ) System.out.print( "I want more dogs with large eyes!" );
		else for( int i : nums ) System.out.print( i+" " );
		System.out.println();
		return true;
	}
}
