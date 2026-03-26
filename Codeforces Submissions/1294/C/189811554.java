
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class ProductOfThreeNumbersAgain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		FastScanner fs = new FastScanner();
		PrintWriter pw = new PrintWriter(System.out);
		int T = fs.nextInt();
		while (T-- > 0)
		{
			int N = fs.nextInt();
			int a = -1;
			for (int i = 2; i * i <= N; i++)
			{
				/*
				 * pw.println("i * i <= N " + (a*a <= N)); pw.println("i--> " + a);
				 * pw.println("N%a == 0 " + (N%a == 0));
				 */
				if (N%i == 0)
				{
					a = i;
					N /= a;
					break;
				}
			}
//			pw.println("a--> "+ a + " N---> "+N);
			if (a == -1)
			{
				pw.println("NO");
				continue;
			}
			
			int b = -1;
			for (int i = a + 1; i * i <= N; i++)
			{
				if (N%i == 0)
				{
					b = i;
					N /= i;
					break;
				}
				
			}
//			pw.println("b--> "+ b + " N---> "+N);
			int c = N;
//			pw.println("c--> "+c);
			if (b == -1 || c <= b)
			{
				pw.println("NO");
			}
			else
			{
				pw.println("YES");
				pw.println(a + " " + b + " " + c);
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
