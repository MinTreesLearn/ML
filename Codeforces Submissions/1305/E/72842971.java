import java.io.*;
import java.util.StringTokenizer;

public class ScoreDistribution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    static StringTokenizer st;

    static int readInt() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        int n = readInt();
        int m = readInt();

        //       n: 1, 2, 3, 4, 5, 6, 7,  8,  9, 10, 11, 12
        // (n-1)/2: 0, 0, 1, 1, 2, 2, 3,  3,  4,  4,  5,  5
        //     n/2: 0, 1, 1, 2, 2, 3, 3,  4,  4,  5,  5,  6
        //     max: 0, 0, 1, 2, 4, 6, 9, 12, 16, 20, 25, 30
        int max = ((n - 1) / 2) * (n / 2);
        if (m > max) {
            System.out.println(-1);
            return;
        }

        if (m == 0 ) {
            for (int i = n * n,
                 limit = n * (n + n - 1);
                 i <= limit; i += n) {
                pw.print(i + " ");
            }
            pw.close();
            return;
        }

        // as long as it is no less than 2 * n;
        final int LARGE_INTEGER = 2 * n;

        int a = (int) Math.sqrt(m - 1);
        if (m <= a * (a + 1)) {
            for (int i = 1; i <= 2 * a + 1; i++) {
                pw.print(i + " ");
            }

            int delta = a * (a + 1) - m;
            pw.print((2 * a + 2 + 2 * delta) + " ");

            for (int i = LARGE_INTEGER * LARGE_INTEGER,
                 limit = LARGE_INTEGER * (LARGE_INTEGER + n - 2 * a - 3);
                 i <= limit; i += LARGE_INTEGER) {
                pw.print(i + " ");
            }
        } else {
            for (int i = 1; i <= 2 * a + 2; i++) {
                pw.print(i + " ");
            }

            int delta = (a + 1) * (a + 1) - m;
            pw.print((2 * a + 3 + 2 * delta) + " ");

            for (int i = LARGE_INTEGER * LARGE_INTEGER,
                 limit = LARGE_INTEGER * (LARGE_INTEGER + n - 2 * a - 4);
                 i <= limit; i += LARGE_INTEGER) {
                pw.print(i + " ");
            }
        }

        pw.close();
    }
}
