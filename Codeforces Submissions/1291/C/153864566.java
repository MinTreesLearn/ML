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

    static int MAX = 3505;
    static int[][] dp = new int[MAX][MAX];
    static int[] arr = new int[MAX];
    static int n, m, k;

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        int test = sc.nextInt();
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        n = sc.nextInt();
        m = sc.nextInt();
        k = sc.nextInt();

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        m--;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = 0;
            }
        }

        out.println(shareArray(0, n - 1));
    }

    private static int shareArray(int start, int end) {
        int remaining = end - start + 1;
        int alreadyTaken = n - remaining;

        if (alreadyTaken == m) {
            // now it's my turn, and I will choose max
            return Math.max(arr[start], arr[end]);
        }

        if (dp[start][end] != 0) {
            return dp[start][end];
        }

        int chooseStart = shareArray(start + 1, end);
        int chooseEnd = shareArray(start, end - 1);

        if (k >= alreadyTaken + 1) {
            // can persuade and get max
            dp[start][end] = Math.max(chooseStart, chooseEnd);
        }else {
            // can't persuade anymore, so friend would choose max
            dp[start][end] = Math.min(chooseStart, chooseEnd);
        }

        return dp[start][end];
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