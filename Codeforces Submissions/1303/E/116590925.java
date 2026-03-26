import java.io.*;
import java.util.*;

public class Main {
    private static FastScanner fs;

    public static void main(String[] args) throws IOException {
        fs = new FastScanner();
        int nTest = 1;
        nTest = fs.nextInt();
        for (int testcase = 1; testcase <= nTest; ++testcase) {
            solve();
        }
    }

    static void solve() throws IOException {
        String s = fs.nextLine();
        String t = fs.nextLine();
        int n = s.length();
        int m = t.length();
        int[][] nxt = getNxt(s, n);
        for (int i = 0; i < m; ++i) {
            if (ok(s, t.substring(0, i + 1), t.substring(i + 1), nxt)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }

    static int[][] getNxt(String s, int n) {
        int[][] nxt = new int[n][26];
        for (int ch = 0; ch < 26; ++ch) {
            for (int i = n - 1; i >= 0; --i) {
                if (s.charAt(i) - 'a' == ch) {
                    nxt[i][ch] = 1;
                } else {
                    if (i < n - 1 && nxt[i + 1][ch] != -1) {
                        nxt[i][ch] = 1 + nxt[i + 1][ch];
                    } else {
                        nxt[i][ch] = -1;
                    }
                }
            }
        }
        return nxt;
    }

    static boolean ok (String s, String t1, String t2, int[][] nxt) {
        int[][] dp = new int[t1.length() + 1][t2.length() + 1];
        int n = s.length();
        for (int i = 0; i <= t1.length(); ++i) {
            for (int j = 0; j <= t2.length(); ++j) {
                dp[i][j] = n + 1;
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= t1.length(); ++i) {
            if (dp[i - 1][0] < n && nxt[dp[i - 1][0]][t1.charAt(i - 1) - 'a'] != -1) {
                dp[i][0] = dp[i - 1][0] + nxt[dp[i - 1][0]][t1.charAt(i - 1) - 'a'];
            } else {
                break;
            }
        }
        for (int i = 1; i <= t2.length(); ++i) {
            if (dp[0][i - 1] < n && nxt[dp[0][i - 1]][t2.charAt(i - 1) - 'a'] != -1) {
                dp[0][i] = dp[0][i - 1] + nxt[dp[0][i - 1]][t2.charAt(i - 1) - 'a'];
            } else {
                break;
            }
        }
        for (int i = 1; i <= t1.length(); ++i) {
            for (int j = 1; j <= t2.length(); ++j) {
                if (dp[i - 1][j] < n && nxt[dp[i - 1][j]][t1.charAt(i - 1) - 'a'] != -1) {
                    dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + nxt[dp[i - 1][j]][t1.charAt(i - 1) - 'a']);
                }
                if (dp[i][j - 1] < n && nxt[dp[i][j - 1]][t2.charAt(j - 1) - 'a'] != -1) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + nxt[dp[i][j - 1]][t2.charAt(j - 1) - 'a']);
                }
            }
        }
        return dp[t1.length()][t2.length()] <= n;
    }

    static void sort(int[] a) {
        ArrayList<Integer> arr = new ArrayList<>();
        for (int val : a) {
            arr.add(val);
        }
        Collections.sort(arr);
        for (int i = 0; i < a.length; ++i) {
            a[i] = arr.get(i);
        }
    }

    static class FastScanner {
        private static BufferedReader br;
        private static StringTokenizer st;

        FastScanner() throws IOException {
            if (System.getProperty("ONLINE_JUDGE") == null) {
                br = new BufferedReader(new FileReader("input.txt"));
                PrintStream o = new PrintStream("output.txt");
                System.setOut(o);
            } else {
                br = new BufferedReader(new InputStreamReader(System.in));
            }
            st = new StringTokenizer("");
        }

        String nextLine() throws IOException {
            return br.readLine();
        }

        String next() throws IOException {
            while (!st.hasMoreTokens()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }
    }
}