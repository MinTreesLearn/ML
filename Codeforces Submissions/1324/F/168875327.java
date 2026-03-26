    import java.util.ArrayList;
    import java.util.List;
    import java.util.Scanner;
     
    public class Main {
    	public static Scanner cin = new Scanner(System.in);
    	public int n;
    	public int a[], d[], c[], ans[];
    	public int use[];
    	public int res[];
    	public List<Integer> vec[];
    	public int dfs(int u) {
    		use[u] = 1;
    		int ttl = (a[u] == 1 ? 1 : -1);
    		for (int v : vec[u]) {
    			if (use[v] == 0) {
    				ttl += dfs(v);
    			}
    		}
    		if (ttl < 0) {
    			ttl = 0;
    		}
    		c[u] = ttl;
    		return c[u];
    	}
    	public void dfsA(int u, int k) {
    		use[u] = 2;
    		int ttl = (a[u] == 1 ? 1 : -1) + k;
    		for (int v : vec[u]) {
    			if (use[v] == 1) {
    				ttl += c[v];
    			}
    		}
    		for (int v : vec[u]) {
    			if (use[v] == 1) {
    				int x = ttl - c[v];
    				if (x < 0) x = 0;
    				dfsA(v, x);
    			}
    		}
    		ans[u] = ttl;
    		
    	}
    	public void solve() {
    		n = cin.nextInt();
    		a = new int[n+1];
    		res = new int[n+1];
    		use = new int[n+1];
    		vec = new List[n+1];
    		c = new int[n+1];
    		ans = new int[n+1];
    		for (int i = 1; i <= n; i++) {
    			a[i] = cin.nextInt();
    		}
    		for (int i = 1; i <= n; i++) {
    			use[i] = 0;
    			vec[i] = new ArrayList<>();
    		}
    		for (int i = 1; i < n; i++) {
    			int x = cin.nextInt();
    			int y = cin.nextInt();
    			vec[x].add(y);
    			vec[y].add(x);
    			
    		}
    		dfs(1);
    		dfsA(1, 0);
    		StringBuffer sb = new StringBuffer();
    		for (int i = 1; i <= n; i++) {
    			sb.append(ans[i]).append(" ");
    		}
    		System.out.println(sb.toString());
    	}
    	public static void main(String [] args) {
    		Main t = new Main();
    		t.solve();
    	}
    }