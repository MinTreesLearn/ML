import java.io.*;
import java.util.*;

public class TeamBuilding {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out, false);
        int N = in.nextInt(), P = in.nextInt(), K = in.nextInt();
        int[][] A = new int[N][2];
        for (int i = 0; i < N; i++) {
            A[i] = new int[]{in.nextInt(), i};
        }
        int[][] S = new int[N][P];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < P; j++) {
                S[i][j] = in.nextInt();
            }
        }
        Arrays.sort(A, (a, b) -> b[0] - a[0]);
        long[][] dp = new long[N + 1][(1 << P)];
        dp[0][0] = 0;
        for (int i = 1; i <= N; i++) {
            int idx = A[i - 1][1];
            for (int mask = 0; mask < (1 << P); mask++) {
                int count = i - 1 - Integer.bitCount(mask);
                if (count >= 0 && count < K) dp[i][mask] = dp[i - 1][mask] + A[i - 1][0];
                else dp[i][mask] = dp[i - 1][mask];
                for (int j = 0; j < P; j++) {
                    if ((mask & (1 << j)) != 0) {
                        dp[i][mask] = Math.max(dp[i][mask], dp[i - 1][mask ^ (1 << j)] + S[idx][j]);
                    }
                }
            }
        }
        out.println(dp[N][(1 << P) - 1]);
        out.close();
        System.exit(0);
    }
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public double nextDouble() {
            return Double.parseDouble(next());
        }
        public String nextLine() {
            String str = "";
            try {
                str = reader.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}