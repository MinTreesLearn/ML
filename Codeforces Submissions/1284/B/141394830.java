import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class NewYearAndAscentSequence {
	
	static class FastReader {
		
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
        	
            br = new BufferedReader(
                new InputStreamReader(System.in));
            
        }
 
        String next() {
        	
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
 
        int nextInt() {
        	
        	return Integer.parseInt(next());
        	
        }
 
        long nextLong() {
        	
        	return Long.parseLong(next());
        	
        }
        
        double nextFloat() {
        	
        	return Float.parseFloat(next());
        
        }
 
        double nextDouble() {
        	
        	return Double.parseDouble(next());
        	
        }
 
        String nextLine() {
        	
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
            
        }
        
        int[] nextArray(int n) {
        	
        	int[] a = new int[n];
        	for (int i=0; i<n; i++) {
        		a[i] = this.nextInt();
        	}
        	return a;
        	
        }
        
        long[] nextArrayLong(int n) {
        	
        	long[] a = new long[n];
        	for (int i=0; i<n; i++) {
        		a[i] = this.nextLong();
        	}
        	return a;
        	
        }
        
    }
	
	public static void solve(int n, int[][] s) {
		
		long aCount = 0;
		boolean[] isAscent = new boolean[n];
		long buf[] = new long[1000007];
		for (int i=0; i<n; i++) {
			for (int j=1; j<s[i].length; j++) {
				if (s[i][j] > s[i][j-1]) {
					isAscent[i] = true;
					aCount++;
					break;
				}
			}
		}
		for (int i=0; i<n; i++) {
			if (!isAscent[i]) {
				buf[s[i][0]]++;
			}
		}
		for (int i=buf.length-2; i>=0; i--) {
			buf[i] += buf[i+1];
		}
		long ans = aCount * n;
		for (int i=0; i<n; i++) {
			if (!isAscent[i]) {
				ans += (aCount + buf[s[i][s[i].length-1]+1]);
			}
		}
		System.out.println(ans);
		
	}

	public static void main(String[] args) {
		
		FastReader in = new FastReader();
		int n = in.nextInt();
		int[][] s = new int[n][];
		for (int i=0; i<n; i++) {
			int l = in.nextInt();
			s[i] = in.nextArray(l);
		}
		solve(n, s);

	}

}
