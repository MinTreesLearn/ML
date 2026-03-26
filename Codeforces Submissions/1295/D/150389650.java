import java.io.*;
import java.util.StringTokenizer;

public class SameGCDs {
    public static long gcd(long A, long B) {
        while (B != 0) {
            long C = A;
            A = B;
            B = C % B;
        }
        return A;
    }
    public static long phi(long N) {
        long result = N;
        for (long i = 2; i * i <= N; i++) {
            if (N % i == 0) {
                while (N % i == 0) N /= i;
                result -= result / i;
            }
        }
        if (N != 1) result -= result / N;
        return result;
    }
    public static void main(String[] args) {
        InputReader reader = new InputReader(System.in);
        PrintWriter writer = new PrintWriter(System.out, false);
        int T = reader.nextInt();
        for (int t = 0; t < T; t++) {
            long A = reader.nextLong();
            long M = reader.nextLong();
            writer.println(phi(M / gcd(A, M)));
        }
        writer.close();
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