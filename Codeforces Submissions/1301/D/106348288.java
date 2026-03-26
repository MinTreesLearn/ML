import java.util.*;
import java.lang.*;
import java.io.*;

public class Codechef {
    static class Pair{
        int n;
        String direction;
        Pair(int n, String direction) {
            this.n = n;
            this.direction = direction;
        }
    }
    public static void main(String[] args) throws java.lang.Exception {
        out = new PrintWriter(new BufferedOutputStream(System.out));
        sc = new FastReader();
        int test = 1;
        for (int t = 0; t < test; t++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int k = sc.nextInt();
            int total_distance = 0;
            List<Pair> list = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                list.add(new Pair(m - 1, "R"));
                total_distance += m - 1;
                if (i == 1) {
                    list.add(new Pair(m - 1, "L"));
                    total_distance += m - 1;
                }else {
                    list.add(new Pair(m - 1, "UDL"));
                    total_distance += 3 * (m - 1);
                }
                if (i == n) {
                    list.add(new Pair(n - 1, "U"));
                    total_distance += n - 1;
                }else {
                    list.add(new Pair(1, "D"));
                    total_distance += 1;
                }
            }
            if (total_distance < k ) {
                out.println("NO");
                continue;
            }
            String temp = "";
            int curr = 0;
            while (total_distance > k) {
                temp = list.get(list.size() - 1).direction;
                curr = list.get(list.size() - 1).n * temp.length();
                list.remove(list.get(list.size() - 1));
                total_distance -= curr;
                if (total_distance > k) {
                    continue;
                }
                curr = k - total_distance;
                if (curr / temp.length() > 0) {
                    list.add(new Pair(curr / temp.length(), temp));
                }
                if (curr % temp.length() > 0){
                    temp = temp.substring(0, curr % temp.length());
                    list.add(new Pair(1, temp));
                }
                total_distance = k;
            }
            out.println("YES");
            int count = 0;
            for (Pair p : list) {
                if (p.n == 0) count++;
            }
            out.println(list.size() - count);
            for(Pair p : list) {
                if (p.n == 0) {
                    continue;
                }
                out.println(p.n + " " + p.direction);
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