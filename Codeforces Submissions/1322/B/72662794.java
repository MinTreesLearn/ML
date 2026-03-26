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
		int TaskCase = 1;
		while(TaskCase--!=0) solver.solve();
		cout.flush();
	}
	private static class Task{
		int n;
		Integer A[],C[];
		public void solve(){
			n = in.nextInt();
			A = new Integer[n];
			C = new Integer[n];
			for(int i = 0; i < n; i++) A[i] = in.nextInt();
			int ans = 0;
			if((n&1)==0) for(int i = 0; i < n; i++) if((A[i]&1)==1) ans^=1;
			for(int bit = 1; bit < 25; bit++){
				if((n&1)==0) for(int i = 0; i < n; i++) if(((A[i])&(1<<bit))!=0) ans ^= (1<<bit);
				for(int i = 0; i < n; i++) C[i] = A[i] & ((1<<bit)-1);
				Arrays.sort(C);
				int ptr = n;
				for(int i = 0; i < n; i++){
					if(ptr<=i) ptr = i + 1;
					while(ptr-1>i&&C[ptr-1]+C[i]>=(1<<bit)) ptr--;
					if(((n-ptr)&1)==1) ans ^= (1<<bit);
				}
			}
			cout.println(ans);
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