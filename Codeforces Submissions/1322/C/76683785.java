import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Random;
import java.util.HashMap;
import java.io.InputStream;

/**
 * @author khokharnikunj8
 */

public class Main {
    public static void main(String[] args) {
        new Thread(null, new Runnable() {
            public void run() {
                new Main().solve();
            }
        }, "1", 1 << 26).start();
    }

    void solve() {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CInstantNoodles solver = new CInstantNoodles();
        int testCount = in.scanInt();
        for (int i = 1; i <= testCount; i++)
            solver.solve(i, in, out);
        out.close();
    }

    static class CInstantNoodles {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int n = in.scanInt();
            int m = in.scanInt();
            long[] values = new long[n];
            for (int i = 0; i < n; i++) values[i] = in.scanLong();
            int[][] edges = new int[m][2];
            long[] random1 = new long[n];
            long[] random2 = new long[n];
            {
                Random rd = new Random();
                for (int i = 0; i < n; i++) random1[i] = rd.nextLong();
            }
            for (int[] edge : edges) {
                edge[0] = in.scanInt();
                edge[1] = in.scanInt();
                random2[edge[1] - 1] ^= random1[(edge[0] - 1)];
            }
            Map<Long, Long> map = new HashMap<>();
            for (int i = 0; i < n; i++) {
                if (random2[i] == 0) continue;
                map.put(random2[i], map.getOrDefault(random2[i], 0l) + values[i]);
            }
            long ans = 0;
            for (Map.Entry<Long, Long> temp : map.entrySet()) {
                ans = CodeHash.gcd(ans, temp.getValue());
            }
            out.println(ans);

        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int index;
        private BufferedInputStream in;
        private int total;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (index >= total) {
                index = 0;
                try {
                    total = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (total <= 0) return -1;
            }
            return buf[index++];
        }

        public int scanInt() {
            int integer = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    integer *= 10;
                    integer += n - '0';
                    n = scan();
                }
            }
            return neg * integer;
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

        public long scanLong() {
            long integer = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    integer *= 10;
                    integer += n - '0';
                    n = scan();
                }
            }
            return neg * integer;
        }

    }

    static class CodeHash {
        public static long gcd(long a, long b) {
            while (b != 0) {
                long t = b;
                b = (a % b);
                a = t;
            }
            return a;
        }

    }
}

