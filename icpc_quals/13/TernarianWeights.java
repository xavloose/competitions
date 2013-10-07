import java.io.*;
import java.util.*;

public class TernarianWeights
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;)
		{
			int x = in.nextInt();
			ArrayList<Integer> l = new ArrayList<Integer>(), r = new ArrayList<Integer>();
			for(int p = 1; x > 0; x /= 3, p *= 3) switch(x % 3)
			{
				case 1: r.add(p); break;
				case 2: l.add(p); x++; break;
				default: break;
			}
			finish("left", l);
			finish("right", r);
			if(n > 0) System.out.println();
		}
	}

	static void finish(String s, ArrayList<Integer> xs)
	{
		Collections.reverse(xs);
		System.out.printf("%s pan:", s);
		for(int x : xs) System.out.print(" " + x);
		System.out.println();
	}
}
