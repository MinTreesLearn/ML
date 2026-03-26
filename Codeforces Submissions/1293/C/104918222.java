import java.lang.reflect.Array;
import java.net.Inet4Address;
import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.function.BinaryOperator;

public class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();
        int test = 1;
        for (int t = 0; t < test; t++) {
            int n = sc.nextInt();
            int q = sc.nextInt();
            int[][] lava = new int[2][n];
            int blockedPairs = 0;
            while (q-- > 0) {
                int x = sc.nextInt() - 1;
                int y = sc.nextInt() - 1;
                int changedState = (lava[x][y] == 0) ? 1 : -1;
                lava[x][y] = 1 - lava[x][y]; // change state.

                // check for its neighbours.
                for (int dy = -1; dy <= 1; dy++) {
                    if (y + dy < 0 || y + dy >= n) {
                        continue;
                    }
                    if (lava[1 - x][y + dy] == 1) {
                        blockedPairs += changedState;
                    }
                }

                if (blockedPairs == 0) {
                    out.println("YES");
                }else {
                    out.println("NO");
                }
            }
        }
        out.close();
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