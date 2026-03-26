import java.io.*;
import java.util.*;
 
public class Main {
    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;
        public InputReader(InputStream stream)
        {
            reader = new BufferedReader(new InputStreamReader(stream),32768);
            tokenizer = null;
        }
        String next()
        {
            while (tokenizer == null||!tokenizer.hasMoreTokens())
            {
                try
                {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt()
        {
            return Integer.parseInt(next());
        }
		public long nextLong()
        {
            return Long.parseLong(next());
        }
    }
    static InputReader r = new InputReader(System.in);
    static PrintWriter pw = new PrintWriter(System.out);
    public static void main(String[] args)
    {
		long H = r.nextLong();
		int n = r.nextInt();
		long[] d = new long[n];
		long[] ps = new long[n+1];
		for (int i = 0; i < n; i ++)
		{
			d[i] = r.nextInt();
			ps[i+1] = ps[i] + d[i];
		}
		long min = Integer.MAX_VALUE;
		for (int i = 0; i < n + 1; i ++)
		{
			min = Math.min(min,ps[i]);
		}
		if (ps[n] >= 0 && H + min > 0)
		{
			pw.println(-1);
		}
		else if (H + min <= 0)
		{
			int hi = 0;
			for (int i = n; i >= 0; i --)
			{
				if (H+ps[i] <= 0)
				{
					hi = i;
				}
			}
			pw.println(hi);
		}
		else
		{
			long x = ps[n];
			//y rounds --> H+min-x*y <= 0
			long y = ((H+min+(-x-1))/(-x));
			H = H + x*y;
			int hi = 0;
			for (int i = n; i>=0; i --)
			{
				if (H+ps[i]<= 0)
				{
					hi = i;
				}
			}
			pw.println(n*y+hi);
		}
		pw.close();
	}
}