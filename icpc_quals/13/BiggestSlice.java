import java.io.*;
import java.util.*;

public class BiggestSlice
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;) new BiggestSlice().solve();
	}

	static int toSeconds(int d, int m, int s)
	{
		return s + 60 * (m + 60 * d);
	}
	static int N = toSeconds(360, 0, 0);
	static boolean[] seen = new boolean[N+1];

	void solve()
	{
		int r = in.nextInt(), n = in.nextInt(), dq = toSeconds(in.nextInt(), in.nextInt(), in.nextInt());
		for(int q = 0; n --> 0 && !seen[q]; q = (q + dq) % N) seen[q] = true;
		int last = 0, best = 0;
		for(int q = 0; q <= N; q++, last++) if(q == N || seen[q])
		{
			best = Math.max(best, q - last);
			last = q;
			seen[q] = false;
		}
		System.out.printf("%.6f\n", Math.PI * r * r * best / N);
	}
}
