import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
import java.util.Random;
import java.util.HashMap;
import java.util.Collections;
import java.util.ArrayList;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        ScanReader in = new ScanReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        CInstantNoodles solver = new CInstantNoodles();
        solver.solve(1, in, out);
        out.close();
    }

    static class CInstantNoodles {
        long[] random;

        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            int t = in.scanInt();


            random = new long[500005];

            for (int i = 0; i < random.length; i++) random[i] = new Random().nextInt(1000000000) + 234792734l;


            while (t-- > 0) {
                int n = in.scanInt();
                int m = in.scanInt();
                long cost[] = new long[n + 1];
                for (int i = 1; i <= n; i++) cost[i] = in.scanLong();


                ArrayList<Integer> arrayList[] = new ArrayList[n + 1];
                for (int i = 1; i <= n; i++) arrayList[i] = new ArrayList<>();


                HashMap<Long, Long> hashMap = new HashMap<>();


                for (int i = 0; i < m; i++) {
                    int a = in.scanInt();
                    int b = in.scanInt();
                    arrayList[b].add(a);
                }

                for (int i = 1; i <= n; i++) {
                    if (arrayList[i].size() == 0) continue;
                    Collections.sort(arrayList[i]);
                    long hash = findHash(arrayList[i]);
                    hashMap.put(hash, cost[i] + hashMap.getOrDefault(hash, 0l));
                }

                long gcd = 0;
                for (long kkk : hashMap.values()) {
                    gcd = CodeX.GCD(gcd, kkk);
                }

                out.println(gcd);

            }


        }

        long findHash(ArrayList<Integer> arrayList) {
            int p = 0;
            long res = 0;
            for (int k : arrayList) {
                res = (res + ((k * random[p++]) % 792950153)) % 792950153;
            }
            return res;
        }

    }

    static class CodeX {
        public static long GCD(long A, long B) {
            if (B == 0)
                return A;
            else
                return GCD(B, A % B);
        }

    }

    static class ScanReader {
        private byte[] buf = new byte[4 * 1024];
        private int INDEX;
        private BufferedInputStream in;
        private int TOTAL;

        public ScanReader(InputStream inputStream) {
            in = new BufferedInputStream(inputStream);
        }

        private int scan() {
            if (INDEX >= TOTAL) {
                INDEX = 0;
                try {
                    TOTAL = in.read(buf);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                if (TOTAL <= 0) return -1;
            }
            return buf[INDEX++];
        }

        public int scanInt() {
            int I = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    I *= 10;
                    I += n - '0';
                    n = scan();
                }
            }
            return neg * I;
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

        public long scanLong() {
            long I = 0;
            int n = scan();
            while (isWhiteSpace(n)) n = scan();
            int neg = 1;
            if (n == '-') {
                neg = -1;
                n = scan();
            }
            while (!isWhiteSpace(n)) {
                if (n >= '0' && n <= '9') {
                    I *= 10;
                    I += n - '0';
                    n = scan();
                }
            }
            return neg * I;
        }

    }
}

