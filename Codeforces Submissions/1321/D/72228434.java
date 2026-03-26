import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class P1321D
{
	static ArrayList<Integer>[] g;
	public static void main(String[] args)
	{
		FastScanner scan = new FastScanner();
		int n = scan.nextInt();
		int m = scan.nextInt();
		g = new ArrayList[n];
		for (int i = 0; i < n; i++)
			g[i] = new ArrayList<>();
		for (int i = 0; i < m; i++)
		{
			int u = scan.nextInt()-1;
			int v = scan.nextInt()-1;
			g[v].add(u);
		}
		int k = scan.nextInt();
		int[] path = new int[k];
		for (int i = 0; i < k; i++)
			path[i] = scan.nextInt()-1;
		
		Queue<Integer> q = new ArrayDeque<>();
		int[] dist = new int[n];
		Arrays.fill(dist, Integer.MAX_VALUE/3);
		dist[path[k-1]] = 0;
		q.add(path[k-1]);
		boolean[] mult = new boolean[n];
		while (!q.isEmpty())
		{
			int p = q.poll();
			int d = dist[p];
			for (int i = 0; i < g[p].size(); i++)
			{
				int x = g[p].get(i);
				if (d+1 < dist[x])
				{
					dist[x] = d+1;
					q.add(x);
				}
				else if (d+1 == dist[x])
					mult[x] = true;
			}
		}
		int min = 0, max = 0;
		for (int i = 1; i < k; i++)
		{
			int prevD = dist[path[i-1]];
			int d = dist[path[i]];
			if (prevD-1 != d)
			{
				min++;
				max++;
			}
			else if (mult[path[i-1]])
				max++;
		}
		System.out.println(min + " " + max);
	}
	static class FastScanner
	{
		BufferedReader br;
		StringTokenizer st;

		public FastScanner()
		{
			try
			{
				br = new BufferedReader(new InputStreamReader(System.in));
				st = new StringTokenizer(br.readLine());
			} catch (Exception e)
			{
				e.printStackTrace();
			}
		}

		public String next()
		{
			if (st.hasMoreTokens())
				return st.nextToken();
			try
			{
				st = new StringTokenizer(br.readLine());
			} catch (Exception e)
			{
				e.printStackTrace();
			}
			return st.nextToken();
		}

		public int nextInt()
		{
			return Integer.parseInt(next());
		}

		public long nextLong()
		{
			return Long.parseLong(next());
		}

		public String nextLine()
		{
			String line = "";
			try
			{
				line = br.readLine();
			} catch (Exception e)
			{
				e.printStackTrace();
			}
			return line;
		}
	}
}
