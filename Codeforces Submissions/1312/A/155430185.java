import java.io.*;
import java.lang.reflect.Array;
import java.util.*;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {

    public static void main(String[] args) {
        in = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        try {
            int t = in.nextInt(); while(t-- > 0) { solve(); out.println();}
//          solve();
        } finally {
            out.close();
        }
        return;
    }

    public static void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        if(n == m) {
            out.print("YES");
            return;
        }

        if(m < 3) {
            out.print("NO");
            return;
        }

        if(n % m == 0) {
            out.print("YES");
        } else {
            out.print("NO");
        }
        return;
    }

    static void print(char[][] a) {
        for(int i =  0; i < a.length; i++) {
            for(int j = 0; j < a.length; j++) {
                out.print(a[i][j]);
            }
            out.println();
        }
    }


//-------------- Helper methods-------------------
    public static int[] fillArray(int n) {
        int[] array = new int[n];
        for(int i = 0; i < n; i++) {
            array[i] = in.nextInt();
        }
        return array;
    }

    public static char[] fillArray() {
        char[] array = in.next().toCharArray();
        return array;
    }

    //-----------PrintWriter for faster output---------------------------------

    public static PrintWriter out;
    public static MyScanner in;

    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
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

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
    //--------------------------------------------------------
}