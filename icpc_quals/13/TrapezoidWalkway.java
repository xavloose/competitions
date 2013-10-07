import java.io.*;
import java.util.*;

public class TrapezoidWalkway
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int N = 1005, INF = 2020202020;
	static ArrayList<int[]>[] g = new ArrayList[N];

	public static void main(String[] args)
	{
		for(int i = 0; i < N; i++) g[i] = new ArrayList<int[]>();
		while(new TrapezoidWalkway().run()) for(int i = 0; i < N; i++) g[i].clear();
	}

	boolean run()
	{
		int n = in.nextInt();
		if(n == 0) return false;
		while(n --> 0)
		{
			int a = in.nextInt(), b = in.nextInt(), h = in.nextInt();
			h *= a + b;
			g[a].add(new int[]{b, h});
			g[b].add(new int[]{a, h});
		}
		int s = in.nextInt(), t = in.nextInt();
		final int[] d = new int[N];
		Arrays.fill(d, INF);
		d[s] = 0;

		TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>()
		{
			public int compare(Integer a, Integer b)
			{
				if(d[a] != d[b]) return d[a] - d[b];
				return a - b;
			}
		});
		q.add(s);
		while(!q.isEmpty())
		{
			int u = q.pollFirst();
			for(int[] e : g[u])
			{
				int v = e[0], h = e[1];
				if(d[v] > d[u] + h)
				{
					q.remove(v);
					d[v] = d[u] + h;
					q.add(v);
				}
			}
		}
		System.out.printf("%.2f\n", 0.01 * d[t]);
		
		return true;
	}
}
