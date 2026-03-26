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
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        char[] s = sc.next().toCharArray();
        int[] maxColorNeeded = new int[26];
        int[] dp = new int[n];
        Arrays.fill(dp, 1); // at least one color needed to color
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'a';
            for (int j = 25; j > index; j--) { // swap is required for these chars, since we want to sort
                dp[i] = Math.max(dp[i], maxColorNeeded[j] + 1);
            }
            maxColorNeeded[index] = Math.max(maxColorNeeded[index], dp[i]);
        }
        int maxColorRequired = 0;
        for (int colorsNeeded : maxColorNeeded) {
            maxColorRequired = Math.max(maxColorRequired, colorsNeeded);
        }
        out.println(maxColorRequired);
        for (int i = 0; i < n; i++) {
            out.print(dp[i] + " ");
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
