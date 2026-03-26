import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class NewYearAndNaming {
	
	static class FastReader {
		
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
        
        double nextFloat() { return Float.parseFloat(next()); }
 
        double nextDouble() { return Double.parseDouble(next()); }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        
        int[] nextArray(int n)
        {
        	int[] a = new int[n];
        	for (int i=0; i<n; i++) {
        		a[i] = this.nextInt();
        	}
        	return a;
        }
        
        long[] nextArrayLong(int n)
        {
        	long[] a = new long[n];
        	for (int i=0; i<n; i++) {
        		a[i] = this.nextLong();
        	}
        	return a;
        }
        
    }
	
	public static void solve(int n, int m, String[] s, String[] t, int q, int[] y) {
		
		StringBuilder ans = new StringBuilder();
		for (int year : y) {
			ans.append(s[(year-1)%n]);
			ans.append(t[(year-1)%m] + "\n");
		}
		System.out.print(ans);
		
	}

	public static void main(String[] args) {
		
		FastReader in = new FastReader();
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		for (int i=0; i<n; i++) {
			s[i] = in.next();
		}
		String[] t = new String[m];
		for (int i=0; i<m; i++) {
			t[i] = in.next();
		}
		int q = in.nextInt();
		int[] y = in.nextArray(q);
		solve(n, m, s, t, q, y);

	}

}
