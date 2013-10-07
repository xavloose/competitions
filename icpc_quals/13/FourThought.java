import java.io.*;
import java.util.*;

public class FourThought
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	static char[] c = {'*', '/', '+', '-', '4'};

	static int eval(int[] xs)
	{
		int n = xs.length, m = 0, ys[] = new int[n];
		for(int i = 0; i < n; i++)
		{
			if(i % 2 == 1 && xs[i] < 2)
			{
				if(xs[i] == 0) ys[m-1] *= xs[i+1];
				else ys[m-1] /= xs[i+1];
				i++;
			}
			else ys[m++] = xs[i];
		}
		for(int j = 1; j < m; j += 2)
		{
			if(ys[j] == 2) ys[0] += ys[j+1];
			else ys[0] -= ys[j+1];
		}
		return ys[0];
	}

	public static void main(String[] args)
	{
		HashMap<Integer,int[]> ans = new HashMap<Integer,int[]>();
		for(int a = 0; a < 4; a++) for(int b = 0; b < 4; b++) for(int c = 0; c < 4; c++)
		{
			int[] expr = {4, a, 4, b, 4, c, 4};
			ans.put(eval(expr), expr);
		}
		for(int n = in.nextInt(); n --> 0;)
		{
			int x = in.nextInt();
			if(ans.containsKey(x))
			{
				for(int i : ans.get(x)) System.out.printf("%c ", c[i]);
				System.out.printf("= %d\n", x);
			}
			else System.out.println("no solution");
		}
	}
}
