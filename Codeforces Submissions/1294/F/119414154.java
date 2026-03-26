import java.io.*;
import java.util.*;

public class F{
	
	static boolean[] vis;
	static int n;
	static List<Integer>[] adj;
	
	static int furthest;
	static int farNode;
	
	static void dfs1(int i, int p, int d) {
		if (d > furthest) {
			furthest = d;
			farNode = i;
		}
		for (int x: adj[i]) {
			if (x==p) continue;
			dfs1(x,i,d+1);
		}
	}
	
	static boolean dfs2(int i, int p, int t) {
		if (i == t) return vis[i] = true;
		for (int x: adj[i]) {
			if (x==p) continue;
			vis[i] |= dfs2(x,i,t);
		}
		return vis[i];
	}
	
	static void dfs3(int i, int p, int d) {
		if (d > furthest) {
			furthest = d;
			farNode = i;
		}
		for (int x: adj[i]) {
			if (vis[x] || x == p) continue;
			dfs3(x,i,d+1);
		}
	}
	
	public static void main(String[] args) throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		//new Thread(null, new (), "peepee", 1<<28).start();
		// Select diameter andthen longest path 
		n = readInt();
		adj = new List[n];
		for (int i = 0; i < n; i++) adj[i] = new ArrayList<Integer>();
		for (int i = 0; i < n-1; i++) {
			int x = readInt()-1;
			int y = readInt()-1;
			adj[x].add(y);
			adj[y].add(x);
		}
		farNode = furthest = 0;
		dfs1(0,0,0);
		List<Integer> b = new ArrayList<Integer>();
		b.add(farNode);
		furthest = 0;
		int cur = farNode;
		dfs1(farNode,farNode,0);
		b.add(farNode);
		long val = furthest;
		vis = new boolean[n];
		dfs2(farNode,farNode, cur);
		
		furthest = 0;
		for (int i =0 ; i < n; i++) {
			if (vis[i]) {
				//System.out.println("using this as jumpoff " + i + " " + adj[i]);
				dfs3(i,i,0);
			}
		}
		val += furthest;
		if (furthest== 0) {
			for (int i = 0; i < n; i++) if (!b.contains(i)) {
				farNode = i;
				break;
			}
		}
		b.add(farNode);

		out.println(val);
		
		for (int x: b) out.print(x +1+ " ");
		
		out.println();
		out.close();
	}
	
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	static StringTokenizer st = new StringTokenizer("");
	static String read() throws IOException{return st.hasMoreTokens() ? st.nextToken():(st = new StringTokenizer(br.readLine())).nextToken();}
	static int readInt() throws IOException{return Integer.parseInt(read());}
	static long readLong() throws IOException{return Long.parseLong(read());}
	static double readDouble() throws IOException{return Double.parseDouble(read());}
	
}