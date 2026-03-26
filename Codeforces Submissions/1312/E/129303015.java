/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."

*/

import java.util.*;
import java.lang.*;
import java.io.*;

public class Codechef {
    static int MAX = 505;
    static int[][] dp = new int[MAX][MAX];
    static int[][] dp2 = new int[MAX][MAX];
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
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < MAX; i++) {
            Arrays.fill(dp[i], -1);
            Arrays.fill(dp2[i], -1);
        }

        int res = arrayShrinking(arr, 0, n - 1);
        out.println(res);
    }

    private static int arrayShrinking(int[] arr, int i, int j) {
        // dp[i][j] stores the min array length that can be formed from elements in range i to j.

        // dp2[i][j] stores the value we get after merging elements in range i to j using several operations (if possible), otherwise -1;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // if only one element in range, it means we can't perform any operation
        if (i == j) {

            // no merging of elements possible, so value left will be same as arr[i].
            dp2[i][j] = arr[i];

            // so min array length that can be formed is 1.
            return dp[i][j] = 1;
        }

        int minLength = Integer.MAX_VALUE;

        for (int k = i; k < j; k++) {

            // we try to split the range from i to k and from k + 1 to j
            int left = arrayShrinking(arr, i, k);
            int right = arrayShrinking(arr, k + 1, j);

            minLength = Math.min(minLength, left + right);

            // left and right equals to 1 means we can further merge these into one value if they have same dp2 values.
            if (left == 1 && right == 1) {
                if (dp2[i][k] != -1 && dp2[i][k] == dp2[k + 1][j]) {

                    dp2[i][j] = dp2[i][k] + 1;
                    return dp[i][j] = 1;

                }
            }
        }
        
        return dp[i][j] = minLength;
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