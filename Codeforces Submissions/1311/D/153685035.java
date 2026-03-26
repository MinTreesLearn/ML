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

    static int MAX = 20000, INF = (int) 1e9;
    static List<int[]> list = new ArrayList<>();

    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();

        precompute();

        int test = sc.nextInt();
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void precompute() {
        for (int i = 1; i <= MAX; i++) {
            for (int j = i; j <= MAX; j += i) {
                for (int k = j; k <= MAX; k += j) {
                    list.add(new int[]{i, j, k});
                }
            }
        }
    }

    private static void solve() {
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();

        int[] res = new int[]{0, 0, 0};
        int minOperations = INF;
        for (int i = 0; i < list.size(); i++) {
            int[] curr = list.get(i);
            int operations = Math.abs(curr[0] - a) + Math.abs(curr[1] - b) + Math.abs(curr[2] - c);
            if (minOperations > operations) {
                minOperations = operations;
                res = curr;
            }
        }

        out.println(minOperations);
        out.println(res[0] + " " + res[1] + " " + res[2]);
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