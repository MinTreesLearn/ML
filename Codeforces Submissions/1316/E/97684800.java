import java.util.*;
import java.io.*;

public class E20 {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt(); int p = sc.nextInt(); int k = sc.nextInt();
        long [][] dp = new long[n + 1][1 << p];
        Person [] people = new Person[n];
        for (int i = 0; i < n; i++) people[i] = new Person(sc.nextInt());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p; j++) {
                people[i].s[j] = sc.nextLong();
            }
        }
        Arrays.sort(people, Comparator.comparingLong(x -> -x.a));
        for (long [] arr : dp) Arrays.fill(arr, Long.MIN_VALUE / 2);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0][0] = people[0].a;
                for (int j = 0; j < p; j++) {
                    dp[0][1 << j] = people[0].s[j];
                }
                continue;
            }
            for (int j = 0; j < (1 << p); j++) {
                for (int bit = 0; bit < p; bit++) {
                    if (((j >> bit) & 1) == 0) continue;
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j ^ (1 << bit)] + people[i].s[bit]);
                }
                int before = i - Integer.bitCount(j);
                if (before < k) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j] + people[i].a);
                } else dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
            }
        }
        out.println(dp[n - 1][(1 << p) - 1]);
        out.close();
    }

    static class Person {
        long a;
        long [] s;
        Person(long a) {
            this.a = a;
            s = new long[10];
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

        String nextLine() {
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