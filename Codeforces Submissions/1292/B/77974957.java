import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.FilterInputStream;
import java.io.BufferedInputStream;
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
        BAromasSearch solver = new BAromasSearch();
        solver.solve(1, in, out);
        out.close();
    }

    static class BAromasSearch {
        ArrayList<long[]> data;
        long cx;
        long cy;
        long ax;
        long bx;
        long ay;
        long by;
        long[][] dis;

        boolean canAdd() {
            double x = ((double) cx * ax) + bx;
            double y = ((double) cy * ay) + by;
            return (x <= 2e17) && (y <= 2e17);
        }

        long[] newData() {
            long x = (cx * ax) + bx;
            long y = (cy * ay) + by;
            cx = x;
            cy = y;
            return new long[]{x, y};
        }

        public void solve(int testNumber, ScanReader in, PrintWriter out) {
            data = new ArrayList<>();
            long x0 = in.scanLong();
            long y0 = in.scanLong();
            ax = in.scanLong();
            ay = in.scanLong();


            bx = in.scanLong();
            by = in.scanLong();

            cx = x0;
            cy = y0;

            data.add(new long[]{x0, y0});
            while (canAdd()) data.add(newData());


            long sx = in.scanLong();
            long sy = in.scanLong();


            long t = in.scanLong();
            dis = new long[data.size()][data.size()];

            for (int i = 0; i < data.size(); i++) {
                for (int j = i + 1; j < data.size(); j++) {
                    dis[i][j] = dis[j][i] = makeEdge(i, j);
                }
            }

            long ans = Long.MIN_VALUE;


            for (int i = 0; i < data.size(); i++) {
                long tt = t - dist(sx, sy, data.get(i)[0], data.get(i)[1]);
                ans = Math.max(ans, findIt(i, tt));
            }

            out.println(ans);


        }

        long dist(long x, long y, long xx, long yy) {
            return (long) Math.abs(x - xx) + Math.abs(y - yy);
        }

        long findIt(int node, long t) {
            if (t < 0) return 0;
            int n = data.size();
            long ans = 1;
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    if (dis[l][r] + Math.min(dis[node][l], dis[node][r]) <= t) ans = Math.max(ans, r - l + 1);
                }
            }
            return ans;
        }

        long makeEdge(int i, int j) {
            long xx = Math.abs(data.get(i)[0] - data.get(j)[0]);
            long yy = Math.abs(data.get(i)[1] - data.get(j)[1]);
            return xx + yy;
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

