/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

                        Just have Patience + 1...

*/








import java.util.*;
import java.lang.*;
import java.io.*;


public class Solution {

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = 1;
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        int[] differences = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            differences[i] = sc.nextInt();
        }

        long[] permutation = new long[n];
        for (int i = 1; i < n; i++) {
            permutation[i] = permutation[i - 1] + differences[i - 1];
        }

        long minVal = 0;
        for (int i = 0; i < n; i++) {
            if (permutation[i] < minVal) {
                minVal = permutation[i];
            }
        }

        HashSet<Long> set = new HashSet<>();

        long add = 1 - minVal;
        for (int i = 0; i < n; i++) {
            permutation[i] += add;
            if (permutation[i] < 1 || permutation[i] > n) {
                out.println(-1);
                return;
            }
            set.add(permutation[i]);
        }

        if (set.size() != n) {
            out.println(-1);
            return;
        }

        for (int i = 0; i < n; i++) {
            out.print(permutation[i] + " ");
        }
        out.println();
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
                catch (IOException  lastMonthOfVacation)
                {
                    lastMonthOfVacation.printStackTrace();
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
            catch (IOException lastMonthOfVacation)
            {
                lastMonthOfVacation.printStackTrace();
            }
            return str;
        }
    }

}