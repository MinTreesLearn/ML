/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

*/


import java.util.*;
import java.lang.*;
import java.io.*;

public class CodeChef {
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        char[] arr = sc.next().toCharArray();

        int opens = 0;
        for (char c : arr) {
            if (c == '(') {
                opens++;
            }else {
                opens--;
            }
        }
        if (opens != 0) {
            out.println(-1);
            return;
        }
        long nanoseconds = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == '(') {
                opens++;
            }else {
                opens--;
            }
            if (opens < 0 && index == -1) {
                index = i;
            }
            if (opens == 0) {
                if (index != -1) {
                    nanoseconds += i - index + 1;
                    index = -1;
                }
            }
        }

        out.println(nanoseconds);
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