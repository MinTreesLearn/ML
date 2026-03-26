import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();
        int test = sc.nextInt();
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        char[] arr = sc.next().toCharArray();
        int[] res = new int[n];
        int num = n;
        int last = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || arr[i] == '>') {
                for (int j = i; j >= last; j--) {
                    res[j] = num;
                    num--;
                }
                last = i + 1;
            }
        }
        display(res, n);
        num = 1;
        last = 0;
        for (int i = 0; i < n; i++) {
            if (i == n - 1 || arr[i] == '<') {
                for (int j = i; j >= last; j--) {
                    res[j] = num;
                    num++;
                }
                last = i + 1;
            }
        }
        display(res, n);
    }

    private static void display(int[] res, int n) {
        for (int i = 0; i < n; i++) {
            out.print(res[i] + " ");
        }
        out.println();
    }

    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
}