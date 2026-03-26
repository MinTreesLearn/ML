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

        int test = sc.nextInt();
        for (int t = 0; t < test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int busTicket = sc.nextInt();
        int tramTicket = sc.nextInt();
        int roublesLeft = sc.nextInt();

        char[] crossroad = sc.next().toCharArray();
        int n = crossroad.length;

        // min walk index, after which we can reach home using public transports and paying roubles we have
        int minWalkIndex = getMinWalk(crossroad, n, busTicket, tramTicket, roublesLeft);

        out.println(minWalkIndex + 1);
    }

    private static int getMinWalk(char[] crossroad, int n, int busTicket, int tramTicket, int roublesLeft) {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (canReachHome(crossroad, n, busTicket, tramTicket, roublesLeft, mid)) {
                hi = mid;
            }else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    private static boolean canReachHome(char[] crossroad, int n, int busTicket, int tramTicket, int roublesLeft, int index) {
        long costToReachHome = 0;
        boolean atBusStation = (crossroad[index] == 'A');
        index++;
        while (index < n) {
            if (crossroad[index] == 'A') { // at bus station
                if (!atBusStation) {
                    // from tram to bus station
                    costToReachHome += tramTicket;
                    atBusStation = true;
                }
            }else {
                // at tram station
                if (atBusStation) {
                    // from bus to tram station
                    costToReachHome += busTicket;
                    atBusStation = false;
                }
            }
            index++;
        }
        index--;
        costToReachHome += (crossroad[index] == crossroad[index - 1]) ? (crossroad[index] == 'A' ? busTicket : tramTicket) : 0;
        return costToReachHome <= roublesLeft;
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