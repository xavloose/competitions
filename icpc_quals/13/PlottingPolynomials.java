import java.io.*;
import java.util.*;

public class PlottingPolynomials
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		int n = in.nextInt() + 1, a[] = new int[n], p[][] = new int[n][n];
		for(int i = 0; i < n; i++) a[i] = in.nextInt();
		for(int i = 0; i < n; i++) p[i][0] = f(a, i);
		for(int j = 1; j < n; j++) for(int i = 0; i + j < n; i++) 
			p[i][j] = p[i+1][j-1] - p[i][j-1];
		for(int j = 0; j < n; j++)
			System.out.printf("%d%s", p[0][j], j < n - 1 ? " " : "\n");
	}

	static int f(int[] a, int x)
	{
		int ans = 0;
		for(int c : a) ans = ans * x + c;
		return ans;
	}
}
