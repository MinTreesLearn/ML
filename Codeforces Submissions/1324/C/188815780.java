import java.io.*;
import java.sql.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        var fastScanner = new FastScanner();
        int n = fastScanner.nextInt();
        for (int i=0; i<n; i++) {
            var s = fastScanner.nextLine();
            s = "R"+s+"R";
            int index = 0;
            int mx = 0;
            for (int j=0;j<s.length(); j++) {
                if(s.charAt(j)=='R') {
                    mx = Math.max(mx, j-index);
                    index = j;
                }
            }
            System.out.println(mx);
        }
    }

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner() {
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