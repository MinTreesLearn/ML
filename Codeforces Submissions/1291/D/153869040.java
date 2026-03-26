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

    static int MAX = 200005;
    static int[][] fenwickTree = new int[MAX][26];

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
        char[] arr = sc.next().toCharArray();
        int n = arr.length;

        for (int i = 1; i <= n; i++) {
            update(i, arr[i - 1] - 'a');
        }

        int queries = sc.nextInt();
        for (int q = 0; q < queries; q++) {
            int l = sc.nextInt();
            int r = sc.nextInt();

            if (r == l) {
                out.println("YES");
                continue;
            }

            int distinct = 0;
            for (int i = 0; i < 26; i++) {
                //out.println(query(r, i) + " " + query(l - 1, i));
                distinct += (query(r, i) - query(l - 1, i)) > 0 ? 1 : 0;
            }

            out.println((distinct > 2 || arr[l - 1] != arr[r - 1]) ? "YES" : "NO");
        }
    }

    private static void update(int index, int charIndex) {
        for (int i = index; i < MAX; i += i & -i) {
            fenwickTree[i][charIndex]++;
        }
    }

    private static int query(int index, int charIndex) {
        int count = 0;
        for (int i = index; i > 0; i -= i & -i) {
            count += fenwickTree[i][charIndex];
        }
        return count;
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