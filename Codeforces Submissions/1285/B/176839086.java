

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class JustEatIt {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner fs = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		int T = fs.nextInt();
		while (T-- > 0)
		{
			int N = fs.nextInt();
			long[] arr = fs.readArray(N);
			long Yasser = Kadane(arr,0, N - 1);
			long Abdel = Math.max(Kadane(arr,0, N - 2), Kadane(arr,1, N - 1));
			if (Yasser > Abdel)
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
	
	
	private static long Kadane(long[] arr, int start, int end)
	{
		long sum = 0;
		long max = Long.MIN_VALUE;
		for (int i = start; i <= end; i++)
		{
			sum += arr[i];
			max = Math.max(max, sum);
		    if (sum < 0)
		    {
		    	sum = 0;
		    }
		}
		
		return max;
		
	}
	

	private static class FastScanner {
		 
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
