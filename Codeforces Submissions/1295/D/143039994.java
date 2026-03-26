import java.io.*;
import java.util.*;
 
public class Contest1295D
{
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        String next() { // reads in the next string
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() { // reads in the next int
            return Integer.parseInt(next());
        }
        public long nextLong() { // reads in the next long
            return Long.parseLong(next());
        }
        public double nextDouble() { // reads in the next double
            return Double.parseDouble(next());
            }
        }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    static long mod = 1000000007;
    public static void main(String[] args)
    {
    	int t = r.nextInt();
    	while (t > 0)
    	{
    		t--;
    		long a = r.nextLong();
    		long m = r.nextLong();
    		long g = gcd(a,m);
    		m/=g;
    		long ans = 1;
    		for (long i = 2; i * i <= m; i ++)
    		{
    			if (m%i == 0)
    			{
    				ans *= (i-1);
    				m/=i;
    				while (m%i==0)
    				{
    					m/=i;
    					ans*=i;
    				}
    			}
    		}
    		if (m > 1)
    		{
    			ans *= (m-1);
    		}
    		pw.println(ans);
    	}
        pw.close();
    }
    static long gcd(long a, long b) { return b==0 ? a : gcd(b, a%b); }
}