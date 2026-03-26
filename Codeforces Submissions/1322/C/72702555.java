import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	private static Scanner cin = new Scanner(new BufferedInputStream(System.in));
	private static PrintWriter cout = new PrintWriter(System.out,true);
	private static InputStream inputstream = System.in;
	private static FastScanner in = new FastScanner(inputstream);
	public static void main(String[] args){
		Task solver = new Task();
		int TaskCase = in.nextInt();
		solver.solve(TaskCase);
		cout.flush();
	}
	private static class Task{
		long value[];
		int n,m;
		TreeMap<Integer,Long> mp = new TreeMap<>();
		public void solve(int T){
			while(T-->0){
				n = in.nextInt();
				m = in.nextInt();
				value = new long[n];
				for(int i = 0; i < n; i++) value[i] = in.nextLong();
				if(n==1){
					in.nextInt();
					in.nextInt();
					cout.print(value[0]);
					cout.write('\n');
					continue;
				}
				ArrayList<Integer>[] G = Utils.ListArray(n);
				for(int i = 0; i < m; i++){
					int u = in.nextInt() - 1, v = in.nextInt() - 1;
					G[v].add(u);
				}
				mp.clear();
				for(int i = 0; i < n; i++){
					if(G[i].isEmpty()) continue;
					G[i].sort((x,y)->{ return x-y; });
					int hx = G[i].hashCode();
					if(!mp.containsKey(hx)) mp.put(hx,value[i]);
					else mp.put(hx,mp.get(hx)+value[i]);
				}
				Long ans = 0l;
				for(long v : mp.values()) ans = gcd(ans,v);
				cout.write(ans.toString()+'\n');
			}
		}
		private long gcd(long A, long B){
			return B!=0 ? gcd(B,A%B) : A;
		}
	}
	private static class Utils{
		public static <T> ArrayList<T>[] ListArray(int _size){
			ArrayList<T>[] ret = new ArrayList[_size];
			for(int i = 0; i < _size; i++) ret[i] = new ArrayList<>();
			return ret;
		}
	}
	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		public FastScanner(InputStream in) {
				br = new BufferedReader(new InputStreamReader(in));
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public boolean hasMoreTokens() {
			while (st == null || !st.hasMoreElements()) {
				String line = null;
				try {
					line = br.readLine();
				} catch (IOException e) {
					return false;
				}
				if (line == null) {
					return false;
				}
				st = new StringTokenizer(line);
			}
			return true;
		}
		public String next() {
			while (st == null || !st.hasMoreElements()) {
				String line = null;
				try {
					line = br.readLine();
				} catch (IOException e) {
				}
				st = new StringTokenizer(line);
			}
			return st.nextToken();
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public int[] nextIntArray(int n) {
			int[] ret = new int[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextInt();
			}
			return ret;
		}
		public long[] nextLongArray(int n) {
			long[] ret = new long[n];
			for (int i = 0; i < n; i++) {
				ret[i] = nextLong();
			}
			return ret;
		}
	}
}