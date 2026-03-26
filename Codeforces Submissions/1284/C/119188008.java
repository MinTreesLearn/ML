import java.io.*;
import java.util.*;

public class tank {

    static final FastScanner fs = new FastScanner();

    //static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while(t-->0) {
            run_case();
        }

        //out.close();
    }

    static void run_case() {
        int n = fs.nextInt(), mod = fs.nextInt(), sum = 0, tmp;

        int[] fact = new int[n + 1];

        fact[0] = fact[1] = 1;

        for (int i = 2; i <= n; i++) {
            fact[i] = (int) ((i * (long) fact[i - 1]) % mod);
        }

        for (int i = 1; i <= n; i++) {
            tmp = (int) ((fact[i] * (long) fact[n - i]) % mod);
            tmp = (int) ((tmp * (long)(n - i + 1)) % mod);
            tmp = (int) ((tmp * (long)(n - i + 1)) % mod);
            sum = (sum + tmp) % mod;
        }

        System.out.println(sum);
    }

    static class FastScanner {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st=new StringTokenizer("");
        String next() {
            while (!st.hasMoreTokens())
                try {
                    st=new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            return st.nextToken();
        }

        String nextLine(){
            try {
                return br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return "";
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            int[] a=new int[n];
            for (int i=0; i<n; i++) a[i]=nextInt();
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}