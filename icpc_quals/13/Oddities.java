import java.io.*;
import java.util.*;

public class Oddities
{
	static Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	public static void main(String[] args)
	{
		for(int n = in.nextInt(); n --> 0;)
		{
			int x = in.nextInt();
			System.out.printf("%d is %s\n", x, x % 2 == 0 ? "even" : "odd");
		}
	}
}
