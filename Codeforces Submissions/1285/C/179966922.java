import java.io.*;
import java.util.*;
public class Main {
    public static long m;
    static int mod = 998244353;
    static int inf = (int) 1e9 + 7;
    static int st[][];
    static int sum_of_d[] = new int[1000001];

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        //int t = sc.nextInt();
        int t = 1;
        Gr1zler:
        for (int WTF = 0; WTF < t; WTF++) {
            long n = sc.nextLong();
            long qw=Long.MAX_VALUE;
            for(long i=1;i*i<=n;i++){
                if(n%i==0){
                    if(lcm(i,n/i)==n){
                        qw=Math.min(qw,Math.max(i,n/i));
                    }
                }
            }
            System.out.println(qw+" "+n/qw);

        }
    }
    static long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }
    static long lcm(long a, long b) {
        return a * b / gcd(a, b);
    }

    static void sort(int[] a) {
        int n = a.length;
        Integer[] b = new Integer[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    }

    static void sort(long[] a) {
        int n = a.length;
        Long[] b = new Long[n];
        for (int i = 0; i < n; i++)
            b[i] = a[i];
        Arrays.sort(b);
        for (int i = 0; i < n; i++)
            a[i] = b[i];
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream system) {
            br = new BufferedReader(new InputStreamReader(system));
        }

        public Scanner(String file) throws Exception {
            br = new BufferedReader(new FileReader(file));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public char nextChar() throws IOException {
            return next().charAt(0);
        }

        public Long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public int[] nextArrInt(int n) throws IOException {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        public long[] nextArrLong(int n) throws IOException {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }

    }
}
