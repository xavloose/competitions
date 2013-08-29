/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Coins
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		while( new Coins().solve( caseNum++ ) );
	}
	
	static int[] c = { 1, 5, 10, 25, 100 };
	static int INF = 111111111;

	boolean solve( int caseNum )
	{
		int p = (int)(100*in.nextDouble());
		if( p == 0 ) return false;

		int[] dp = new int[p+1];
		int[][] coins = new int[p+1][c.length];
		for( int i = 0; i <= p; i++ ) dp[i] = INF;
		dp[0] = 0;
		for( int z = c.length-1; z >= 0; z-- )
		for( int i = 0; i <= p; i++ )
			if( dp[i] != INF && c[z]+i <= p && dp[c[z]+i] > dp[i]+1 )
			{
				dp[i+c[z]] = dp[i]+1;
				for( int zz = 0; zz < c.length; zz++ )
					coins[c[z]+i][zz] = coins[i][zz];
				coins[c[z]+i][z]++;
			}

		if( caseNum > 1 ) System.out.println();
		System.out.printf( "Change for customer %d:\n", caseNum );
		System.out.println( "dollars: "+coins[p][4] );
		System.out.println( "quarters: "+coins[p][3] );
		System.out.println( "dimes: "+coins[p][2] );
		System.out.println( "nickels: "+coins[p][1] );
		System.out.println( "pennies: "+coins[p][0] );

		return true;
	}
}
