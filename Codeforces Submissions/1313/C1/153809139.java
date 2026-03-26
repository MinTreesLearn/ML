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
        int[] maxHeight = new int[n];
        for (int i = 0; i < n; i++) {
            maxHeight[i] = sc.nextInt();
        }

        int[] res = new int[n];
        int[] currHeight = new int[n];

        long maxSkyscraper = 0;
        for (int i = 0; i < n; i++) { // for each peak
            long skyscrapers = maxHeight[i];
            currHeight[i] = maxHeight[i];
            int atMost = maxHeight[i];

            for (int j = i - 1; j >= 0; j--) {
                atMost = Math.min(atMost, maxHeight[j]);
                currHeight[j] = atMost;
                skyscrapers += atMost;
            }

            int atLeast = maxHeight[i];
            for (int j = i + 1; j < n; j++) {
                atLeast = Math.min(atLeast, maxHeight[j]);
                currHeight[j] = atLeast;
                skyscrapers += atLeast;
            }

            if (skyscrapers > maxSkyscraper) {
                for (int j = 0; j < n; j++) {
                    res[j] = currHeight[j];
                }
                maxSkyscraper = skyscrapers;
            }
        }

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