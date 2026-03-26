/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."


*/


import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
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
        Set<Long> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            long val = sc.nextLong();
            set.add(val);
        }
        out.println(drEvilUnderscores(set, 30));
    }

    private static long drEvilUnderscores(Set<Long> set, int bitPosition) {
        if (bitPosition < 0) {
            return 0;
        }

        Set<Long> set0 = new HashSet<>();
        Set<Long> set1 = new HashSet<>();
        long currMask = (1 << bitPosition);

        for (long val : set) {
            if ((currMask & val) == 0) {
                set0.add(val);
            }else {
                set1.add(val);
            }
        }

        if (set0.size() == 0) {
            return drEvilUnderscores(set1, bitPosition - 1);
        }

        if (set1.size() == 0) {
            return drEvilUnderscores(set0, bitPosition - 1);
        }

        return (1 << bitPosition) + Math.min(drEvilUnderscores(set0, bitPosition - 1), drEvilUnderscores(set1, bitPosition - 1));
    }


    public static FastReader sc;
    public static PrintWriter out;
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer str;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (str == null || !str.hasMoreElements())
            {
                try
                {
                    str = new StringTokenizer(br.readLine());
                }
                catch (IOException  end)
                {
                    end.printStackTrace();
                }
            }
            return str.nextToken();
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
            catch (IOException end)
            {
                end.printStackTrace();
            }
            return str;
        }
    }
}