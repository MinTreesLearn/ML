import java.util.*;
import java.io.*;

public class Main {
    static FastReader sc;
    static PrintWriter out;

    static void solve() {
        int n = sc.nextInt(), k = 0;
        int[] arr = sc.readIntArray(2*n);
        Arrays.sort(arr);
        //debug(mini);
        out.println((arr[n] - arr[n - 1]));
            /*
4
33 44 11 22
             */

    }

    static int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }


    public static void main(String[] args) throws IOException {
        sc = new FastReader();
        out = new PrintWriter(System.out);
        int tt = sc.nextInt();
        for (int t = 1; t <= tt; t++) {
            // out.printf("Case %d: ", t);
            solve();
        }
        out.close();
    }

    static int[] strToIntArray(String s){
        String[] sarr = s.split(" ");
        int[] arr = new int[sarr.length];
        for(int i = 0; i < sarr.length; i++){
            arr[i] = Integer.parseInt(sarr[i]);
        }
        return arr;
    }

    static <E> void debug(E a) {
        System.err.println(a);
    }

    static void debug(int... a) {
        System.err.println(Arrays.toString(a));
    }

    static <E> void print(E res) {
        out.println(res);
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
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

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

        int[] readIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++)
                res[i] = nextInt();
            return res;
        }

        long[] readLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++)
                res[i] = nextLong();
            return res;
        }
    }

}