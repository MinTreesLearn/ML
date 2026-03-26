import java.io.*;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
            Solution.solve(in, out);
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        public long[] readArray(int n)
        {
            long[] arr=new long[n];
            for(int i=0;i<n;i++) arr[i]=nextLong();
            return arr;
        }
    }
}
class Solution
{
    public static void solve(Main.InputReader in, PrintWriter out)
    {
        int n=in.nextInt();
        long[] arr=in.readArray(n);
        long max=arr[0];
        HashMap<Long,Long> hmap=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            long diff=i-arr[i];
            if(hmap.containsKey(diff))
            {
                hmap.put(diff,hmap.get(diff)+arr[i]);
                max=Math.max(hmap.get(diff),max);
            }
            else
            {
                hmap.put(diff,arr[i]);
                max=Math.max(arr[i],max);
            }
        }
        out.println(max);
    }
}