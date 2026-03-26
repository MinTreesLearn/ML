import java.io.*;
import java.util.*;
public class Fields {
	static int n, m, k;
	static ArrayList<ArrayList<Integer>> adj;
	static boolean[] special, visited;
	static int[] distance1, distanceN;
	public static void main(String[] args) throws Exception {
		FastIO in = new FastIO();
		n = in.nextInt();
		m = in.nextInt();
		k = in.nextInt();
		special = new boolean[n];
		visited = new boolean[n];
		distance1 = new int[n];
		distanceN = new int[n];
		adj = new ArrayList<ArrayList<Integer>>();
		for (int i=0; i<k; i++) {
			int s = in.nextInt()-1;
			special[s] = true;
		}
		for (int i=0; i<n; i++) {
			adj.add(new ArrayList<Integer>());
		}
		for (int i=0; i<m; i++) {
			int a = in.nextInt()-1;
			int b = in.nextInt()-1;
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		bfs(0, distance1);
		visited = new boolean[n];
		bfs(n-1, distanceN);
		Pair[] specialPairs = new Pair[k];
		int index = 0;
		for (int i=0; i<n; i++) {
			if (special[i]) {
				specialPairs[index] = new Pair(distance1[i], distanceN[i]);
				index++;
			}
		}
		Arrays.parallelSort(specialPairs, (o1, o2) -> Integer.compare(o1.x, o2.x));
		int[] suffixMaxY = new int[k];
		suffixMaxY[k-1] = specialPairs[k-1].y;
		for (int i=k-2; i>=0; i--) {
			suffixMaxY[i] = Math.max(specialPairs[i].y, suffixMaxY[i+1]);
		}
		int maxDist = 0;
		for (int i=0; i<k-1; i++) {
			int longestPath = specialPairs[i].x+1+Math.min(specialPairs[i].y, suffixMaxY[i+1]);
			maxDist = Math.max(maxDist, longestPath);
		}
		System.out.println(Math.min(maxDist, distance1[n-1]));
	}
	public static void bfs(int node, int[] distance) {
		Queue<Pair> queue = new LinkedList<Pair>();
		queue.add(new Pair(node, 0));
		while (!queue.isEmpty()) {
			Pair curr = queue.poll();
			if (visited[curr.x]) continue;
//			if (curr.x==3) System.out.println(curr.y);
			distance[curr.x] = curr.y;
			visited[curr.x] = true;
			for (int next: adj.get(curr.x)) {
				if (!visited[next]) {
					queue.add(new Pair(next, curr.y+1));
				}
			}
		}
	}
	static class Pair {
		int x, y;
		public Pair(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	static class FastIO {
		BufferedReader br;
	    StringTokenizer st;
	    public FastIO() throws IOException
	    {
	        br = new BufferedReader(
	            new InputStreamReader(System.in));

	    }
	    

	    public String next() throws IOException
	    {
	        while (st == null || !st.hasMoreElements()) {
	           
	            st = new StringTokenizer(br.readLine());
	        }
	        return st.nextToken();
	    }

	    public int nextInt() throws NumberFormatException, IOException { return Integer.parseInt(next()); }

	    public long nextLong() throws NumberFormatException, IOException { return Long.parseLong(next()); }

	    public double nextDouble() throws NumberFormatException, IOException
	    {
	        return Double.parseDouble(next());
	    }

	    public String nextLine() throws IOException
	    {
	        String str = br.readLine();
	        return str;
	    }
	}
}
