import java.io.*;
import java.math.*;
import java.util.*;

public class ChoosingNumbers
{
	static Scanner in = new Scanner( new BufferedReader( new InputStreamReader( System.in ) ) );

	public static void main( String[] args )
	{ while( in.hasNextInt() ) new ChoosingNumbers().run(); }

	void run()
	{
		int n = in.nextInt();
		BigInteger nums[] = new BigInteger[n], prod = BigInteger.ONE, ans = BigInteger.ONE;
		for( int i = 0; i < n; i++ )
		{
			nums[i] = new BigInteger( in.next() );
			prod = prod.multiply( nums[i] );
		}
		Arrays.sort( nums );
		for( int i = n - 1; i >= 0; i-- ) if( nums[i].gcd( prod.divide( nums[i] ) ).equals( BigInteger.ONE ) )
		{
			System.out.println( nums[i] );
			return;
		}
	}
}
