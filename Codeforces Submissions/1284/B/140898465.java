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
        List<Integer> maximums = new ArrayList<>();
        List<Integer> minimums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            boolean alreadyHasAscent = false;
            int totalElements = sc.nextInt();
            int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
            for (int j = 0; j < totalElements; j++) {
                int value = sc.nextInt();
                if (value > min) {
                    alreadyHasAscent = true;
                }
                min = Math.min(min, value);
                max = Math.max(max, value);
            }
            if (alreadyHasAscent) {
                min = Integer.MIN_VALUE;
                max = Integer.MAX_VALUE;
            }
            minimums.add(min);
            maximums.add(max);
        }
        Collections.sort(minimums);
        Collections.sort(maximums);
        //out.println(maximums);
        long totalPairs = 0;
        for (int i = 0; i < minimums.size(); i++) {
            totalPairs += binarySearch(maximums, minimums.get(i));
        }
        out.println(totalPairs);
    }

    private static long binarySearch(List<Integer> maximums, int minValue) {
        int n = maximums.size();
        int lo = 0, hi = n - 1;
        int res = n;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            if (maximums.get(mid) > minValue) {
                //out.println("ok");
                res = Math.min(res, mid);
                hi = mid - 1;
            }else {
                lo = mid + 1;
            }
        }
        return n - res;
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