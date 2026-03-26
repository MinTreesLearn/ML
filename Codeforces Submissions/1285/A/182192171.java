import java.io.*;
import java.util.*;


public class A {
    static class Program {
        int val;
        int index;
        Program(int i, int val) {
            this.index = i;
            this.val = val;
        }
    }

    public static void main(String[] args) {
        FastScanner sc = new FastScanner();
        int t = 1;
        while (t-- > 0) {
            int n = sc.nextInt();
           String s = sc.next();
           int r = 0, l = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s.charAt(i) == 'R')
                    r++;
                else
                    l++;
            }
            System.out.println(r + l + 1);
        }

        // min
        // mid

        // max

        // max + min
        // max + mid
        // min + max + mid

    }
    /*
     * 5 4
     * 9 4
     * 9 13
     * 22 13
     * 22 35
     * 57 35
     * 57 92
     * +100
     */
    static boolean IsPowerOfTwo(int x) {
        return (x & (x - 1)) == 0;
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
    }
}
