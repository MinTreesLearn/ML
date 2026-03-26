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

        int test = sc.nextInt();
        for (int t = 1; t <= test; t++) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        List<Integer> list = new ArrayList<>();
        for (int i = 0; i < 3; i++) {
            int freq = sc.nextInt();
            list.add(freq);
        }
        Collections.sort(list, Collections.reverseOrder());
        int count = 0;
        for (int i = 0; i < 3; i++) {
            if (list.get(i) == 0) {
                break;
            }
            list.set(i, list.get(i) - 1);
            count++;
        }
        for (int i = 1; i < 3; i++) {
            if (list.get(0) > 0 && list.get(i) > 0) {
                list.set(0, list.get(0) - 1);
                list.set(i, list.get(i) - 1);
                count++;
            }
        }
        if (list.get(1) > 0 && list.get(2) > 0) {
            list.set(1, list.get(1) - 1);
            list.set(2, list.get(2) - 1);
            count++;
        }
        int min = 1;
        for (int i = 0; i < 3; i++) {
            min = Math.min(min, list.get(i));
        }
        if (min > 0) {
            count++;
        }
        out.println(count);
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