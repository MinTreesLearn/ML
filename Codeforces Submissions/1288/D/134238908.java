/*
        "Everything in the universe is balanced. Every disappointment
                you face in life will be balanced by something good for you!
                        Keep going, never give up."


*/


import java.util.*;
import java.lang.*;
import java.io.*;

public class Solution {
    static int MAX = 1000000000;
    static int n, m, allSet = 1;
    static int[][] arr;
    static List<int[]> valid = new ArrayList<>();
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
        n = sc.nextInt();
        m = sc.nextInt();
        arr = new int[n + 1][m];
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                arr[i][j] = sc.nextInt();
            }
        }

        for (int i = 2; i <= m; i++) {
            allSet = (allSet << 1) | 1;
        }

        for (int i = 0; i <= allSet; i++) {
            for (int j = i; j <= allSet; j++) {
                if ((i | j) == allSet) {
                    valid.add(new int[]{i, j});
                }
            }
        }

        int lo = 0, hi = MAX;
        int[] res;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            res = check(mid);
            if (res[0] == -1) {
                hi = mid - 1;
            }else {
                lo = mid;
            }
        }
        res = check((lo + hi + 1) / 2);
        out.println(res[0] + " " + res[1]);
    }

    private static int[] check(int mid) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int state = 0;
            for (int j = 0; j < m; j++) {
                int isGood = arr[i][j] >= mid ? 1 : 0;
                state = (state << 1) | isGood;
            }
            map.put(state, i);
        }

        for (int[] pairs : valid) {
            int first = map.getOrDefault(pairs[0], 0);
            int second = map.getOrDefault(pairs[1], 0);
            if (first > 0 && second > 0) {
                return new int[]{first, second};
            }
        }

        return new int[]{-1, -1};
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