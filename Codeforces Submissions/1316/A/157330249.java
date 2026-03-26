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
//            solve();
        } finally {
            out.close();
        }
        return;
    }

    public static void solve() {
        int n = in.nextInt();
        int m = in.nextInt();
        int[] a = fillArray(n);
        int sum = Arrays.stream(a).sum();

        out.print(Math.min(m, sum));
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

    //-----------MyScanner class for faster input----------x§x
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

    static void shuffleArray(int[] arr){
        int n = arr.length;
        Random rnd = new Random();
        for(int i=0; i<n; ++i){
            int tmp = arr[i];
            int randomPos = i + rnd.nextInt(n-i);
            arr[i] = arr[randomPos];
            arr[randomPos] = tmp;
        }
    }
    //--------------------------------------------------------
}

