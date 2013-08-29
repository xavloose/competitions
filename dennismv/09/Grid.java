/*
	Siyang Chen
 */

import java.io.*;
import java.math.*;
import java.util.*;

public class Grid
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{
		int caseNum = 1;
		generate();
		while( new Grid().solve( caseNum++ ) );
	}

	boolean used[], found;
	int n, N, grid[], ansGrid[], minSum = 12345678;
	boolean solve( int caseNum )
	{
		n = in.nextInt();
		int x0 = in.nextInt();
		if( n==x0 && n==0 ) return false;
		N = n*n;
		grid = new int[N];
		grid[0] = x0;
		ansGrid = new int[N];
		used = new boolean[N*(n<=4?2:1)+1];
		used[x0] = true;
		found = false;
		if( caseNum > 1 ) System.out.println();
		if( dfs(0) ) ansGrid = grid;
		if( found )
		{
			System.out.printf( "Matt, here is puzzle #%d:\n", caseNum );
			int max = 0;
			for( int i : ansGrid ) if( i > max ) max = i;
			int len = max>99 ? 4 : max>9 ? 3 : 2;
			for( int i = 0; i < n; i++ )
			{
				for( int j = 0; j < n; j++ ) System.out.printf( "%"+len+"d", ansGrid[i*n+j] );
				System.out.println();
			}
		}
		else System.out.printf( "Yo, Matt! That puzzle #%d, it was not cool!\n", caseNum );
		return true;
	}

	boolean dfs( int x )
	{
		if( x == N-1 ) return foundOptimalSolution();
		x++;
		for( int next = 1; next < used.length; next++ )
			if( !used[next] && ( x%n==0 || isPrime[next+grid[x-1]] ) && ( x<n || isPrime[next+grid[x-n]] ) )
			{
				used[next] = true;
				grid[x] = next;
				if( dfs(x) ) return true;
				used[next] = false;
			}
		return false;
	}

	boolean foundOptimalSolution()
	{
		found = true;
		int sum = 0;
		for( int i = 0; i < N; i++ ) sum += grid[i];
		if( sum==(N*(N+1))/2 ) return true;
		if( sum<minSum )
		{
			for( int i = 0; i < N; i++ ) ansGrid[i] = grid[i];
			minSum = sum;
		}
		return false;
	}

	static boolean[] isPrime;
	static int max = 200;
	static void generate()
	{
		isPrime = new boolean[max];
		for( int i = 2; i < max; i++ ) isPrime[i] = true;
		for( int i = 2; i < max; i++ ) if( isPrime[i] ) for( int j = i*2; j < max; j += i ) isPrime[j] = false;
	}
}
