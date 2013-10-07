import java.io.*;
import java.util.*;

public class ErraticAnts
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	static int INF = 12345, M = 65, N = 2*M;
	static int[] id = new int[128], dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};

	public static void main(String[] args)
	{
		id['E'] = 0;
		id['W'] = 1;
		id['N'] = 2;
		id['S'] = 3;
		for(int n = in.nextInt(); n --> 0;) new ErraticAnts().solve();
	}

	void solve()
	{
		int[][] best = new int[N][N], g = new int[N][N];
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		{
			best[i][j] = INF;
			g[i][j] = 0;
		}

		int x1 = M, y1 = M;
		for(int m = in.nextInt(); m --> 0;)
		{
			int dir = id[in.next().charAt(0)];
			g[x1][y1] |= 1 << dir;
			x1 += dx[dir];
			y1 += dy[dir];
			g[x1][y1] |= 1 << (dir ^ 1);
		}

		LinkedList<int[]> q = new LinkedList<int[]>();
		q.add(new int[]{M, M});
		best[M][M] = 0;
		while(!q.isEmpty())
		{
			int r[] = q.pollFirst(), x = r[0], y = r[1];
			for(int dir = 0; dir < 4; dir++) if((g[x][y] & (1 << dir)) > 0)
			{
				int u = x + dx[dir], v = y + dy[dir];
				if(best[u][v] == INF)
				{
					best[u][v] = best[x][y] + 1;
					q.add(new int[]{u, v});
				}
			}
		}
		System.out.println(best[x1][y1]);
	}
}
