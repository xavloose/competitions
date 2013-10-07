import java.io.*;
import java.util.*;

public class IslandBuses
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		for(int n = 1; new IslandBuses().solve(n); n++);
	}

	ArrayList<String> g = new ArrayList<String>();
	boolean seen[][];
	int n, m;
	EdgeCheck e;

	boolean solve(int t)
	{
		boolean last = false;
		while(true)
		{
			if(!in.hasNextLine())
			{
				last = true;
				break;
			}
			String line = in.nextLine();
			if(line.isEmpty()) break;
			g.add(line);
		}

		n = g.size();
		m = g.get(0).length();
		seen = new boolean[n][m];

		if(t > 1) System.out.println();
		System.out.printf("Map %d\n", t);
		System.out.printf("islands: %d\n", count(new EdgeCheck()
		{
			public boolean good(char u, char v)
			{
				return v == '#' || v == 'X';
			}
		}));
		System.out.printf("bridges: %d\n", count(new EdgeCheck()
		{
			public boolean good(char u, char v)
			{
				return v == 'B';
			}
		}));
		System.out.printf("buses needed: %d\n", count(new EdgeCheck()
		{
			public boolean good(char u, char v)
			{
				return v != '.' && u + v != '#' + 'B';
			}
		}));

		return !last;
	}

	interface EdgeCheck
	{
		public boolean good(char u, char v);
	}

	int count(EdgeCheck e)
	{
		this.e = e;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) seen[i][j] = false;
		int ans = 0;
		for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ans += dfs(i, j, 'x');
		return ans;
	}

	int dfs(int i, int j, char u)
	{
		if(i < 0 || i >= n || j < 0 || j >= m || seen[i][j]) return 0;
		char v = g.get(i).charAt(j);
		if(!e.good(u, v)) return 0;
		seen[i][j] = true;
		dfs(i+1, j, v);
		dfs(i-1, j, v);
		dfs(i, j+1, v);
		dfs(i, j-1, v);
		return 1;
	}
}
