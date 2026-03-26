import java.io.*;

public class Main {
	static class BIT{
		int[] t;
		int N;
		public BIT(int n) {
			N = n;
			t = new int[N+1];
		}
		void add(int i, int dx) {
			while(i <= N) {
				t[i] += dx;
				i += i&-i;
			}
		}
		int sum(int i) {
			int s = 0;
			while(i > 0) {
				s += t[i];
				i -= i&-i;
			}
			return s;
		}
		int sum(int l, int r) {
			return sum(r) - sum(l-1);
		}
	}
	static StreamTokenizer in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	public static int nextInt()throws IOException { in.nextToken(); return (int)in.nval; }
	public static String next()throws IOException { in.nextToken(); return (String)in.sval; }
	static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
	
	static int MN = (int)3e5 + 5;
	static int[] lst = new int[MN];
	static int[] mn = new int[MN];
	static int[] mx = new int[MN];
	public static void main(String[] args) throws IOException {
		int n = nextInt();
		int m = nextInt();
		BIT bit = new BIT(n+m);
		for(int i=1; i<=n; ++i) {
			lst[i] = n+1-i;
			mn[i] = i;
			mx[i] = i;
			bit.add(lst[i], 1);
		}
		for(int i=1; i<=m; ++i) {
			int t = nextInt();
			mn[t] = 1;
			mx[t] = Math.max(mx[t], bit.sum(lst[t], n+m));
			bit.add(lst[t], -1);
			lst[t] = n+i;
			bit.add(lst[t], 1);
		}
		for(int i=1; i<=n; ++i)
			mx[i] = Math.max(mx[i], bit.sum(lst[i], n+m));
		for(int i=1; i<=n; ++i)
			out.printf("%d %d\n", mn[i], mx[i]);
		out.flush();
		out.close();
	}
}
