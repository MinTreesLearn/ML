

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class ArraySharpening {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner fs = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		int T = fs.nextInt();
		while (T-- > 0)
		{
			int N = fs.nextInt();
			long[] arr = fs.readArray(N);
			
			//Kahan tak you can achieve strictly inc from left to right
			int prefix_last = -1;
			
			for (int i = 0; i < N; i++)
			{
				if (arr[i] < i)
				{
					break;
				}
				prefix_last = i;
			}
			
			//Kahan tak tu strictly decreasing kar sakta hai--> check from left
/*
   			  \/			
         ⇗    /\	 ⇖		
		⇗ 	 /  \      ⇖
			/    \
*/			
			int suffix_last = N-1;
			for (int i = N-1; i >= 0; i--)
			{
				if (arr[i] < N - i - 1)
				{
					break;
				}
				suffix_last = i;
			}
			
			//Are these two pointers intersecting?
			
			if (suffix_last <= prefix_last)
			{
				pw.println("YES");
			}
			else
			{
				pw.println("NO");
			}
			
		}
		pw.close();

	}

	static class FastScanner {
		 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");
 
        public String next() {
            while (!st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        long[] readArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = nextLong();
            }
            return a;
        }
 
        int nextInt() {
            return Integer.parseInt(next());
        }
 
        long nextLong() {
            return Long.parseLong(next());
        }
 
        double nextDouble() {
            return Double.parseDouble(next());
        }
}
}
