import java.util.*;
import java.io.*;

public class D616 {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        String s = sc.next(); int q = sc.nextInt();
        int n = s.length();
        int [][] ct = new int[n + 1][26];
        for (int i = 1; i <= n; i++) {
            int idx = s.charAt(i - 1) - 'a';
            for (int j = 0; j < 26; j++) {
                if (j == idx) ct[i][j] = ct[i - 1][j] + 1;
                else ct[i][j] = ct[i - 1][j];
            }
        }
        for (int i = 0; i < q; i++) {
            int l = sc.nextInt();
            int r = sc.nextInt();
            if (l == r || s.charAt(l - 1) != s.charAt(r - 1)) {
                out.println("Yes");
                continue;
            }
            ArrayList<Integer> count = new ArrayList<>();
            int sum = 0;
            for (int j = 0; j < 26; j++) {
                count.add(ct[r][j] - ct[l - 1][j]);
                sum += count.get(count.size() - 1);
            }
            int amt = 0;
            for (int j = 0; j < 26; j++) if (count.get(j) > 0) amt++;
            if (amt <= 2) {
                out.println("No");
            } else {
                out.println("Yes");
            }
        }
        out.close();
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