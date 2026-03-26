import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
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
        BIrreducibleAnagrams solver = new BIrreducibleAnagrams();
        solver.solve(1, in, out);
        out.close();
    }

    static class BIrreducibleAnagrams {
        public void solve(int testNumber, ScanReader in, PrintWriter out) {

            char arr[] = in.scanString().toCharArray();
            int[] pre[] = new int[26][arr.length + 1];

            for (int i = 0; i < 26; i++) {
                for (int j = 1; j <= arr.length; j++) {
                    pre[i][j] = pre[i][j - 1] + ((arr[j - 1] - 'a') == i ? 1 : 0);
                }
            }

            int q = in.scanInt();
            while (q-- > 0) {
                int l = in.scanInt();
                int r = in.scanInt();
                int count = 0;
                for (int i = 0; i < 26; i++) count += (pre[i][r] - pre[i][l - 1] > 0) ? 1 : 0;
                if (l == r || arr[l - 1] != arr[r - 1] || count >= 3) {
                    out.println("Yes");
                } else {
                    out.println("No");
                }
            }

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

        public String scanString() {
            int c = scan();
            while (isWhiteSpace(c)) c = scan();
            StringBuilder RESULT = new StringBuilder();
            do {
                RESULT.appendCodePoint(c);
                c = scan();
            } while (!isWhiteSpace(c));
            return RESULT.toString();
        }

        private boolean isWhiteSpace(int n) {
            if (n == ' ' || n == '\n' || n == '\r' || n == '\t' || n == -1) return true;
            else return false;
        }

    }
}

