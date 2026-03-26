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

        int[] prevSmallerHeight = getPreviousSmallerHeights(maxHeight, n);
        int[] nextSmallerHeight = getNextSmallerHeights(maxHeight, n);

        long[] prefixSkyscrapers = getPrefixSkyscraper(prevSmallerHeight, maxHeight, n);
        long[] suffixSkyscrapers = getSuffixSkyscraper(nextSmallerHeight, maxHeight, n);

        long maxSkyscraperFloors = getTotalFloorsWithFixedPeak(prefixSkyscrapers, suffixSkyscrapers, maxHeight, 0);
        int maxSkyscrapersIndex = 0;

        for (int i = 1; i < n; i++) {
            long totalFloors = getTotalFloorsWithFixedPeak(prefixSkyscrapers, suffixSkyscrapers, maxHeight, i);
            if (totalFloors > maxSkyscraperFloors) {
                maxSkyscraperFloors = totalFloors;
                maxSkyscrapersIndex = i;
            }
        }

        long[] perfectHeights = new long[n];
        perfectHeights[maxSkyscrapersIndex] = maxHeight[maxSkyscrapersIndex];

        long atMost = maxHeight[maxSkyscrapersIndex];
        for (int i = maxSkyscrapersIndex - 1; i >= 0; i--) {
            atMost = Math.min(atMost, maxHeight[i]);
            perfectHeights[i] = atMost;
        }

        atMost = maxHeight[maxSkyscrapersIndex];
        for (int i = maxSkyscrapersIndex + 1; i < n; i++) {
            atMost = Math.min(atMost, maxHeight[i]);
            perfectHeights[i] = atMost;
        }

        for (int i = 0; i < n; i++) {
            out.print(perfectHeights[i] + " ");
        }
        out.println();
    }

    private static long getTotalFloorsWithFixedPeak(long[] prefixSkyscrapers, long[] suffixSkyscrapers, int[] maxHeight, int index) {
        return prefixSkyscrapers[index] + suffixSkyscrapers[index] - maxHeight[index];
    }

    private static int[] getPreviousSmallerHeights(int[] maxHeight, int n) {
        int[] prevSmallerHeight = new int[n];
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && maxHeight[stack.peek()] >= maxHeight[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                prevSmallerHeight[i] = stack.peek();
            }else {
                prevSmallerHeight[i] = -1;
            }
            stack.add(i);
        }
        return prevSmallerHeight;
    }

    private static int[] getNextSmallerHeights(int[] maxHeight, int n) {
        int[] nextSmallerHeight = new int[n];
        Stack<Integer> stack = new Stack<>();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && maxHeight[stack.peek()] >= maxHeight[i]) {
                stack.pop();
            }
            if (!stack.isEmpty()) {
                nextSmallerHeight[i] = stack.peek();
            }else {
                nextSmallerHeight[i] = -1;
            }
            stack.add(i);
        }
        return nextSmallerHeight;
    }

    private static long[] getPrefixSkyscraper(int[] prevSmallerHeight, int[] maxHeight, int n) {
        long[] prefixSkyscrapers = new long[n];
        for (int i = 0; i < n; i++) {
            if (prevSmallerHeight[i] == -1) {
                prefixSkyscrapers[i] = (long) (i + 1) * maxHeight[i];
            }else {
                prefixSkyscrapers[i] = (long) (i - prevSmallerHeight[i]) * maxHeight[i] + prefixSkyscrapers[prevSmallerHeight[i]];
            }
        }
        return prefixSkyscrapers;
    }

    private static long[] getSuffixSkyscraper(int[] nextSmallerHeight, int[] maxHeight, int n) {
        long[] suffixSkyscrapers = new long[n];
        for (int i = n - 1; i >= 0; i--) {
            if (nextSmallerHeight[i] == -1) {
                suffixSkyscrapers[i] = (long) (n - i) * maxHeight[i];
            }else {
                suffixSkyscrapers[i] = (long) (nextSmallerHeight[i] - i) * maxHeight[i] + suffixSkyscrapers[nextSmallerHeight[i]];
            }
        }
        return suffixSkyscrapers;
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