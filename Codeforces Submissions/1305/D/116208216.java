import java.io.*;
import java.util.*;

public class D {

	public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	//public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));

	public static void main(String[] args) throws IOException {
		readInput();
		//out.close();
	}
	static int n;
	static List<Integer>[] adj;
	static boolean[] bad;
	static int dist;
	static int maxNode;
	static void dfs(int i, int p, int d) {
		if (bad[i]) return;
		if (d > dist) {
			dist = d;
			maxNode = i;
		}
		for (int x: adj[i]) {
			if (x == p) continue;
			dfs(x,i,d+1);
		}
	}
	static void mark(int i, int p, int t) {
		if (bad[i]) return;
		if (i == t) return;
		//System.out.println("Marking " + i + " Target " + t);
		bad[i] = true;
		for (int x: adj[i]) {
			if (p ==x) continue;
			mark(x,i,t);
		}
	}
	public static void readInput() throws IOException {
		// br = new BufferedReader(new FileReader(".in"));
		// out = new PrintWriter(new FileWriter(".out"));
		// Idea: Get diameter of tree, query LCA. If LCA is either one of the nodes, immidiately exit. 
		// Else, mark every node on the path to LCA as bad or someth. Continue;
		n = Integer.parseInt(br.readLine());
		adj = new List[n+1];
		bad = new boolean[n+1];
		for (int i= 0 ; i <= n; i++) adj[i] = new ArrayList<Integer>();
		for (int i = 0; i < n-1; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			adj[x].add(y);
			adj[y].add(x);
		}
		int prev = 1;
		while (true) {
			dist = 0;
			maxNode = prev;
			dfs(prev,prev,0);
			int u = maxNode;
			dist = 0;
			maxNode = u;
			dfs(u,u,0);
			int v = maxNode;
			if (u == v) {
				System.out.println("! " + v);
				System.out.flush();
				break;
			}
			System.out.println("? " + u + " " + v);
			System.out.flush();
			int lca = Integer.parseInt(br.readLine());
			if (lca == -1) System.exit(0);
			else if (lca == u || lca == v) {
				System.out.println("! " + lca);
				System.out.flush();
				break;
			}
			mark(u,u,lca);
			mark(v,v,lca);
			prev = lca;
		}
		
	}
}
