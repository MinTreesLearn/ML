import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

/**
 * #
 *
 * @author pttrung
 */
public class F_Round_547_Div3 {
    public static long MOD = 998244353;
    static int[] dp;


    public static void main(String[] args) throws FileNotFoundException {
        // PrintWriter out = new PrintWriter(new FileOutputStream(new File(
        // "output.txt")));
        PrintWriter out = new PrintWriter(System.out);
        Scanner in = new Scanner();
        int n = in.nextInt();
        int[] data = new int[n];
        int[] sum = new int[n];

        for (int i = 0; i < n; i++) {
            data[i] = in.nextInt();
            sum[i] = data[i] + (i > 0 ? sum[i - 1] : 0);
        }
        int result = 0;
        int val = 0;
        int[] pre = new int[n];
        HashSet<Integer> set = new HashSet<>();
        dp = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int v = sum[j] - (i > 0 ? sum[i - 1] : 0);
                if (set.contains(v)) {
                    continue;
                }
                set.add(v);
                Arrays.fill(dp, -1);
                int tmp = cal(0, v, sum);
                if (result < tmp) {
                    val = v;
                    result = tmp;
                    pre = Arrays.copyOf(dp, n);
                }

            }
        }
        //System.out.println(result);

        out.println(result);
        int index = 0;
        int cur = result;
        while (index < n && cur > 0) {
            // System.out.println(index + " " + cur + " " + Arrays.toString(pre));
            if (index + 1 < n && pre[index + 1] == cur) {
                index++;
                continue;
            }
            for (int i = index; i < n; i++) {
                int tmp = sum[i] - (index > 0 ? sum[index - 1] : 0);

                if (tmp == val) {
                    out.println((index + 1) + " " + (i + 1));
                    index = i + 1;
                    cur--;
                    break;
                }
            }

        }


        out.close();
    }

    static int cal(int index, int need, int[] sum) {
        if (index == sum.length) {
            return 0;
        }
        if (dp[index] != -1) {
            return dp[index];
        }
        int result = cal(index + 1, need, sum);
        for (int i = index; i < sum.length; i++) {
            int v = sum[i] - (index > 0 ? sum[index - 1] : 0);
            if (v == need) {
                result = Integer.max(result, 1 + cal(i + 1, need, sum));
                break;
            }
        }
        return dp[index] = result;
    }

    static class P {
        int pos, index, open;

        P(int pos, int index, int open) {
            this.pos = pos;
            this.index = index;
            this.open = open;
        }
    }


    public static int[] KMP(String val) {
        int i = 0;
        int j = -1;
        int[] result = new int[val.length() + 1];
        result[0] = -1;
        while (i < val.length()) {
            while (j >= 0 && val.charAt(j) != val.charAt(i)) {
                j = result[j];
            }
            j++;
            i++;
            result[i] = j;
        }
        return result;

    }

    public static boolean nextPer(int[] data) {
        int i = data.length - 1;
        while (i > 0 && data[i] < data[i - 1]) {
            i--;
        }
        if (i == 0) {
            return false;
        }
        int j = data.length - 1;
        while (data[j] < data[i - 1]) {
            j--;
        }
        int temp = data[i - 1];
        data[i - 1] = data[j];
        data[j] = temp;
        Arrays.sort(data, i, data.length);
        return true;
    }

    public static int digit(long n) {
        int result = 0;
        while (n > 0) {
            n /= 10;
            result++;
        }
        return result;
    }

    public static double dist(long a, long b, long x, long y) {
        double val = (b - a) * (b - a) + (x - y) * (x - y);
        val = Math.sqrt(val);
        double other = x * x + a * a;
        other = Math.sqrt(other);
        return val + other;

    }

    public static class Point implements Comparable<Point> {

        int x;
        long y;

        public Point(int start, long end) {
            this.x = start;
            this.y = end;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return x == point.x &&
                    y == point.y;
        }

        @Override
        public int hashCode() {
            return Objects.hash(x, y);
        }

        @Override
        public int compareTo(Point o) {
            return Integer.compare(x, o.x);
        }
    }

    public static class FT {

        long[] data;

        FT(int n) {
            data = new long[n];
        }

        public void update(int index, long value) {
            while (index < data.length) {
                data[index] += value;
                index += (index & (-index));
            }
        }

        public long get(int index) {
            long result = 0;
            while (index > 0) {
                result += data[index];
                index -= (index & (-index));
            }
            return result;

        }
    }

    public static long gcd(long a, long b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    public static long pow(long a, long b) {
        if (b == 0) {
            return 1;
        }
        if (b == 1) {
            return a;
        }

        long val = pow(a, b / 2);
        if (b % 2 == 0) {
            return (val * val) % MOD;
        } else {
            return (val * ((val * a) % MOD)) % MOD;

        }
    }

    static class Scanner {

        BufferedReader br;
        StringTokenizer st;

        public Scanner() throws FileNotFoundException {
            // System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
            br = new BufferedReader(new InputStreamReader(System.in));
            //br = new BufferedReader(new InputStreamReader(new FileInputStream(new File("input.txt"))));
        }

        public String next() {

            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    throw new RuntimeException();
                }
            }
            return st.nextToken();
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public String nextLine() {
            st = null;
            try {
                return br.readLine();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }

        public boolean endLine() {
            try {
                String next = br.readLine();
                while (next != null && next.trim().isEmpty()) {
                    next = br.readLine();
                }
                if (next == null) {
                    return true;
                }
                st = new StringTokenizer(next);
                return st.hasMoreTokens();
            } catch (Exception e) {
                throw new RuntimeException();
            }
        }
    }
}