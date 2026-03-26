import java.util.*;
import java.io.*;
public class E617
{
    public static void main(String [] args)
    {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        String s = sc.next(); int [] a = new int [n];
        for (int i = 0; i < n; i++) {
            a[i] = (int) s.charAt(i) - 96;
        }
        TreeSet<Pair> map = new TreeSet<>(); int [] ret = new int [n]; int cur = 1;
        for (int i = 0; i < n; i++) {
            Pair key = map.floor(new Pair(a[i], 1000000));
            if (key == null) {
                map.add(new Pair(a[i], cur));
                ret[i] = cur;
                cur++;
            } else {
                int idx = key.second;
                ret[i] = idx;
                map.remove(key);
                map.add(new Pair(a[i], idx));
            }
        }
        int ans = 0;
        for (Pair i: map) {
            ans = Math.max(ans, i.second);
        }
        out.println(ans);
        for (int i = 0; i < n; i++) out.print(ret[i] + " ");
        out.close();
    }
    static class Pair implements Comparable<Pair> {
        int first; int second;
        Pair(int first, int second) {
            this.first = first; this.second = second;
        }

        @Override
        public int compareTo(Pair o) {
            if (first == o.first) return second - o.second;
            return first - o.first;
        }
    }









    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }



    }

}