import java.io.*;
import java.util.*;

public class Main {
    private static final InputReader in = new InputReader(System.in);
    private static final PrintWriter pw = new PrintWriter(System.out);

    public static void main(String[] args) {
        int n = in.nextInt();
        Integer[] d = new Integer[n];
        for (int i = 0; i < n; i++) {
            d[i] = in.nextInt();
        }
        for (int i = 0; i < n; i++) {
            d[i] -= in.nextInt();
        }

        Arrays.sort(d);

        long ans = 0;
        for (int i = 0; i < n - 1; i++) {
            int l = i + 1, r = n - 1, x = n;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (d[mid] > -d[i]) {
                    r = mid - 1;
                    x = mid;
                }
                else l = mid + 1;
            }
            ans += n - x;
        }
        pw.println(ans);
        pw.close();
    }

    private static class Pair {
        private int first, second;

        public Pair(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }

    private static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public boolean ready() throws IOException {
            return reader.ready();
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

        public String nextLine() {
            String str = null;
            try {
                str = reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            return str;
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public Double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}