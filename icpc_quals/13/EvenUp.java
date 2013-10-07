import java.io.*;
import java.util.*;

public class EvenUp
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt(), x[] = new int[n], m = 0;
		while(n --> 0)
		{
			x[m] = in.nextInt() % 2;
			if(m > 0 && x[m] == x[m-1]) m--;
			else m++;
		}
		System.out.println(m);
	}
}
