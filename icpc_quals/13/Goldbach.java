import java.io.*;
import java.util.*;

public class Goldbach
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int N = 32000;
		boolean[] isP = new boolean[N+1];
		ArrayList<Integer> ps = new ArrayList<Integer>();
		for(int i = 2; i <= N; i++) isP[i] = true;
		for(int i = 2; i <= N; i++) if(isP[i])
		{
			ps.add(i);
			for(int j = 2*i; j <= N; j += i) isP[j] = false;
		}

		for(int n = in.nextInt(); n --> 0;)
		{
			int x = in.nextInt();
			ArrayList<Integer> qs = new ArrayList<Integer>();
			for(int p : ps)
			{
				if(p > x / 2) break;
				if(isP[x-p]) qs.add(p);
			}
			System.out.printf("%d has %d representation(s)\n", x, qs.size());
			for(int q : qs) System.out.printf("%d+%d\n", q, x - q);
			if(n > 0) System.out.println();
		}
	}
}
