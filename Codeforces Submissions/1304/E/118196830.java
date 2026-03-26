import java.io.*;
import java.util.*;
public class Main {
    static int[] depth;
	static int[][] table;
	static ArrayList<Integer>[] tree;
	static void dfs(int curr,int p) {
		table[curr][0]=p; 
		for (int i=1;i<18;i++) {  
            table[curr][i]=table[table[curr][i-1]][i-1];
        }
		for(int child:tree[curr]) {
			if(child!=p) {
				depth[child]=1+depth[curr];
				dfs(child,curr);
			}
		}
	}
	
	static int lca(int u, int v)  
    {    
        if(depth[u]<depth[v]) {  
            int temp=u;  
            u=v;  
            v=temp;  
        }  
        for (int i=17;i>-1;i--) {  
            if ((depth[u]-(int)Math.pow(2, i))>=depth[v]) { 
                u=table[u][i];  
            }
        }  
        if (u==v) {  
            return u;  
        }
        for(int i=17;i>-1;i--) {  
            if (table[u][i]!=table[v][i]) {  
                u=table[u][i];  
                v=table[v][i];  
            }  
        }  
        return table[u][0];  
    }  
	static int dist(int a, int b) {
		  int c = lca(a, b);
		  int ans = depth[a] + depth[b] - 2*depth[c];
		  return ans;
	}
	public static void main(String[] args) throws IOException 
	{ 
		FastScanner f = new FastScanner(); 
		int ttt=1;
//		ttt=f.nextInt();
		PrintWriter out=new PrintWriter(System.out);
		for(int tt=0;tt<ttt;tt++) {
			int n=f.nextInt();
			tree=new ArrayList[n];
			depth=new int[n];
			table=new int[n][19];
			for(int i=0;i<n;i++) tree[i]=new ArrayList<>();
			for(int i=0;i<n-1;i++) {
				int u=f.nextInt()-1;
				int v=f.nextInt()-1;
				tree[u].add(v);
				tree[v].add(u);
			}
			dfs(0,0);
			int q=f.nextInt();
			for(int i=0;i<q;i++) {
				int x=f.nextInt()-1;
				int y=f.nextInt()-1;
				int a=f.nextInt()-1;
				int b=f.nextInt()-1;
				int k=f.nextInt();
				int d1 = dist(a, b);
			    int d2 = dist(a, x) + 1 + dist(y, b);
			    int d3 = dist(a, y) + 1 + dist(x, b);
			    boolean w1 = d1 <= k && (k-d1)%2==0;
			    boolean w2 = d2 <= k && (k-d2)%2==0;
			    boolean w3 = d3 <= k && (k-d3)%2==0;
			    if (w1 || w2 || w3) {
			      out.println("YES");
			    } else {
			      out.println("NO");
			    }
			}
		}
		out.close();
	} 
	static void sort(int[] p) {
        ArrayList<Integer> q = new ArrayList<>();
        for (int i: p) q.add( i);
        Collections.sort(q);
        for (int i = 0; i < p.length; i++) p[i] = q.get(i);
    }
    
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
		double nextDouble() {
			return Double.parseDouble(next());
		}
		long[] readLongArray(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
	}
} 	